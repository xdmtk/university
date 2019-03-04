/*!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-/
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
 *                      Homework #4                         !
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
 *   Date: 02/27/18
 *    
 *   --->> 
 *
 * CS 542 Homework: sets
 *
 *      For this homework, we are working with ordered pairs of unsigned's:
 *          pair<unsigned, unsigned>
 *      and with sets of these pairs:
 *          set<pair<unsigned, unsigned>>
 *      I find these long type names somewhat unwieldy, so I'll use abbreviations:
 *          typedef pair<unsigned, unsigned> OP;
 *          typedef set<OP> SOP;
 *      but you don't have to use these abbreviations.
 *
 *      Here are some little functions to get you used to working with these types:
 *
 *      void show(const OP & op);
 *      show's job is to output the 2 unsigned's in op, with parens and a comma.
 *      For instance, if your main said
 *          OP x(7, 3);
 *          show(x);
 *      or the shorter
 *          show(OP(7,3));
 *      then your show function would output
 *          (7, 3)
 *
 *      OP makeOP(unsigned first, unsigned second);
 *      makeOP's job is to create and return an OP with values equal to the args.
 *      (Not really useful, since main can make its own OP as easily as it can call this function, but this is just for practice.)

 *      OP add(const OP & a, const OP & b);
 *      add's job is to create and return an order pair gotten by adding the corresponding parts of the to args. For example, if your main said
 *          show(add(OP(1,2), OP(5,7)));
 *      then your show function would output
 *          (6, 9)
 *
 *      void show(const SOP & sop);
 *      show's job is to output all the ordered pairs in sop by passing each one to your previous show function.
 *
 *      bool elementOf(const OP & op, const SOP & sop);
 *      elementOf's job is to return whether op is an element of sop.
 *      For example,
 *          elementOf(OP(1,2), SOP{OP(1,1), OP(2,1), OP(2,2))
 *      should return false.
 *
 *      bool firstFound(unsigned first, const SOP & sop);
 *      firstFound's job is to return whether the number in first appears as the first member of any OP in sop.
 *
 *
 *      bool secondFound(unsigned second, const SOP & sop);
 *      secondFound's job is to return whether the number in second appears as the second member of any OP in sop.
 *
 *      bool eitherFound(unsigned n, const SOP & sop);
 *      eitherFound's job is to return whether n appears in either position of any OP in sop.
 *      (It's always fine your functions to call your other functions if you want to.)
 *
 *      SOP Union(const SOP & sop0, const SOP & sop1);
 *      Union's job is to create and return (by value) a set that is the union of the two sets passed to it.
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
#include <utility>
#include <string>
#include <set>

typedef std::pair<unsigned, unsigned> OP;
typedef std::set<OP> SOP;

void show(const OP & op);
OP makeOP(unsigned first, unsigned second);
OP add(const OP & a, const OP & b);
void show(const SOP & sop);
bool elementOf(const OP & op, const SOP & sop);
bool firstFound(unsigned first, const SOP & sop);
bool secondFound(unsigned second, const SOP & sop);
bool eitherFound(unsigned n, const SOP & sop);
SOP Union(const SOP & sop0, const SOP & sop1);




int main(int argc, char * argv[]) {


    srand(time(NULL));

    // Test case for show()
    printf("TESTING SHOW FUNCTION:\n* * * * * * * * * * * * * *\n");
    for (int x=0; x < 5; x++) {
       
        // Show a randomly generated OP
        OP test_show((rand() % 10), (rand() % 10));
        show(test_show);
    }
    printf("\n\n");
   
    
    // Test case for makePair()
    printf("TESTING MAKE PAIR + SHOW FUNCTION:\n* * * * * * * * * * * * * *\n");
    for (int x=0; x < 5; x++) {
       
        // Same as above except use makeOP
        OP test_mp = makeOP(rand() % 10, rand() % 10);
        show(test_mp);
    }
    printf("\n\n");
    
    
    // Test case for add()
    printf("TESTING MAKE PAIR + ADD + SHOW FUNCTION:\n* * * * * * * * * * * * * *\n");
    for (int x=0; x < 5; x++) {
        
        // Use make pair as params for add() to generated the resulting OP
        OP add_res = add(makeOP(rand() % 10, rand() % 10), 
                makeOP(rand() % 10, rand() % 10));

        // Then show
        show(add_res);
    }
    printf("\n\n");


    // Test case for elementOf()
    printf("TESTING MAKE PAIR + ADD + SHOW + ELEMENTOF :\n* * * * * * * * * * * * * *\n");
    for (int x=0; x < 2; x++) {

        // Decalare and fill a SOP with randomly generated OPS
        SOP test_sop;
        for (int x=0; x < 5; x++) {

            // The randomly generated OPS come from two makeOP() calls and
            // adding the result with an add() call
            test_sop.insert(add(makeOP(rand() % 10, rand() % 10), 
                    makeOP(rand() % 10, rand() % 10)));
        }

        // Show the generated SOP
        printf("Generated SOP:\n");
        show(test_sop);

        // Make a random OP
        OP add_res = add(makeOP(rand() % 10, rand() % 10), 
                makeOP(rand() % 10, rand() % 10));

        // Show it
        printf("\nGenerated OP:\n");
        show(add_res);

        // Show if is an element
        printf("\nElement of result:\n");

        // Star result string with backspace escape
        std::string res_str = "\b";

        // If elementOf returns true, add ' not' to the string, otherwise keep as it
        (elementOf(add_res, test_sop)) ? res_str += "" : res_str += " not";

        // Then string should either say OP is a member of SOP or OP is not a member of SOP
        std::cout << "OP is " << res_str << " a member of SOP\n" << std::endl;


    }

}





// Prints out the given pair
void show(const OP & op) {
    printf("Show pair: (%d, %d)\n", op.first, op.second);
}


// makeOP's job is to create and return an OP with values equal to the args.
OP makeOP(unsigned first, unsigned second) {
    OP ret;
    ret.first = first; ret.second = second;

    return ret;
}


// Returns an order pair by adding the correspdonding parts of
// the supplied pairs
OP add(const OP & a, const OP & b) {
    
    OP ret;

    // Adds the parts of the supplied pairs, stores in ret
    ret.first = a.first + b.first;
    ret.second= a.second + b.second;

    // Returns pair to be copied into receiving stack variable
    return ret;
}



// Show's job is to output all the ordered pairs in sop by passing 
// each one to your previous show function.
void show(const SOP & sop) { 
   
    SOP::iterator it;
    printf("\nSet size: %d - Show set:\n", sop.size());
    for (it = sop.begin(); it != sop.end(); it++) { 
        // For each OP in SOP, pass it to show overloaded for OP type
        show(*it);
    }
}


// ElementOf's job is to return whether op is an element of sop.
bool elementOf(const OP & op, const SOP & sop) {

    SOP::iterator it;
    for (it = sop.begin(); it != sop.end(); it++) { 
        // Iterate through SOP and use == operator to determine
        // equivalence 
        if (op == *it) {
            return true;
        }
    }
    return false;
}


// firstFound's job is to return whether the number in first 
// appears as the first member of any OP in sop.
bool firstFound(unsigned first, const SOP & sop) {

    SOP::iterator it;
    for (it = sop.begin(); it != sop.end(); it++) { 

        // Similar to above except only test against 'first' member
        // of it's pointed OP
        if (first == it->first) {
            return true;
        }
    }
    return false;
} 


// secondFound's job is to return whether the number in second appears 
// as the second member of any OP in sop.
bool secondFound(unsigned second, const SOP & sop) {
    
    SOP::iterator it;
    for (it = sop.begin(); it != sop.end(); it++) { 

        //  Exactly the same as above except for member 'second'
        if (second == it->second) {
            return true;
        }
    }
    return false;
}


// eitherFound's job is to return whether n appears in either position of any OP in sop.
// (It's always fine your functions to call your other functions if you want to.)
bool eitherFound(unsigned n, const SOP & sop) {

    SOP::iterator it;
    for (it = sop.begin(); it != sop.end(); it++) { 

        // Call the previous two functions to check for first or second 
        // finds in the given SOP
        if (firstFound(n, sop) || (secondFound(n, sop))) {
            return true;
        }
    }
    return false;
}



// Union's job is to create and return (by value) a set that 
// is the union of the two sets passed to it.
SOP Union(const SOP & sop0, const SOP & sop1) {
    
    SOP::iterator it;
    SOP union_set;
    for (it = sop0.begin(); it != sop0.end(); it++) { 
        if (sop1.find(*it) != sop1.end()) {
            union_set.insert(*it);
        }
    }
    return union_set;
}

    





