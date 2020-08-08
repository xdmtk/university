
/* All of this is probably more complicated than it should be without any global scope */
window.addEventListener('load', init);


/**
 * Called on page load. Finds the input/textarea/button DOM
 * objects and registers them to event handlers that handle
 * the submit button click
 */
function init() {
    registerLoginDomEventHandlers(getRelevantDomObjects(), getGlobalStateObjects());
}


/**
 * Returns a dictionary of DOM objects tagged to their name
 * identifiers
 */
function getRelevantDomObjects() {
    return {
        'submit' : document.getElementById('submit'),
        'username' : document.getElementById('username'),
        'password' : document.getElementById('password'),

        'username-span' : document.getElementById('username-span'),
        'password-span' : document.getElementById('password-span'),
        'general-error-span' : document.getElementById('general-error-span'),

        'form-box' : document.getElementById('form-box'),
        'form-box-content' : document.getElementById('form-box-content'),
        'form-box-title' : document.getElementById('form-box-title'),
        'login-modal' : document.getElementById('login-modal'),
        'login-register-switch' : document.getElementById('login-register-switch')
    }
}


/**
 * Constructs a dictionary to pass around state variables to various functions
 * that require them, while maintaining the 'no code outside of functions' requirement
 *
 * @returns - Dictionary of states
 */
function getGlobalStateObjects() {
    return {
        form_action : 'login',
        form_box_contents : '',
        form_box_styles : '',
        logged_in : false,
    }
}


/**
 */
function registerLoginDomEventHandlers(domObjects, globalStates) {

    /* Register anonymous function to handle Submit button click */
    domObjects['submit'].addEventListener('click', () => {

        /* If client-side form validation succeeds, make AJAX call to server */
        if (validateForms(domObjects)) {

            /* Make a post API call to login or register (depending on form state) */
            post('/', {
                'api': globalStates.form_action,
                'username' : domObjects['username'].value,
                'password' : domObjects['password'].value
            },

            /* Handle success response from API */
            () => {

                domObjects['general-error-span'].style.visibility = "hidden";

                /* Depending on the configured submit action, execute the proper callback */
                if (globalStates.form_action === 'login') {
                    loginSuccess(domObjects, globalStates)
                }
                else {
                    registerSuccess(domObjects, globalStates) ;
                }
            },

            (response) => {
                showLoginOrRegisterError(domObjects, globalStates, JSON.parse(response));
            });
        }
    });

    /* Register anonymous function to handle the login/register switch link click */
    domObjects['login-register-switch'].addEventListener('click', () => {
        switchLoginOrRegister(domObjects, globalStates);
    });
}

function showLoginOrRegisterError(domObjects, globalStates, errorMsg) {

    const errorSpan = domObjects['general-error-span'];
    errorSpan.innerHTML = errorMsg['reason'];
    errorSpan.style.visibility = "visible";
}


/**
 * Dynamic page content load called after passing clientside
 * validation
 * @param domObjects
 * @param globalStates
 */
function loginSuccess(domObjects, globalStates) {

    /* Save DOM form box to operate on via shorthand */
    const formBox = domObjects['form-box'];

    /* Save current form box contents and style elements */
    globalStates.form_box_contents = formBox.innerHTML;
    globalStates.form_box_styles = getComputedStyle(formBox);

    post('/', {
        'api' : 'get_content',
        },

        (response) => {
            /* Fade out form box content and fade in new user content based on server AJAX response */
            domContentFadeIn(domObjects, globalStates, response, true);
            domContentFadeOut(domObjects, globalStates);

            /* Manual CSS set to new content area */
            formBox.style.width = "680px";
            formBox.style.height = "700px";
            formBox.style.margin = "100px auto";

        },(response) => {
            alert(response);
        }
    );

}


function registerSuccess(domObjects, globalStates) {

    /* Custom Register success page to display with fade-in/fade-out effects */
    const registerSuccessContent = `
    <style>
        svg {
          display: block;
          height: 23vw;
          width: 5vw;
          color: #2fbd91;
          margin: 0 auto;
          /* SVG path use currentColor to inherit this */
        }

        .circle {
          stroke-dasharray: 76;
          stroke-dashoffset: 76;
          -webkit-animation: draw 1s forwards;
                  animation: draw 1s forwards;
        }

        .tick {
          stroke-dasharray: 18;
          stroke-dashoffset: 18;
          -webkit-animation: draw 1s forwards 1s;
                  animation: draw 1s forwards 1s;
        }

        @-webkit-keyframes draw {
          to {
            stroke-dashoffset: 0;
          }
        }

        @keyframes draw {
          to {
            stroke-dashoffset: 0;
          }
        }
    </style> 
    <span id="form-box-title">Register Success</span>
    <svg viewBox="0 0 26 26" xmlns="http://www.w3.org/2000/svg">
        <g stroke="currentColor" stroke-width="2" fill="none" fill-rule="evenodd" stroke-linecap="round" stroke-linejoin="round">
            <path class="circle" d="M13 1C6.372583 1 1 6.372583 1 13s5.372583 12 12 12 12-5.372583 12-12S19.627417 1 13 1z"/>
            <path class="tick" d="M6.5 13.5L10 17 l8.808621-8.308621"/>
        </g>
    </svg>
    `;

    /* Save the original contents */
    const formBoxContentsOriginal = domObjects['form-box'].innerHTML;

    /* Fadeout original content, fadein register success */
    domContentFadeIn(domObjects, globalStates, registerSuccessContent, false);
    domContentFadeOut(domObjects, globalStates);

    /* Fade back to login/register page */
    setTimeout(() => {
        domContentFadeIn(domObjects, globalStates, formBoxContentsOriginal, false);
        domContentFadeOut(domObjects, globalStates);

        /* Same hack as above, need to wait for login DOM objects to reappear before reinstalling
        their original event handlers */
        setTimeout(() => {
            domObjects = getRelevantDomObjects();
            registerLoginDomEventHandlers(domObjects, globalStates);
        }, 2000);

    }, 4000);

}


/**
 * Tricky function to map event listeners to dynamic DOM content that is yet to originate,
 * namely the log out button, and the button to change the background color as specified
 * by the lab instructions
 *
 * @param domObjects
 * @param globalStates
 */
function registerLoggedInDomEventHandlers(domObjects, globalStates) {
    /* Add the logout button to the global domObjects dictionary and add the logout event handler */
    (domObjects['log-out-span'] = document.getElementById('log-out-span'))
        .addEventListener('click', () => {
            logOut(domObjects, globalStates);
        }
    );

}

/**
 * Custom mimic of the jQuery fadeout function using vanilla JS
 * @param domObjects
 * @param globalStates
 */
function domContentFadeIn(domObjects, globalStates, content, loggingIn = false) {

    const formBoxContent = domObjects['form-box-content'];
    setTimeout(() => {

        /* Fade in the content set by the caller */
        formBoxContent.innerHTML = content;

        /* Setup the event handlers for elements you might find if you're logged in */
        if (loggingIn) {
            registerLoggedInDomEventHandlers(domObjects, globalStates);
            globalStates.logged_in = true;
        }

        /* Ramp up opacity with an interval timer and cut it when opacity is 100% */
        const fadeIn = setInterval(() => {

            formBoxContent.style.opacity = (parseFloat(formBoxContent.style.opacity) + .01).toString();
            if (parseFloat(formBoxContent.style.opacity) === 1.0) {
                clearInterval(fadeIn);
            }
        }, 10);
    }, 2000);

}

/**
 * Custom mimic of the jQuery fadein function using vanilla JS
 * @param domObjects
 * @param globalStates
 */
function domContentFadeOut(domObjects, globalStates) {

    const formBoxContent = domObjects['form-box-content'];

    /* Since the opacity wouldn't have come through without computed styles
    manually set it to full before fading out */
    formBoxContent.style.opacity = "1.0";

    const fadeOut = setInterval(() => {
        formBoxContent.style.opacity = (parseFloat(formBoxContent.style.opacity) - .01).toString();
        if (!parseFloat(formBoxContent.style.opacity)) {
            clearInterval(fadeOut);
        }
    }, 10);
}


/**
 * Executes all visual prep for re-adding the login box to the DOM
 *
 * @param domObjects
 * @param globalStates
 */
function logOut(domObjects, globalStates) {

    post("/", {
        'api' : 'logout'
    },
    () => {
        const formBox = domObjects['form-box'];

        /* On logout click, reset global session state */
        globalStates.logged_in = false;

        /* Fade in old login box saved in globalStates and fadeout current content */
        domContentFadeIn(domObjects, globalStates, globalStates.form_box_contents);
        domContentFadeOut(domObjects, globalStates);

        /* Manual CSS reset back to login box dimensions */
        formBox.style.width = "275px";
        formBox.style.height = "";
        formBox.style.margin = "200px auto";

        /* For some reason the computer styles don't include the original
        width height and margin, so set those first manually before bringing
        the rest of the stylesheet back */
        formBox.style = globalStates.form_box_styles;
        document.getElementsByTagName('html')[0].style.background = '#202225';


        /* HACK: Wait at least a couple seconds for login page DOM objects to be
        present before re-registering login event handlers */
        setTimeout(() => {
            domObjects = getRelevantDomObjects();
            registerLoginDomEventHandlers(domObjects, globalStates);
        }, 2000);
    },
    (response) => {
        alert('Failed to logout. Reason: ' + JSON.parse(response)['reason']);
    });
}

/**
 * Handles text changes when switching the form action from 'Login' to 'Register'
 * and vice versa
 * @param domObjects
 * @param globalStates
 */
function switchLoginOrRegister(domObjects, globalStates) {
    if (globalStates.form_action === 'login') {
        domObjects['form-box-title'].innerHTML = 'Lab 2 Register';
        domObjects['submit'].value = 'Register';
        domObjects['login-register-switch'].innerHTML = 'Already have an account? Click Here'
        globalStates.form_action = 'register';
    }
    else {
        domObjects['form-box-title'].innerHTML = 'Lab 2 Login';
        domObjects['submit'].value = 'Login';
        domObjects['login-register-switch'].innerHTML = 'Don\'t have an account? Click Here'
        globalStates.form_action = 'login';
    }
}


/**
 * Master function encapsulating form validation functions, returning
 * simple true or false based on validation success. Slightly repurposed
 * code from Lab 1
 *
 * @param domObjects
 * @returns {boolean}
 */
function validateForms(domObjects) {

    /* Get form validation errors in dictionary */
    const errors = {};

    /* Validate forms */
    validateUsername(errors, domObjects['username'].value);
    validatePassword(errors, domObjects['password'].value);

    /* Clear out existing text from spans that display error messages */
    clearErrorSpans(domObjects);

    /* If any form validation errors were found */
    if (Object.keys(errors).length) {

        /* Iterate through errors */
        for (let domObject in errors) {

            /* Use the domObject title, append the -span suffix, and use it to
             * address the corresponding span element of the errored form, and apply
             * the appropriate error message */
            domObjects[domObject + '-span'].innerHTML = errors[domObject];
        }
        return false;
    }
    return true;
}

/**
 * Uses Regex to validate the username supplied
 *
 * @param errors - Dictionary of DOM object titles with corresponding errors as keys
 * @param username - Value of username input field
 */
function validateUsername(errors, username) {
    const onlyLettersRegex = /^[A-Za-z]+$/;

    /* Match username against the only letters requirement */
    if (!username.match(onlyLettersRegex)) {

        /* Add appropriate error message if regex fails */
        errors['username'] = "Username field must only contain letters";
    }
}


/**
 * Uses Regex to validate the password supplied

 * @param errors - Dictionary of DOM object titles with corresponding errors as keys
 * @param password - Value of password input field
 */
function validatePassword(errors, password) {
    const oneUpperOneLowerOneNumberRegex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).*/;

    /* Match password against the one upper, one lower, and one number requirement */
    if (!password.match(oneUpperOneLowerOneNumberRegex)) {

        /* Add appropriate error message if regex fails */
        errors['password'] = "Password must contain at least 1 uppercase letter, " +
            "1 lowercase letter, and 1 number";
    }
}
/**
 * Clears the error message text of each span to its corresponding input field
 *
 * @param domObjects - Dictionary of DOM object title keys with DOM object
 * values
 */
function clearErrorSpans(domObjects) {

    /* Iterate the domObjects */
    for (let domObject in domObjects) {

        /* Target the 'span' domObjects */
        if (domObject.includes('-span')) {

            /* Clear any existing error message */
            domObjects[domObject].innerHTML = "";
        }
    }
}

function changeBackgroundColor() {
    document.getElementsByTagName('html')[0].style.background = '#' +
        Math.floor(Math.random()*16777215).toString(16);
}


/**
 * POST wrapper for DOM Ajax API
 * @param endpoint
 * @param params
 * @param success
 * @param error
 */
function post(endpoint, params, success, error) {

    const xhr = new XMLHttpRequest();
    let paramString = ''; let callback = '';

    /* Setup POST method XHR object */
    xhr.open("POST", endpoint);
    xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xhr.onreadystatechange = function() {

        /* Assign the callback function when the request returns based on HTTP status codes */
        if (this.readyState === XMLHttpRequest.DONE) {
            (callback = this.status === 200 ? success : error)(xhr.response);
        }
    }

    /* Build the parameter string for the XHR request body */
    for (let key in params) {
        if (params.hasOwnProperty(key)) {
            paramString += (key + "=" + params[key] + "&");
        }
    }
    /* Chop off the last '&' character */
    paramString = paramString.substr(0, paramString.length-1);

    /* Fire away */
    xhr.send(paramString);
}
