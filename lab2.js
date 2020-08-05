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
        form_box_contents : ''
    }
}


/**
 */
function registerDomEventHandlers(domObjects, globalStates) {

    /* Register anonymous function to handle Submit button click */
    domObjects['submit'].addEventListener('click', () => {

        /* If client-side form validation succeeds, make AJAX call to server */
        if (validateForms(domObjects)) {
            const formBox = domObjects['form-box'];
            globalStates.form_box_contents = formBox.innerHTML;
            formBox.innerHTML = "";
            formBox.style.width = "600px";
            formBox.style.height = "700px";
            formBox.style.margin = "100px auto";
        }
    });

    /* Register anonymous function to handle the login/register switch link click */
    domObjects['login-register-switch'].addEventListener('click', () => {
        switchLoginOrRegister(domObjects, globalStates);
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
