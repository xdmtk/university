window.addEventListener('load', init);


/**
 * Called on page load. Finds the input/textarea/button DOM
 * objects and registers them to event handlers that handle
 * the submit button click
 */
function init() {
    registerDomEventHandlers(getRelevantDomObjects(), getGlobalStateObjects());
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
function registerDomEventHandlers(domObjects, globalStates) {

    /* Register anonymous function to handle Submit button click */
    domObjects['submit'].addEventListener('click', () => {
        console.log("In submit");
        /* If client-side form validation succeeds, make AJAX call to server */
        if (validateForms(domObjects)) {
            loginSuccess(domObjects, globalStates);
        }
    });

    /* Register anonymous function to handle the login/register switch link click */
    domObjects['login-register-switch'].addEventListener('click', () => {
        switchLoginOrRegister(domObjects, globalStates);
    });
}


/**
 * Dynamic page content loads after successfully logging in
 * @param domObjects
 * @param globalStates
 */
function loginSuccess(domObjects, globalStates) {

    const formBox = domObjects['form-box'];

    globalStates.form_box_contents = formBox.innerHTML;
    globalStates.form_box_styles = getComputedStyle(formBox);

    domContentFadeIn(domObjects, globalStates, getUserContent(domObjects, globalStates), true);
    domContentFadeOut(domObjects, globalStates);

    formBox.style.width = "600px";
    formBox.style.height = "700px";
    formBox.style.margin = "100px auto";
}


/**
 * Returns dynamic content for logged in users from API call based
 * on user login credentials
 *
 * @param domObjects
 * @param globalStates
 * @returns {string}
 */
function getUserContent(domObjects, globalStates) {
    return `<span id="log-out-span" style="text-decoration: underline; cursor: pointer; text-align: center" onclick="">Log out</span>`;

}


function registerLoggedInDomEventHandlers(domObjects, globalStates) {
    (domObjects['log-out-span'] = document.getElementById('log-out-span')).addEventListener('click', () => {
        globalStates.logged_in = false;
        const formBox = domObjects['form-box'];

        domContentFadeIn(domObjects, globalStates, globalStates.form_box_contents);
        domContentFadeOut(domObjects, globalStates);
        formBox.style.width = "275px";
        formBox.style.height = "";
        formBox.style.margin = "200px auto";
        formBox.style = globalStates.form_box_styles;

        setTimeout(() => {
            domObjects = getRelevantDomObjects();
            registerDomEventHandlers(domObjects, globalStates);
        }, 2000);
    });

}

/**
 * Custom mimic of the jQuery fadeout function using vanilla JS
 * @param domObjects
 * @param globalStates
 */
function domContentFadeIn(domObjects, globalStates, content, loggingIn = false) {

    const formBoxContent = domObjects['form-box-content'];
    setTimeout(() => {

        globalStates.logged_in = true;
        formBoxContent.innerHTML = content;
        if (loggingIn) {
            registerLoggedInDomEventHandlers(domObjects, globalStates);
        }

        const fadeIn = setInterval(() => {
            formBoxContent.style.opacity = (parseFloat(formBoxContent.style.opacity) + .01);
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
    formBoxContent.style.opacity = "1.0";
    const fadeOut = setInterval(() => {
        formBoxContent.style.opacity = (parseFloat(formBoxContent.style.opacity) - .01);
        console.log(formBoxContent.style.opacity);
        if (!parseFloat(formBoxContent.style.opacity)) {
            clearInterval(fadeOut);
        }
    }, 1);
}

function logOut(domObjects, globalStates) {

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
