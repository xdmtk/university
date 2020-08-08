<?php
session_start();

const main_site = '
    <html>



        <!-- Basic document head -->
        <head>
            <title>Lab 2</title>
            <link rel="stylesheet" href="lab2.css">
            <script src="lab2.js"></script>
        </head>
        
        <body>
           <div id="login-modal">
                <div id="form-box">
                    <div id="form-box-content">
                        <span id="form-box-title">Lab 2 Login</span>
                        <input type="text" id="username" placeholder="Username" autocomplete="off">
                        <span id="username-span"></span>
                        <input type="password" id="password" placeholder="Password" autocomplete="off">
                        <span id="password-span"></span>
                        <span id="general-error-span">Hi</span>
                        <input type="button" value="Login" id="submit"></button>
                        <span id="login-register-switch">Don\'t have an account? Click Here</span>
                    </div>
                </div>
           </div>
        </body>

    </html>
    ';

    class DB {

        /* Typically these would be in an .env file */
        const DB_HOST = 'localhost';
        const DB_PORT = '3306';
        const DB_USER = 'admin';
        const DB_PASS = 'php484';
        const DB_NAME = 'lab2';

        public $conn;

        /**
         * DB constructor. Opens a connection to the Database.
         */
        public function __construct() {
            $this->conn = new mysqli(self::DB_HOST,
                            self::DB_USER,
                             self::DB_PASS,
                             self::DB_NAME);

            if ($this->conn->connect_error) {
                die("Couldn't connect to DB");
            }
        }

        /**
         * Closes the active connection to the Database if it exists.
         */
        public function __destruct() {
            if ($this->conn) {
                $this->conn->close();
            }
        }

        /**
         * Looks for a matching row with the given username/password combo. Returns a truthy/false
         * integer representing whether the user was found or not.
         *
         * @param $username
         * @param $password
         * @return int
         */
        public function verify_user($username, $password) {
            $sql = "SELECT * FROM user WHERE username = '${username}'";

            if ($res = $this->conn->query($sql)) {
                $row = $res->fetch_array();
                if ($row) {
                    $password_ret = $row['password'];
                    return password_verify($password, $password_ret);
                }
            }
            return false;
        }

        /**
         * Inserts new username/password combo into Database if username doesn't already
         * exist.
         * @param $username
         * @param $password
         * @return bool - Success/failure registering user
         */
        public function register_user($username, $password) {
            $sql = "SELECT * FROM user WHERE username = '${username}';";
            if ($res = $this->conn->query($sql)) {
                $row = $res->fetch_array();
                if ($row) {
                    return false;
                }
            }

            $sql = "INSERT INTO user (username, password) VALUES ('${username}', '${password}');";
            $this->conn->query($sql);

            if ($this->conn->error) {
                return false;
            }
            return true;
        }

        public function get_user_table() {
            $sql = "SELECT * FROM user ORDER BY username ASC";
            $rows = [];
            if ($res = $this->conn->query($sql)) {
                while ($row = $res->fetch_array(MYSQLI_ASSOC)) {
                    array_push($rows, $row);
                }
                return $rows;
            }
            return false;
        }

        public static function debug($msg) {
            date_default_timezone_set("America/Los_Angeles");
            $log_file = '/home/xdmtk/phplog.log';
            $mode = (file_exists($log_file) ? "a" : "w");

            $log_handle = fopen($log_file, $mode);
            flock($log_handle, LOCK_EX);
            fwrite($log_handle, "[" . date("Y-m-d H:i:s") . "] - " . $msg . "\n");
            flock($log_handle, LOCK_UN);
            fclose($log_handle);
        }
    }

    class HTMLGenerator {

        public static function generate_user_table($row_data) {
            $content = '<table><tr><th>User ID</th><th>Username</th><th>Password</th></tr>';
            $row_num = 0;
            foreach ($row_data as $row) {
                $content .= '<tr>';
                $content .= '<td ' . ($row_num % 2 ? ' id="mod-two"' : '') . '>' . $row['userid'] . '</td>';
                $content .= '<td' . ($row_num % 2 ? ' id="mod-two"' : '') . '>' . $row['username'] . '</td>';
                $content .= '<td' . ($row_num % 2 ? ' id="mod-two"' : '') . '>' . $row['password'] . '</td>';
                $content .= '</tr>';
                $row_num++;
            }
            $content .= '</table>';

            return $content;
        }

        public static function generate_color_button() {
           return '<a href="#" id="color-changer"><span id="color-changer-span">Click Me</span></a>';

        }


        public static function generate_logout_span() {
            return '<span id="log-out-span" style="text-decoration: underline; cursor: pointer; 
                        text-align: center; margin-top: 40px;" onclick="">Log out</span>';
        }
    }

    /**
     * Main function for all requests to the index page. Serves basic HTML
     * content when no 'api' post keyword is specified, otherwise performs
     * a specialized task returning JSON
     */
    function router() {

        /* Return the main site static HTML if not specifying
        an API call */
        if (!isset($_POST['api'])) {
            return main_site;
        }

        /* Otherwise, take a look at the api parameter to determine
        which route to call */
        switch ($_POST['api']) {

            /* Main routes */
            case 'login':
                return login();
            case 'register':
                return register();
            case 'logout':
                return logout();
            case 'get_content':
                return get_content();

            /* Invalid API specification results in a 400 with failure JSON */
            default:
                return api_response(400, 'No API call specified');
        }
    }


    /**
     * Helper function to organize and simplify JSON API responses
     * @param $code
     * @param $reason
     * @return false|string
     */
    function api_response($code, $reason) {
        http_response_code($code);
        return json_encode([
            'status' => ($code == 200 ? 'success' : 'failure'),
            'reason' => $reason
        ]);
    }

    /**
     * Called on the login API route. Checks for valid login params,
     * scans database for username/password pair, and starts a session
     * @return string
     */
    function login() {

        /* Make sure username and password are specified in the request */
        if (!(isset($_POST['username']) && isset($_POST['password']))) {
            return api_response(400, 'Client did not specify username and password');
        }

        /* Look for the user/pass combo in the database */
        $db = new DB();
        if (!$db->verify_user($_POST['username'], $_POST['password'])) {
            return api_response(401, 'Invalid username and/or password');
        }

        $_SESSION['username'] = $_POST['username'];
        return api_response(200, 'Successful login');
    }

    /**
     * Called on the register API route. Checks for valid registration params,
     * scans database for username/password pair to see if already exists, and if
     * not, adds user/pass combo into the table
     * @return string
     */
    function register() {
        if (session_status() == PHP_SESSION_ACTIVE && isset($_SESSION['username']))  {
            return api_response(400, 'Cant register new user while already logged in');
        }

        if (!(isset($_POST['username']) && isset($_POST['password']))) {
            return api_response(400, 'Client did not specify username and password');
        }

        $db = new DB();
        $res = $db->register_user($_POST['username'], password_hash($_POST['password'], PASSWORD_DEFAULT));

        return api_response($res ? 200 : 418, $res ? 'Successfully registered user' :
            'User already exists with this username');
    }

    /**
     * Called on the logout API route. Destroys the current session
     */
    function logout() {
        if (session_status() != PHP_SESSION_ACTIVE) {
            return api_response(400, 'Cant log out, no active session: ' . session_status());
        }

        session_unset();
        session_destroy();
        return api_response(200, 'Successfully logged out');
    }

    /**
     * Called after logging in, returns dynamic content based on the user
     * permissions (admin gets a database dump, regular user gets a color changer button
     */
    function get_content() {

        $content = '';
        if ($_SESSION['username'] == 'Administrator') {

            $DB = new DB();
            $content .= ($row_data = $DB->get_user_table()) ? HTMLGenerator::generate_user_table($row_data) :
                'Failed to get user table!';
        }
        else {
            $content .= HTMLGenerator::generate_color_button();
        }
        $content .= HTMLGenerator::generate_logout_span();

        return $content;
    }

echo router();
?>
