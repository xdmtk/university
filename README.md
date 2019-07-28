# spring2019
```
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
 *                                                          !
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
 -!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
```
All homework for COSCI 542 - Discrete Structures - Pierce College - Spring 2019

### Homework 1:
Write some functions to output the following: 
* Factorial of given `n`
* Combinations for `n` of `k`
* Permutations for `n` of `k`
* Combinations given for alphanumeric `A` `B` and `C`
* Permutations given for alphanumeric `A` `B` and `C`

### Homework 2:
```
 *        * A. Arithmetic sequences
 *        You may do error checking with your program if you want, but it's not required.
 *
 *        This program involves 5 numbers that are relevant in a (finite) arithmetic series.
 *        Suppose we are considering the series
 *        The 5 values we're interested in are
 *        F (the first term): 1.1
 *        I (the increment from one term to the next): 0.1
 *        L (the last term): 1.3
 *        N (the number of terms): 3
 *        T (the total of the terms): 3.6
 *
 *        Let's say that as far as this program is concerned, I has to be nonzero and N has to be > 1.
 *        (Then we don't have to worry about trivial cases.)
 *
 *        The idea here is that the user will input any 3 of these 5 values, and your program outputs the other 2.
 *        The user's input is a letter followed by a number, a letter, a number, a letter, and a number. The 3 letters
 *        are case insensitive, all different, from FILNT; the numbers give the corresponding values.
 *
 *        For example, still considering the example    , if the user types
 *            t  3.6  f  1.1  L  1.3
 *        then the user is saying to your program, "I'm thinking of an arithmetic sequence, whose total is 3.6, whose
 *        first term is 1.1, and whose last term is 1.3. You tell me the other 2 things." Your program should then output
 *            I  0.1  N  3
 *
 *            The user can pick any 3 of the 5 values to input, and can input them in any order.
 *        Your program can output the two other values in either order, labeled with the appropriate letters.
 *
 *        You may recall that doubles can be problematic in that their answers are off by a tiny amount at hard-to-predict time.
 *        For instance, it would be a problem to say
 *            unsigned n = unsigned((first - last)/inc) + 1;
 *        even though that equations is mathematically correct.
 *        One way to get around that problem is to say
 *            double n = (first - last)/inc + 1;
 *        instead.
 *
 *   --->>
```

### Homework 3:
```
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
```

### Homework 4: 
```
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
```


