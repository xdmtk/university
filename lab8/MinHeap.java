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


        Sample output:
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "test"
            String 1: this is a test of the string matching algorithm
            String 2: test
            Matched at index: 10
            Total Execution Time: 114567
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "testf"
            String 1: this is a test of the string matching algorithm
            String 2: testf
            Total Execution Time: 6830
            No match
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "alg"
            String 1: this is a test of the string matching algorithm
            String 2: alg
            Matched at index: 38
            Total Execution Time: 70182
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "algbbbbb"
            String 1: this is a test of the string matching algorithm
            String 2: algbbbbb
            Total Execution Time: 10129
            No match
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "t"
            String 1: this is a test of the string matching algorithm
            String 2: t
            Matched at index: 1
            Total Execution Time: 63160
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "m"
            String 1: this is a test of the string matching algorithm
            String 2: m
            Matched at index: 29
            Total Execution Time: 57143
            String 2 is a substring of String 1
            
            xdmtk@DMT~/prog/fall2018/lab8 (master)
            └─ $ ▶ java PatternMatch "this is a test of the string matching algorithm" "z"
            String 1: this is a test of the string matching algorithm
            String 2: z
            Total Execution Time: 7764
            No match
            



*/


public class MinHeap {

}
