/* Nicholas Martinez - COSCI 542 - Hart - April 10 2019 - HOMEWORK 10
/
/
/!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-/
 *                                                          !
 *  ·▄▄▄▄  ▪  .▄▄ ·  ▄▄· ▄▄▄  ▄▄▄ .▄▄▄▄▄▄▄▄ .               !
 *  ██▪ ██ ██ ▐█ ▀. ▐█ ▌▪▀▄ █·▀▄.▀·•██  ▀▄.▀·               !
 *  ▐█· ▐█▌▐█·▄▀▀▀█▄██ ▄▄▐▀▀▄ ▐▀▀▪▄ ▐█.▪▐▀▀▪▄               !
 *  ██. ██ ▐█▌▐█▄▪▐█▐███▌▐█•█▌▐█▄▄▌ ▐█▌·▐█▄▄▌               !
 *  ▀▀▀▀▀• ▀▀▀ ▀▀▀▀ ·▀▀▀ .▀  ▀ ▀▀▀  ▀▀▀  ▀▀▀                !
 *                                                          !
 *  .▄▄ · ▄▄▄▄▄▄▄▄  ▄• ▄▌ ▄▄· ▄▄▄▄▄▄• ▄▌▄▄▄  ▄▄▄ ..▄▄ ·     !
 *  ▐█ ▀. •██  ▀▄ █·█▪██▌▐█ ▌▪•██  █▪██▌▀▄ █·▀▄.▀·▐█ ▀.     !
 *  ▄▀▀▀█▄ ▐█.▪▐▀▀▄ █▌▐█▌██ ▄▄ ▐█.▪█▌▐█▌▐▀▀▄ ▐▀▀▪▄▄▀▀▀█▄    !
 *  ▐█▄▪▐█ ▐█▌·▐█•█▌▐█▄█▌▐███▌ ▐█▌·▐█▄█▌▐█•█▌▐█▄▄▌▐█▄▪▐█    !
 *   ▀▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀ ·▀▀▀  ▀▀▀  ▀▀▀ .▀  ▀ ▀▀▀  ▀▀▀▀     !
 *                                                          !
 *                      Homework #8                         !
 *                                                          !
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 *
 *   CoSCi 542 - Discrete Structures 
 *   Instructor: Bob Hart
 *   Section: 21566
 *   W - 5:45PM - 10:00PM
 *
 *   --->>
 *       
 *   Name: Nicholas Martinez
 *   Date: 04/10/19
 *    
 *   --->> 
 *   This program builds upon the last program; it presumes that you have a function 
 *   (or some such) that can evaluate an expression like0 & 1 | (1 & !1)and determine that its value is 0
 *
 *
 *   This  program  will  input  as  many  non-blank  lines  as  the  user  wants  to  enter,
 *   terminating when the user enters a blank line.Each non-blank line will be a pair of Boolean 
 *   expressions separated by a comma. The expressions  can  have  all  the  chars  mentioned  in  the  
 *   last  homework,  plus  any  upper case letters that the user chooses to use as variables.
 *
 *  This program, like the last one, does not have to do any error checking; your program can assume without checking that all the inputs are valid.
 *
 *  For  each  non-blank  line,  your  program  will  output  whether  the  two  expressions  are equivalent  
 *   that  is,  whether  they  give  the  same  result  for  every  combination  of values for the variables.
 *
 *
 *
 *  An example run of your program might go as
 *
 *  A & P | Z,    A | P & Z
 *  not equivalent
 *
 *  A & B,    !(!A | !B)
 *  equivalent
 *
 *  A ^ Z,    A&Z  |  !A&!Z
 *  equivalent
 *
 *  (blank line above terminates program.)
 *
 *
 *
 *
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>

#include <iostream>
#include <string>
#include <stack>

std::string user_input();
bool is_valid(std::string s);
bool evaluate(std::string in);
bool is_lparen_or_unary(char c);
int precedence(char c);

int main(int argc, char *argv[]) {

    // Get user input 
    std::string in = user_input();

    // Validate input
    if (!is_valid(in)) {
        exit(0);
    }
    


    // TODO: The idea here is that the evaluate function
    // doesn't need to be changed at all. 
    //
    // Input method should get a total of all the variables,
    // and use 2^n combinations of values for each variable
    //
    // For each set of values assigned to the variables
    // send each expression, ( both sides ) to evaluate and 
    // for equivalent expressions, every call to evaluate must
    // return true
    //  
    // If even one returns false, the expressions are not equivalent
}



// TODO: Write a function to split the input on comma
//
//



// TODO: Write a function to get all the variables, and 
// begin assigning either 0 or 1 to each of them
//
//


// TODO: Probably in the same function, we can pass them repeatedly to
// evaluate, left expression first, store the result, then right express
// and check whether they both evaluate to the same answer
//
//
// Iterate through all possible value combinations

bool evaluate(std::string in) {

    std::stack<int> operands;
    std::stack<char> operators;
    

    // Iterate through characters of string
    for (char t: in) {

        // Push numbers on operand stack
        if (isdigit(t)) {

            // Convert ascii to integer type
            operands.push(std::atoi(&t));
        }

        // If left parenthesis or unary operator, push on operators stack
        else if (is_lparen_or_unary(t)) {
            operators.push(t);
        }

        // If binary operator or closing parenthesis, begin evaluating expression
        else {

            // Evalaute all higher precedence operations first
            while (precedence(operators.top()) > precedence(t)) {

                // Get the operator from the stack
                char op = operators.top();

                // Discard operator
                operators.pop();

                // Get the right hand side of expression
                int rhs = operands.top();
                operands.pop();

                // Define the lefthand side, but we may not need this
                // if operator turns out to be unary ( ! )
                int lhs;
                if (is_lparen_or_unary(op)) {

                    // If the operator is the 'not' operator,
                    // skip rest of loop execution, and push the logical not
                    // value of the right hand side operand on to the operand stack
                    //
                    // This effectively replaces the original operand that we popped intop
                    // rhs, and executes a logical not, and pushes back on to the stack
                    // to be used in other operations
                    if (op == '!') {
                        operands.push(!rhs);
                        continue;
                    }
                }

                // If its a binary operator ( all others than ! )
                else {

                    // Get the left hand side
                    lhs = operands.top();

                    // And discard
                    operands.pop();
                }

                // Choose the appropriate operation for the operator
                switch (op) {

                    // Each logical operator is already defined in C++,
                    // so just use the C++ operation and push result back on to 
                    // operands stack
                    case '&':

                        // Logical and
                        operands.push(rhs && lhs);
                        break;
                    case '^':

                        // XOR operation should always work in this
                        // program, since operands are only 0x0 and 0x1
                        operands.push(rhs ^ lhs);
                        break;
                    case '|':

                        // Logical OR
                        operands.push(rhs || lhs);
                        break;
                }
            }
            
            // If closing parenthesis
            if (t == ')') {

                // Then discard of it, as operation has completed
                operators.pop();
            }
            else {

                // Otherwise push the operator
                operators.push(t);
            }
        }
    }

    // Final operand on stack should be the result
    return operands.top();
}








// Get user input
std::string user_input() {
    
    std::string in;
    char c;
    in.push_back('(');
    // Append input characters to string until newline
    while ((c = getchar()) != '\n') {
        if (c != ' ')  {
            in.push_back(c);
        }
    }
    
    in.push_back(')');
    // Return the input
    return in;

}



// Basic input validation
bool is_valid(std::string s) {
   
    // Assume invalid input
    bool valid = false;
    char accepted_tokens[] = { 
        '!', '&', '^', '|', 
        '(', ')', '0', '1'};
    
    // Iterate through characters in input string
    for (int x = 0; x < s.length(); ++x) {

        valid = false;
        for (int y = 0; y < sizeof(accepted_tokens)/sizeof(char); ++y) {
            
            // If equivalent to at least one accepted token, validate character
            if (s[x] == accepted_tokens[y]) {
                valid = true;
            }
        }
    
        // Return false immediately on first invalid character
        if (!valid) {
            return false;
        }
    }

    // Return state of valid, 0 length strings (new line only) will return false
    return valid;
}

    
bool is_lparen_or_unary(char c) {

    // Verifies left parenthesis or unary operator
    if ((c == '(') || (c == '!')) {
        return true;
    }
    return false;
}


int precedence(char c) {

    // Returns precedence value
    switch (c) {
        case '!': return 4;
        case '&': return 3;
        case '^': return 2;
        case '|': return 1;
        default: return 0;
    }
}






