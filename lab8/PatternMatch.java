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

import java.util.Random;

public class PatternMatch  {


    public static void main(String[] args) {
    
        System.out.println(PatternMatch.mySubStr("this is a test", "test"));
        



    }


    public static boolean mySubStr(String s1Str, String s2Str) {
       

        // Only begin if string 2 is less than or equal to 
        // string 1, otherwise cannot possibly be a substring of string 1
        int sizeS1 = s1Str.length(); int sizeS2 = s2Str.length();
        if (sizeS2 > sizeS1) { return false; }


        // Begin timer
        long startTime, endTime, execTime;
        startTime = System.nanoTime();
        char[] s1 = s1Str.toCharArray(); char[] s2= s2Str.toCharArray();

        // Forward and backwords index for matching string 2
        int x, f, b;
        boolean match;
        for (x=f=0, b=sizeS2-1 ; x < sizeS1; ++x) {

            match = false;  
            if ( ( s1[x] == s2[f] ) && ((x+b) <= sizeS1)  && ( s1[x+b] == s2[b] ) ) {
                match = true;   
                if (++f >= --b) {
                    endTime = System.nanoTime();
                    System.out.println("Total Execution Time: " + (endTime-startTime) );
                    return true;
                }
            }

            if (match == false) {
                f=0;
                b=sizeS2-1;
            }

                
        }
        
        endTime = System.nanoTime();
        System.out.println("Total Execution Time: " + (endTime-startTime) );
        return false;

    }








}












