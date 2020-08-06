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

    /**
     * Main function for all requests to the index page. Serves basic HTML
     * content when no 'api' post keyword is specified, otherwise performs
     * a specialized task returning JSON
     */
    function router() {

        /* Return the main site static HTML if not specifying
        an API call */
        if (!isset($_POST['api'])) {
            echo "no api";
            return main_site;
        }

        /* Otherwise, take a look at the api parameter to determine
        which route to call */
        switch ($_POST['api']) {

            /* Main routes */
            case 'login':
                return login();
            case 'logout':
                return logout();
            case 'get_content':
                return get_content();

            /* Invalid API specification results in a 400 with failure JSON */
            default:
                http_response_code(400);
                return json_encode([
                    'status' => 'failure',
                    'reason' => 'No API call specified'
                ]);
        }
    }

    /**
     * Called on the login API route. Checks for valid login params,
     * scans database for username/password pair, and starts a session
     * @return string
     */
    function login() {
        session_start();
        return 'foo';
    }

    /**
     * Called on the logout API route. Destroys the current session
     */
    function logout() {
        session_unset();
        session_destroy();
        return 'bar';
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
