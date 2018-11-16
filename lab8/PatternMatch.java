    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/16/2018                                               !
    !                                                                            #
    #          LAB 8 - Pattern Matching                                          !
    !                                                                            #
    #!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!



________/\\\\\\\\\_______/\\\\\__________/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\_        
_____/\\\////////______/\\\///\\\______/\\\/////////\\\_____/\\\////////__\/////\\\///__       
___/\\\/_____________/\\\/__\///\\\___\//\\\______\///____/\\\/_______________\/\\\_____      
__/\\\______________/\\\______\//\\\___\////\\\__________/\\\_________________\/\\\_____     
_\/\\\_____________\/\\\_______\/\\\______\////\\\______\/\\\_________________\/\\\_____    
_\//\\\____________\//\\\______/\\\__________\////\\\___\//\\\________________\/\\\_____   
__\///\\\___________\///\\\__/\\\_____/\\\______\//\\\___\///\\\______________\/\\\_____  
____\////\\\\\\\\\____\///\\\\\/_____\///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\\\\\_ 
_______\/////////_______\/////_________\///////////___________\/////////__\///////////__


 _______________________/\\\________/\\\\\\\\\\_____________/\\\\\____________________
  ____________________/\\\\\______/\\\///////\\\________/\\\\////____________________
 ___________________/\\\/\\\_____\///______/\\\______/\\\///___________________________
  ________________/\\\/\/\\\____________/\\\//_____/\\\\\\\\\\\_______________________
 _______________/\\\/__\/\\\___________\////\\\___/\\\\///////\\\______________________
  ____________/\\\\\\\\\\\\\\\\___________\//\\\_\/\\\______\//\\\____________________
 ____________\///////////\\\//___/\\\______/\\\__\//\\\______/\\\___________________
   ____________________\/\\\____\///\\\\\\\\\/____\///\\\\\\\\\/______________________
  _____________________\///_______\/////////________\/////////______________________


    Exercise 22.3 (Pattern Matching)
        
        Write a program that prompts the user to enter two strings
        and tests whether the second string is a substring of the first string. Suppose
        the neighboring characters in the string are distinct. (Don’t use the indexOf
        method in the String class.) Analyze the time complexity of your algorithm.
        Your algorithm needs to be at least O(n) time. Here is a sample run of the
        program:




*/


public class PatternMatch  {


    public static void main(String[] args) {

        if ((args.length != 2) || (args[1].length() > args[0].length())) {
            System.out.println("Usage: [ String 1 ] [ Sub-String ] \n\n[ + ] Encapsulate strings with quotes");
            return;
        }

        String s1 = args[0];
        String s2 = args[1];


        System.out.println("String 1: " + s1 + "\nString 2: " + s2);
        PatternMatch.mySubStr(s1, s2);




    }


    public static boolean mySubStr(String s1Str, String s2Str) {


        // Only begin if string 2 is less than or equal to
        // string 1, otherwise cannot possibly be a substring of string 1
        int sizeS1 = s1Str.length(); int sizeS2 = s2Str.length();
        if (sizeS2 > sizeS1) { return false; }


        // Begin timer
        long startTime, endTime, execTime;
        startTime = System.nanoTime();

        // Convert strings to character arrays
        char[] s1 = s1Str.toCharArray(); char[] s2= s2Str.toCharArray();



        /*
         * @params
         *      x  :  Index to iterate over string 1
         *      f  :  Index to iterate in the forward direction over string 2
         *      b  :  Index to iterate in the backward direction over string 2
         *      bc :  Matching index for forward and backward comparison
         *      st :  Records the last non-matching character
         *      match  :  Boolean for supressing the reset of f,b, and bc
         *
         */
        int x, f, b, bc,st=0;
        boolean match;
        
        // Begin iterating String 1, set params accordingly
        for (x=f=0, b=sizeS2-1, bc=b ; x < sizeS1; ++x) {

            // Initialize match to false for each iteration
            match = false;

            /*
             * - Check whether first char of String 1 is equal to 
             * - Check whether backward counting index for SubString on top of the
             *      first index at String 1 will be out of bounds
             * - Check whether the char at the backward counting index for Substring
             *      plus the current index of String 1 is equal to the backward
             *      counting index of SubString
             */
             
            if ( ( s1[x] == s2[f] ) && ((x+bc) <= sizeS1-1)  && ( s1[x+bc] == s2[b] ) ) {

                // If so, match is true, so do not reset indices on SubString
                match = true;

                // Subtract 2 from bc because both x increments and b decrements, leaving
                // a total diff for addition on the index as 2
                bc-=2;

                // If our foward index catches the backward index, all characters up until this
                // point have matched, and SubString is indeed a sub-string of String 1
                if (++f >= --b) {
                    
                    // Display matching index by adding 2 ( 1 for 0-based index and another
                    // 1 since st represents the last matching character )  to st
                    System.out.println("Matched at index: " + (st+2));

                    // Mark the time
                    endTime = System.nanoTime();

                    // Print it
                    System.out.println("Total Execution Time: " + (endTime-startTime) );

                    return true;
                }
            }

            // If there was no match above, reset the indices for iterating String 2, for another
            // round at matching for the next character inline in String 1
            if (match == false) {
                st=x;
                f=0;
                b=sizeS2-1;
                bc=b;
            }


        }

        // On failure, print the execution time and return false
        endTime = System.nanoTime();
        System.out.println("Total Execution Time: " + (endTime-startTime) );
        return false;

    }








}





