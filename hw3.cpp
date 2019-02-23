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
 *                      Homework #3                         !
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
 *   Date: 02/15/18
 *    
 *   --->> 
 *
 * CS 542 Homework: sets

 *      For this homework, you will write several functions that do operations on sets.
 *
 *      void show(const set<int> & s);
 *      Output the #'s in s with whatever formatting pleases you.
 *
 *      unsigned evens(const set<int> & s);
 *      Return the number of even numbers in s.
 *
 *      unsigned howManyInteresting(const set<int> & s, bool (*interesting)(int n));
 *      Return the number of interesting numbers in s, according to the function whose pointer we pass as the second arg.
 *
 *      bool subset(const set<int> & little, const set<int> & big);
 *      Return whether all the elements in little also appear in big.
 *
 *      set<int> Union(const set<int> & s0, const set<int> & s1);
 *       (The name of this function is spelled with a capital U.)
 *      create and return the set that is the union of s0 and s1.
 *
 *      set<int> intersection(const set<int> & s0, const set<int> & s1);
 *      create and return the set that is the intersection of s0 and s1.
 *
 *      set<int> complement(const set<int> & s, const set<int> & universe);
 *      Assume without checking that all the elements of s also appear in universe.
 *      Build and return the set containing all the elements of universe that don't appear in s.
 *
 *      set<int> difference(const set<int> & a, const set<int> & b);
 *      Build and return the difference of sets a and b, which is defined as all the elements of a that don't appear in b. (In case you're wondering whether you're allowed to have one of your functions call another one, yes, that's always fine.)
 *
 *      set<int> symmetricDifference(const set<int> & a, const set<int> & b);
 *      The symmetric difference of sets a and b is defined as the set containing all the elements of a that don't appear in b, together with all the elements of b that don't appear in a.
 *
 *      main: write a main that calls these other functions. You decide the details of your main.
 *
 *   --->> 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <set>
#include <iterator>


void show(const std::set<int> & s);
unsigned evens(const std::set<int> & s);
unsigned howManyInteresting(const std::set<int> & s, bool (*interesting)(int n));
bool testFunctor(int n);
bool subset(const std::set<int> & little, const std::set<int> & big);



int main(int argc, char * argv[]) {
    
    std::set<int> foo;
    std::set<int> fooBig;
    for (int y=0; y < 50; ++y) {
        foo.insert(y);
    }
    for (int y=0; y < 100; ++y) {
        fooBig.insert(y);
    }
    show(foo); 
    evens(foo);
    howManyInteresting(foo,testFunctor);
    subset(foo, fooBig);
    

}




// Output the #'s in s with whatever formatting pleases you.
void show(const std::set<int> & s) {
    printf("\nSet output:\n");

    std::set<int>::iterator it;
    for (it = s.begin(); it != s.end();) {
        for (int x=0; x < 5; ++x) {
            printf("%d\t", *it++);
        }
        printf("\n");
    }
    printf("\n\n");
}
        

// Return the number of even numbers in s.
unsigned evens(const std::set<int> & s) {

    unsigned count = 0;
    std::set<int>::iterator it;

    for (it = s.begin(); it != s.end(); ++it) {
        if (!(*it % 2)) {
            count++;
        }
    }
    printf("\nTotal even numbers: %d\n", count);
    return count;
}


// Return the number of interesting numbers in s, according to the function whose pointer we pass as the second arg.
unsigned howManyInteresting(const std::set<int> & s, bool (*interesting)(int n)) {
   
    unsigned count = 0;
    std::set<int>::iterator it;

    for (it = s.begin(); it != s.end(); ++it) {
        if (interesting(*it)) {
            count++;
        }
    }
    printf("\nTotal interesting numbers: %d\n", count);
    return count;
}


bool testFunctor(int n) {
    if (!(n % 3)) {
        return false;
    }
    return true;
}

// Return whether all the elements in little also appear in big.
bool subset(const std::set<int> & little, const std::set<int> & big) {
    
    std::set<int>::iterator it;

    for (it = little.begin(); it != little.end(); ++it) {
        if (big.find(*it) == big.end()) {
            printf("\nElement %d is in little set but not in 'big' set\n", *it);
            return false;
        }
    }
    printf("\nAll elements in 'little' set are in 'big' set\n");
    return true;


}
