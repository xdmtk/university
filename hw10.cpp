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
#include <cctype>

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

std::string user_input();
bool evaluate(std::string in);
bool is_lparen_or_unary(char c);
int precedence(char c);
int index_of(char var, std::vector<char> vars);

std::vector<std::string> split_expressions(std::string in);
std::string replace_with_vals(std::string expr, std::vector<char> vals, std::vector<char> vars);
bool master_evaluate(std::vector<std::string> in);

int main(int argc, char *argv[]) {

    // Get user input 
    std::string in = user_input();
    std::vector<std::string> expressions = split_expressions(in);

    if (master_evaluate(expressions)) {
        printf("Expressions are equivalent\n");
        return 0;
    }

    printf("Expressions are not equivalent\n");


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



std::vector<std::string> split_expressions(std::string in) {
    
    std::vector<std::string> out;
    
    // Splits the input expression into two expessions based on 
    // the comma
    out.push_back(in.substr(0, in.find_first_of(',')));
    out.push_back(in.substr(in.find_first_of(',')+1, in.length()-1));
    
    std::cout << out[0] << " " << out[1] << std::endl;
    
    return out;
}


// TODO: Write a function to get all the variables, and 
// begin assigning either 0 or 1 to each of them
//
//
bool master_evaluate(std::vector<std::string> in) {
    
    std::string expr1 = in[0];
    std::string expr2 = in[1];

    std::vector<char> vars;
    std::vector<char> vals;

    // Assume correct input and get variables of expression
    // by iterating over either string
    for (int x = 0; x < expr1.length(); ++x) {
        
        // Find all alpha variables in expression
        if (std::isalpha(expr1[x])) {
            
            // Only if they're unique
            if (std::find(vars.begin(), vars.end(), expr1[x]) == vars.end()) {

                // Collect all unique variables
                vars.push_back(expr1[x]);
            }
        }
    }
    

    // We need 2^(amount of variables) combinations of 0's and 1's to
    // assign to each variable and test in every situation if they are equiv
    // Use base two bit counting to assign values to variables
    //
    // First we set out max by shifting right the amount of variables we have 
    // giving us 2^vars.size() 
    long long unsigned int total = 1 << vars.size();

    // We also need a counter starting from 0, which will iterate through
    // each bit combination
    long long unsigned int counter = 0;
    

    // Begin executing combinations 
    while (counter < total) {
        
        int counter_t = counter;
        // For each var, we need to assign a value based on
        // the current bits set in counter
        for (int x = 0; x < vars.size(); ++x) {

            // And each bit of counter with 0x1 to assign
            // the actual bit value to val
            char val = (counter_t & 0x1) + '0';

            // Push val to vals vector
            vals.push_back(val);
            
            // Shift left counter value to get next bit
            counter_t = counter_t >> 1;
        }

        // Now we should have the vector vars with all letter 
        // variables and a corresponding vector vals with 
        // the combination of values to apply for each variable
        //
        // So no we we need to replace each variable in the expression
        // with the corresponding values
        
        std::string new_expr1 = replace_with_vals(expr1, vals, vars);
        std::string new_expr2 = replace_with_vals(expr2, vals, vars);
       
        
        // Now we evaluate the boolean expressions individually and
        // test whether they are equivalent. IF the expressions are truly equivalent
        // this condition will never be true, and make it out
        // of the while loop to return true. Otherwise master_evalaute will
        // return false here
        if (evaluate(new_expr1) != evaluate(new_expr2)) {

            return false;
        }

        // Increment the counter for the next set of values
        counter++;
    }
    
    return true;
}



// Function to replace variables with values
std::string replace_with_vals(std::string expr, std::vector<char> vals, std::vector<char> vars) {
    for (int x = 0; x < expr.length(); ++x) {
        
        if (std::isalpha(expr[x])) {
            
            // Get the index of the variable found in the expression
            int index = index_of(expr[x], vars);

            // Assign 0 or 1 to variable in expression 
            expr[x] = vals[index];

        }
    }

    // Return the value substitute expression
    return expr;
}



int index_of(char var, std::vector<char> vars) {
    
    std::vector<char>::iterator it = vars.begin();
    int index;

    for (index = 0; index < vars.size(); ++index, ++it) {
        
        if (*it == var) {
            return index;
        }
    }
    printf("About to throw exception\n");
    throw "Index not found exception!";
}


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
        if (c != ' ' && c != ',')  {
            in.push_back(c);
        }
        if (c == ',') {
            in.push_back(')');
            in.push_back(',');
            in.push_back('(');
        }
    }
    
    in.push_back(')');
    // Return the input
    return in;

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






