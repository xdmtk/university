<?php

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
            $sql = "SELECT * FROM user WHERE username = ${username} AND password = ${password};";

            return count($this->conn->query($sql)->fetch_array(MYSQLI_ASSOC));
        }

        /**
         * Inserts new username/password combo into Database if username doesn't already
         * exist.
         * @param $username
         * @param $password
         * @return bool - Success/failure registering user
         */
        public function register_user($username, $password) {
            $sql = "SELECT * FROM user WHERE username = ${username};";
            if (count($this->conn->query($sql)->fetch_array(MYSQLI_ASSOC))) {
                return false;
            }

            $sql = "INSERT INTO user (username, password) VALUES (${username}, ${password});";
            $this->conn->query($sql);

            if ($this->conn->error) {
                return false;
            }
            return true;
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

        if (!(isset($_POST['username']) && isset($_POST['password']))) {
            return api_response(400, 'Client did not specify username and password');
        }

        $db = new DB();
        if (!$db->verify_user($_POST['username'], password_hash($_POST['password'], PASSWORD_DEFAULT))) {
            return api_response(401, 'Invalid username and/or password');
        }

        session_start();
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
        if (session_status() == PHP_SESSION_ACTIVE) {
            return api_response(400, 'Cant register new user while already logged in');
        }

        if (!(isset($_POST['username']) && isset($_POST['password']))) {
            return api_response(400, 'Client did not specify username and password');
        }

        $db = new DB();
        $res = $db->register_user($_POST['username'], password_hash($_POST['password'], PASSWORD_DEFAULT));

        return api_response($res ? 200 : 418, $res ? 'Succesfully registered user' : 'I\'m a teapot');
    }

    /**
     * Called on the logout API route. Destroys the current session
     */
    function logout() {
        if (session_status() != PHP_SESSION_ACTIVE) {
            return api_response(400, 'Cant log out, no active session');
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
        return '<span id="log-out-span" style="text-decoration: underline; cursor: pointer; text-align: center" onclick="">Log out</span>';
    }

echo router();
?>
