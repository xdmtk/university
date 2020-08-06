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
        if (!isset($_POST['api'])) {
            return main_site;
        }
        switch ($_POST['api']) {
            case 'login':
                return login();
            case 'logout':
                return logout();
            case 'get_content':
                return get_content();
            default:
                http_response_code(400);
                return json_encode([
                    'status' => 'failure',
                    'reason' => 'No API call specified'
                ]);
        }
    }

    function login() {return 'foo';}
    function logout() {return 'bar';}
    function get_content() {return 'baz';}

    echo router();
?>
