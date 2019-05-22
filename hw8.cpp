/* Nicholas Martinez - COSCI 542 - Hart - April 2 2019 - HOMEWORK 8
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
 *   Date: 04/2/19
 *    
 *   --->> 
 *
 *
 * For  this  program,  you  will  write  a  Boolean  calculator  that  
 * will  evaluate  as  many Boolean expressions as the user wants 
 * to enter.
 *
 * Your program will recognize!as the  (unary) not operator&as the and operator 
 * (not && like in C++, just &)^as the exclusive-or operator|as the or operator
 * ()parens to override precedence0as the value false1as the value trueAs with C++, 
 * these 4 operators will have 4 levels of precedence:
 *
 *
 *
 * ! & ^ | 
 *
 * Spaces will be tolerated and ignored
 *
 * Your program will handle paren nesting to any depth
 *
 * Your program will terminate on blank line
 *
 * SAMPLE OUTPUT:
       
 
        [~/school/discr] (master) >>> run
        
        (1 & 0)

        false
        [~/school/discr] (master) >>> run
        (1 & 1)

        true
        [~/school/discr] (master) >>> run
        1

        true
        [~/school/discr] (master) >>> run
        0

        false
        [~/school/discr] (master) >>> run
        1 ^ 0

        true
        [~/school/discr] (master) >>> run
        1 ^ 1

        false
        [~/school/discr] (master) >>> run
        0 ^ 0

        false
        [~/school/discr] (master) >>> run
        (!1 & 1) | 1

        true
        [~/school/discr] (master) >>> run
        (!1 & 1) & 1

        false
        [~/school/discr] (master) >>> run
        (1 ^ 0) & ( (!0 & 1) & 1 )

        true

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

    // Send input to evaluate
    if (evaluate(in)) {

        // If evaluate returns true, print true
        printf("\ntrue\n");
    }
    else {
        // If evaluate returns false, print false
        printf("\nfalse\n");
    }





}



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






