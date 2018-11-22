    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/21/2018                                               !
    !                                                                            #
    #          Test3 - Question 1                                                !
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




     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6
     THIS PORTION OF THE TEST CONTAINS SOURCE CODE FOR QUESTION 6




        I have a list of face values of 100 dice rolls. Since a dice has 6 face values: 
        1, 2, 3, 4, 5, 6 the list will only contain these six numbers. Can you make use
        of this fact, that the array will contain only numbers 1 through 6 to devise a 
        sorting alogrithm, to sort this list of 100 numbers?

        Hint: Counting the number of occurrences of those numbers may lead to a sorting algorithm. 

        (a) Device an algorithm to sort this list of 100 values.

        (b) Using Big O notation, what is the the efficiency of your algorithm.

        (c) Write the java code to implement the above algorithm.
                
*/

import java.util.*;
import java.util.Random;


public class Test3 {


    int[] diceRolls = new int[100];
    
    public static void main(String[] args) {

        Test3.setDiceRolls(diceRolls);       




    }


    public static void setDiceRolls(int[] dr) {
        Random r = new Random();
        int c = 0,
        int x;

        while (c < 100) {

            x = r.nextInt(6);
            if (x == 0) { ++x; }
            dr[c++] = x;

        }

    public static void printDiceRolls(int[] dr) {

        for (int i = 0; i < 100;) {
            for (int x = 0; x < 10; ++x) {
                System.out.print(dr[i++] + " ");
            }
            System.out.println("");
        }

    }


    }




}














