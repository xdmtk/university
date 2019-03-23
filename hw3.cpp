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
std::set<int> intersection(const std::set<int> & s0, const std::set<int> & s1) {
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
 *   Sample output
 *
            SINGLE SET TESTS
            * * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * *

            Set output:
            2	5	8	11	13	
            14	15	19	21	22	
            23	24	25	26	27	
            29	30	34	35	36	
            37	40	42	43	45	
            46	49	50	56	57	
            58	59	62	63	64	
            67	68	69	70	72	
            73	76	77	78	80	
            81	82	84	86	87	
            90	91	92	93	95	
            96	98	57	98	57	
            98	57	98	57	98	



            Total even numbers: 30

            Total interesting numbers: 38

            Set output:
            0	1	2	3	6	
            8	9	12	14	15	
            17	18	19	21	23	
            24	26	27	28	29	
            31	32	34	39	40	
            41	44	45	46	49	
            50	51	52	53	54	
            55	56	60	64	65	
            67	68	70	71	75	
            76	78	79	80	81	
            83	84	86	87	88	
            89	92	93	94	95	
            96	97	99	63	99	



            Total even numbers: 32

            Total interesting numbers: 40

            Set output:
            4	5	6	7	11	
            13	17	18	21	24	
            25	27	28	29	32	
            35	36	37	38	39	
            40	43	44	51	54	
            58	59	63	65	69	
            70	72	74	75	76	
            83	86	88	90	91	
            93	95	96	99	44	
            99	44	99	44	99	



            Total even numbers: 20

            Total interesting numbers: 27

            Set output:
            0	1	4	5	7	
            8	10	11	13	16	
            20	22	24	26	28	
            30	31	33	36	37	
            40	42	43	44	46	
            48	50	52	55	58	
            59	60	61	62	63	
            64	65	66	68	71	
            73	78	79	81	82	
            84	90	94	95	96	
            97	99	52	99	52	
            99	52	99	52	99	



            Total even numbers: 31

            Total interesting numbers: 36

            Set output:
            1	4	5	6	7	
            9	10	11	12	13	
            18	19	20	21	22	
            24	25	26	27	28	
            30	32	36	39	40	
            42	45	48	50	54	
            55	56	58	59	60	
            61	67	69	72	73	
            76	79	81	84	85	
            87	90	92	93	94	
            96	98	99	53	98	
            99	53	98	99	53	
            98	99	53	98	99	



            Total even numbers: 29

            Total interesting numbers: 29
            DUAL SET TESTS
            * * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * *

            Element 1 is in 'little' set but not in 'big' set

            Resulting union set:
            Set output:
            1	2	3	4	5	
            6	7	8	9	10	
            11	12	13	18	19	
            20	21	22	24	25	
            26	27	28	30	32	
            36	39	40	42	45	
            48	50	53	54	55	
            56	58	59	60	61	
            67	68	69	72	73	
            76	79	81	84	85	
            87	89	90	92	93	
            94	96	98	99	59	
            99	59	99	59	99	



            Resulting intersection set:
            Set output:
            36	48	58	72	98	



            Element 1 is in 'little' set but not in 'big' set

            Resulting union set:
            Set output:
            0	1	2	3	4	
            5	6	7	8	9	
            10	11	12	13	14	
            15	18	19	20	21	
            22	24	25	26	27	
            28	29	30	32	33	
            34	35	36	38	39	
            40	42	43	45	46	
            47	48	49	50	51	
            52	53	54	55	56	
            57	58	59	60	61	
            63	64	67	68	69	
            72	73	75	76	79	
            81	84	85	86	87	
            88	89	90	92	93	
            94	96	97	98	99	



            Resulting intersection set:
            Set output:
            0	2	3	4	27	
            28	29	36	39	48	
            49	50	53	56	58	
            59	72	81	85	92	
            94	97	98	99	24	
            99	24	99	24	99	



            Element 1 is in 'little' set but not in 'big' set

            Resulting union set:
            Set output:
            0	1	2	3	4	
            5	6	7	8	9	
            10	11	12	13	14	
            15	16	17	18	19	
            20	21	22	23	24	
            25	26	27	28	29	
            30	31	32	33	34	
            35	36	38	39	40	
            41	42	43	44	45	
            46	47	48	49	50	
            51	52	53	54	55	
            56	57	58	59	60	
            61	63	64	67	68	
            69	70	71	72	73	
            75	76	77	78	79	
            80	81	82	84	85	
            86	87	88	89	90	
            92	93	94	95	96	
            97	98	99	93	99	



            Resulting intersection set:
            Set output:
            0	2	3	4	5	
            10	12	14	24	26	
            27	28	29	34	36	
            38	39	43	46	48	
            49	50	52	53	55	
            56	57	58	59	68	
            72	79	81	85	86	
            90	92	93	94	97	
            98	99	42	99	42	
            99	42	99	42	99	



            Element 1 is in 'little' set but not in 'big' set

            Resulting union set:
            Set output:
            0	1	2	3	4	
            5	6	7	8	9	
            10	11	12	13	14	
            15	16	17	18	19	
            20	21	22	23	24	
            25	26	27	28	29	
            30	31	32	33	34	
            35	36	37	38	39	
            40	41	42	43	44	
            45	46	47	48	49	
            50	51	52	53	54	
            55	56	57	58	59	
            60	61	63	64	66	
            67	68	69	70	71	
            72	73	74	75	76	
            77	78	79	80	81	
            82	83	84	85	86	
            87	88	89	90	92	
            93	94	95	96	97	
            98	99	97	99	97	
            99	97	99	97	99	



            Resulting intersection set:
            Set output:
            0	2	3	4	5	
            7	10	12	14	17	
            18	24	26	27	28	
            29	34	36	37	38	
            39	43	45	46	48	
            49	50	52	53	55	
            56	57	58	59	68	
            70	71	72	73	79	
            81	85	86	89	90	
            92	93	94	97	98	
            99	51	99	51	99	



            Element 1 is in 'little' set but not in 'big' set

            Resulting union set:
            Set output:
            0	1	2	3	4	
            5	6	7	8	9	
            10	11	12	13	14	
            15	16	17	18	19	
            20	21	22	23	24	
            25	26	27	28	29	
            30	31	32	33	34	
            35	36	37	38	39	
            40	41	42	43	44	
            45	46	47	48	49	
            50	51	52	53	54	
            55	56	57	58	59	
            60	61	62	63	64	
            66	67	68	69	70	
            71	72	73	74	75	
            76	77	78	79	80	
            81	82	83	84	85	
            86	87	88	89	90	
            91	92	93	94	95	
            96	97	98	99	99	
            99	99	99	99	99	



            Resulting intersection set:
            Set output:
            0	2	3	4	5	
            7	10	11	12	14	
            15	17	18	21	24	
            26	27	28	29	31	
            34	36	37	38	39	
            43	44	45	46	47	
            48	49	50	51	52	
            53	55	56	57	58	
            59	60	62	63	68	
            70	71	72	73	76	
            77	79	81	85	86	
            89	90	92	93	94	
            96	97	98	99	64	
            99	64	99	64	99	


 *
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <set>
#include <iterator>


void show(const std::set<int> & s);
unsigned evens(const std::set<int> & s);
unsigned howManyInteresting(const std::set<int> & s, bool (*interesting)(int n));
bool is_three_mutiple(int n);
bool subset(const std::set<int> & little, const std::set<int> & big);
std::set<int> Union(const std::set<int> & s0, const std::set<int> & s1);
std::set<int> intersection(const std::set<int> & s0, const std::set<int> & s1);
std::set<int> complement(const std::set<int> & s, const std::set<int> & universe);
std::set<int> difference(const std::set<int> & a, const std::set<int> & b);
std::set<int> symmetricDifference(const std::set<int> & a, const std::set<int> & b);



int main(int argc, char * argv[]) {
    
    std::set<int> little;
    std::set<int> big;

    printf("SINGLE SET TESTS\n* * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * *\n");
    // Set limit on test runs for single set tests
    for (int lim = 0; lim < 5; ++lim) {
        int set_size = (rand() % 100);
        little.clear();
        for (int x = 0; x < set_size; ++x) {
            little.insert(rand() % 100);
        }
        show(little); 
        evens(little);
        howManyInteresting(little, is_three_mutiple);
    }
   
    printf("DUAL SET TESTS\n* * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * ** * * *\n");

    // Set limit on test runs for double set tests
    for (int lim = 0; lim < 5; ++lim) {
        int big_set_size;
        int little_set_size = (rand() % 50);
        do {
            big_set_size = (rand() % 100);
        } while (big_set_size < little_set_size);


        for (int x = 0; x < little_set_size; ++x) {
            little.insert(rand() % 100);
        }
        for (int x = 0; x < little_set_size; ++x) {
            big.insert(rand() % 100);
        }
        subset(little, big);
        Union(little,big); 
        intersection(little,big);

    }

}




// Output the #'s in s with whatever formatting pleases you.
void show(const std::set<int> & s) {
    printf("\nSet output:\n");
    
    // Iterate through set
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
        // Iterate through set, test modulus 2 for odd/even
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
        // Pass functor as test, increment interesting count on pass
        if (interesting(*it)) {
            count++;
        }
    }
    printf("\nTotal interesting numbers: %d\n", count);
    return count;
}



// Example functor, returns numbers are multiple of 3
bool is_three_mutiple(int n) {
    if (!(n % 3)) {
        return false;
    }
    return true;
}


// Return whether all the elements in little also appear in big.
bool subset(const std::set<int> & little, const std::set<int> & big) {
    
    std::set<int>::iterator it;
    
    for (it = little.begin(); it != little.end(); ++it) {

        // Iterate through little, exec find() against 'it' value, if found
        // will not return end()
        if (big.find(*it) == big.end()) {
            printf("\nElement %d is in 'little' set but not in 'big' set\n", *it);
            return false;
        }
    }
    printf("\nAll elements in 'little' set are in 'big' set\n");
    return true;
}


// (The name of this function is spelled with a capital U.)
// create and return the set that is the union of s0 and s1.
std::set<int> Union(const std::set<int> & s0, const std::set<int> & s1) {
    
    std::set<int> res;
    std::set<int>::iterator it0, it1;
    int i, size = std::max(s0.size(), s1.size());
    

    // Iterate on the count of the highest count on set s0 and s1, only accessing
    // iterator if count not exceeded, determined by increments on 'it' up till end()
    for (it0 = s0.begin(), it1 = s1.begin(), i = 0; i < size; ++i, ++it0, ++it1) {
        if (it0 != s0.end()) {
            // For union set, add members from each set only if not already found in resulting set
            if (res.find(*it0) == res.end()) {
                res.insert(*it0);
            }
        }
        if (it1 != s1.end()) {
            if (res.find(*it1) == res.end()) {
                res.insert(*it1);
            }
            res.insert(*it1);
        }
    }
    printf("\nResulting union set:");
    show(res);
    return res;
}

// create and return the set that is the intersection of s0 and s1.
std::set<int> intersection(const std::set<int> & s0, const std::set<int> & s1) {

    std::set<int>::iterator it;
    std::set<int> res;
    
    // Iterate against set and find only common values
    for (it = s0.begin(); it != s0.end(); ++it) {
        if (s1.find(*it) != s1.end()) {
            res.insert(*it);
        }
    }
    printf("\nResulting intersection set:");
    show(res);
    return res;
}

 

// Assume without checking that all the elements of s also appear in universe.
// Build and return the set containing all the elements of universe 
// that don't appear in s.
std::set<int> complement(const std::set<int> & s, const std::set<int> & universe) {

    std::set<int>::iterator it;
    std::set<int> res;
    
    // Same check as above except reversed, != to ==
    for (it = universe.begin(); it != universe.end(); ++it) {
        if (s.find(*it) == s.end()) {
            res.insert(*it);
        }
    }
    printf("\nResulting complement set:");
    show(res);
    return res;
}


// Build and return the difference of sets a and b, which is defined 
// as all the elements of a that don't appear in b. (In case you're 
// wondering whether you're allowed to have one of your functions call 
// another one, yes, that's always fine.)
std::set<int> difference(const std::set<int> & a, const std::set<int> & b) {
    
    std::set<int>::iterator it;
    std::set<int> res;

    // Similar to above but run only one way, a to b
    for (it = a.begin(); it != a.end(); ++it) {
        if (b.find(*it) == b.end()) {
            res.insert(*it);
        }
    }

    printf("\nResulting difference set:");
    show(res);
    return res;

}


// The symmetric difference of sets a and b is defined as the set 
// containing all the elements of a that don't appear in b, together 
// with all the elements of b that don't appear in a.
//
std::set<int> symmetricDifference(const std::set<int> & a, const std::set<int> & b) {

    std::set<int>::iterator it;
    std::set<int> res;
    
    // Similar to above but now run both ways
    for (it = a.begin(); it != a.end(); ++it) {
        if (b.find(*it) == b.end()) {
            res.insert(*it);
        }
    }
    for (it = b.begin(); it != b.end(); ++it) {
        if (a.find(*it) == a.end()) {
            res.insert(*it);
        }
    }

    printf("\nResulting symmetric difference set:");
    show(res);
    return res;
}








