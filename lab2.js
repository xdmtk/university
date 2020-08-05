window.addEventListener('load', init);


/**
 * Called on page load. Finds the input/textarea/button DOM
 * objects and registers them to event handlers that handle
 * the submit button click
 */
function init() {
    registerDomEventHandlers(getRelevantDomObjects());
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

        'login-link' : document.getElementById('login-link'),
        'login-modal' : document.getElementsByTagName('html')[0]
    }
}


/**
 */
function registerDomEventHandlers(domObjects) {

    /* Register anonymous function to handle Submit button click */
    domObjects['submit'].addEventListener('click', () => {

        * If client-side form validation suceeds, make AJAX call to server */
        if (validateForms(domObjects)) {
        }
    });



}

function validateForms(domObjects) {

    /* Get form validation errors in dictionary */
    const errors = _validateForms(domObjects);

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

        /* Modify the background color of the page as indicated by the instructions */
        domObjects['login-modal'].style.backgroundColor = "#ff2509";
        return false;
    }
    else {

        /* Restore the background color of the page if no errors found */
        domObjects['login-modal'].style.backgroundColor = "#202225";
        return true;
    }
}

/**
 */
function _validateForms(domObjects) {

    /* Dictionary of potential error messages for input fields */
    const errors = {};

    /* Validate forms */
    validateUsername(errors, domObjects['username'].value);
    validatePassword(errors, domObjects['password'].value);

    /* Return error dictionary */
    return errors;
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
