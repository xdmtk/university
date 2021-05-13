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

CHECK        (a) Device an algorithm to sort this list of 100 values.

        (b) Using Big O notation, what is the the efficiency of your algorithm. 

                BIG 0 = n*log(n)

CHECK        (c) Write the java code to implement the above algorithm.




        OUTPUT 

            xdmtk@DMT~/prog/fall2018/test3 (master)
            └─ $ ▶ java Test3 w
            Dice Rolls before Sort
            3 3 4 4 4 1 2 3 1 1 
            6 3 4 6 3 6 1 3 4 2 
            3 6 1 1 2 5 3 4 1 4 
            2 1 6 2 1 2 2 2 1 1 
            5 6 6 5 5 4 1 6 1 1 
            5 4 5 4 1 1 1 6 5 6 
            4 4 1 2 5 6 5 5 1 3 
            6 1 5 1 1 2 1 1 3 3 
            6 2 1 4 5 5 1 4 4 4 
            1 4 1 6 3 1 5 4 6 2 
            Dice Rolls after Sort
            1 1 1 1 1 1 1 1 1 1 
            1 1 1 1 1 1 1 1 1 1 
            1 1 1 1 1 1 1 1 1 2 
            2 2 2 2 2 2 2 2 2 2 
            2 3 3 3 3 3 3 3 3 3 
            3 3 3 4 4 4 4 4 4 4 
            4 4 4 4 4 4 4 4 4 4 
            4 5 5 5 5 5 5 5 5 5 
            5 5 5 5 5 6 6 6 6 6 
            6 6 6 6 6 6 6 6 6 6 
                
*/

import java.util.*;
import java.util.Random;


public class Test3 {


    static int[] diceRolls = new int[100];
    
    public static void main(String[] args) {

        
        Test3.setDiceRolls(diceRolls);       

        System.out.println("Dice Rolls before Sort");
        Test3.printDiceRolls(diceRolls);


        Test3.sortDiceRolls(diceRolls);

        System.out.println("Dice Rolls after Sort");
        Test3.printDiceRolls(diceRolls);



    }


    public static void setDiceRolls(int[] dr) {
        Random r = new Random();
        int c = 0;
        int x;

        while (c < 100) {

            x = r.nextInt(7);
            if (x == 0) { ++x; }
            dr[c++] = x;

        }
    }

    public static void printDiceRolls(int[] dr) {

        for (int i = 0; i < 100;) {
            for (int x = 0; x < 10; ++x) {
                System.out.print(dr[i++] + " ");
            }
            System.out.println("");
        }

    }

    public static void sortDiceRolls(int[] dr) {
        int[] temp = new int[100];
        int x=0;
        int b=0;
        for (int i=1; i < 7; ++i) {
            int f = countFaceOccurence(dr, i);



            for (b=0 ; b < f && x < 100; b++, x++) {
                temp[x] = i;
            }
        }
        for (int p=0; p < 100; ++p) {
            dr[p] = temp[p];
        }
        return;


    }

    public static int  countFaceOccurence(int[] dr, int val) {
        int count = 0;
        for (int i=0; i < 100; ++i) {
            if (dr[i] == val) {
                count++;
            }
        }
        return count;



    }

}


















