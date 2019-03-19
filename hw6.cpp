/* Nicholas Martinez - COSCI 542 - Hart - March 18 2019
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
 *
    CS 542 Homework: Is this relation an equivalence relation?

    Recall that a relation is a set of ordered pairs — in our case, a set of ordered pairs of unsigneds. Underlying a relation is the relation's universal set: each element of each ordered pair is an element of that universal set.

    Recall that a relation may or may not be an equivalence relation.
    An equivalence relation is a relation with 3 properties:
    Reflexivity: for each element e in the universal set, the ordered pair (e, e) is in the relation.
    Symmetry: for each ordered pair (a, b) in the relation, the ordered pair (b, a) is also in the relation.
    Transitivity: for any a, b, and c in the universal set, if (a, b) and (b, c) are in the relation, then (a, c) is also in the relation.

    Your job is to write function named er (equivalence relation):
    bool er(const SOP & sop, const set<unsigned> & univ)

    (In the above I'm assuming the use of
    typedef pair<unsigned, unsigned> OP;
    typedef set<OP> SOP;
    that we introduced previously, but if you prefer, you can write
    bool er(const set<pair<unsigned, unsigned>> & sop, const set<unsigned> & univ);
    instead.)

    The function's job is to return whether sop is an equivalence relation. If it passes all 3 tests, return true; if it fails any of the 3, return false.

    Write a main that calls your er function. You decide the details of your main, I'm interested in your er function.

    Please write your program as a single .cpp file, and make the first line a comment telling me the class (CS 542), the assignment (Hw6), and your name.
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

typedef std::pair<unsigned, unsigned> OP;
typedef std::set<OP> SOP;

void show(const OP & op);
void show(std::set<unsigned> u);
OP makeOP(unsigned first, unsigned second);
void show(const SOP & sop);
bool er(const SOP & sop, const std::set<unsigned> & univ);

void assign_values(int *arr, int n, unsigned *a, unsigned *b, unsigned *c);
bool next_combination(int n, int r, int *a);



int main(int argc, char * argv[]) {
    srand(time(NULL));    
    SOP mySop; 
    std::set<unsigned> universe;
    
    // Generate ordered pairs and 
    // 1. Push to SOP `mySop`
    // 2. Insert each element into universal set `universe`
    for (int x=0; x < 5; x++) {
        
        OP test_mp = makeOP((unsigned) rand() % 30, (unsigned) rand() % 30);

        mySop.insert(test_mp);
        universe.insert(test_mp.first);
        universe.insert(test_mp.second);
    }

    er(mySop, universe);
}


/*
 *  Reflexivity: for each element e in the universal set, the ordered pair (e, e) is in the relation.
 *  Symmetry: for each ordered pair (a, b) in the relation, the ordered pair (b, a) is also in the relation.
 *  Transitivity: for any a, b, and c in the universal set, if (a, b) and (b, c) are in the relation, then (a, c) is also in the relation.
 */
bool er(const SOP & sop, const std::set<unsigned> & univ) {
   /* 
    // Begin iterating the universe and applying tests to elements
    std::set<unsigned>::iterator it = univ.begin();

    // Reflexivity test
    for ( ; it != univ.end(); ++it ) {
        
        // Assign element to stack temporarily for tests
        unsigned elem = *it; 

        // Reflexive test , make OP (elem,elem) and test whether than OP 
        // is in the set `sop`
        if (sop.find( makeOP( elem, elem )) == sop.end()) { 
            return false;
        }
        // If OP (elem , elem) is in `sop`. continue with tests
    }


    // Symmetry test
    SOP::iterator sopIt = sop.begin();

    for ( ; sopIt != sop.end(); ++sopIt ) {
        
        // Get elements a and b from OP in `sop`
        unsigned elemA = sopIt->first;
        unsigned elemB = sopIt->second;

        // Make an OP with `elemA` and `elemB` reversed and check
        // for existence in `sop`
        if (sop.find( makeOP( elemB , elemA )) == sop.end()) { 
            return false;
        }
    }

*/
    // Transitivity test
    // For this test, the pair making operation is a bit more expensive,
    // as we must make (n!/(3! (n - 3)!)) OP's
    //
    show(univ);

    // First we get the size `n` from the universal set
    int universe_len = univ.size();

    // Next since we only need a, b, and c values, we can give our
    // choose_k array ( which will hold the combinations ) three members
    int choose_k[] = {1,2,3}; 

    // We declare our variables a b and c and pass them as pointers
    // to be assign values from next_combination, (the first pass will have the values
    // 1, 2, and 3,
    unsigned a, b, c;
    do {
        assign_values(choose_k, 3, &a, &b, &c);

        // After the values are assigned, we can continue with the transitivity test
        
    } while (next_combination(universe_len, 3, choose_k));
    


}

// Generates the combinations for 3 values (a, b, and c,) (k) in the
// universe set (n) , and assigns the values back to main() to execute
// the transitivity test
//  
bool next_combination(int n, int r, int *a) {
    int last_offset = r-1;
    while (a[last_offset] == n-r+(last_offset+1)) {
        last_offset--;
    }
    if (last_offset < 0) {
        return false;
    }
    a[last_offset]++;
    for (int i = last_offset+1; i<r; i++) {
        a[i] = a[last_offset]+(i-last_offset);
    }
    return true;
}

void assign_values(int *arr, int n, unsigned *a, unsigned *b, unsigned *c) {

    arr[0] = *a;
    arr[1] = *b;
    arr[2] = *c;

}


// makeOP's job is to create and return an OP with values equal to the args.
OP makeOP(unsigned first, unsigned second) {
    OP ret;
    ret.first = first; ret.second = second;

    return ret;
}


// To show the universe set
void show(std::set<unsigned> u) {
   
    std::set<unsigned>::iterator it;
    printf("\nSet size: %d - Show set:\n", u.size());
    for (it = u.begin(); it != u.end(); it++) { 
        printf("%d", *it);
    }


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


// Prints out the given pair
void show(const OP & op) {
    printf("Show pair: (%d, %d)\n", op.first, op.second);
}


