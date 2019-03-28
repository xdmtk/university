/* Nicholas Martinez - COSCI 542 - Hart - March 18 2019 - HOMEWORK 6
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
 *                      Homework #6                         !
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
 *   Date: 03/18/19
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
 * ! ?& ^ | 
 *
 * Spaces will be tolerated and ignored
 *
 * Your program will handle paren nesting to any depth
 *
 * Your program will terminate on blank line
 *
 *
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>

#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <vector>

std::string user_input();
bool is_valid(std::string s);


int main(int argc, char *argv[]) {

    std::string in = user_input();
    if (is_valid(in)) {
        printf("ok");
    }





}




std::string user_input() {
    
    std::string in;
    char c;
    while ((c = getchar()) != '\n') {
        in.push_back(c);
    }
    
    return in;

}


bool is_valid(std::string s) {
    
    bool valid;
    char accepted_tokens[] = { 
        '!', '&', '^', '|', 
        '(', ')', '0', '1', ' ' };
     
    for (int x = 0; x < s.length(); ++x) {

        valid = false;
        for (int y = 0; y < sizeof(accepted_tokens)/sizeof(char); ++y) {
            if (s[x] == accepted_tokens[y]) {
                valid = true;
            }
        }
        if (!valid) {
            return false;
        }
    }
    return valid;
}


    









