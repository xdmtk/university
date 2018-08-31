
    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           8/28/2018                                                !
    !                                                                            #
    #          LAB 1 - Count occurence of numbers                                !
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


        Count occurence of numbers: 

            Write a program that reads the integers between 1 and 100 and counts the 
            occurrences of each. Assume the input ends with 0. Here is a sample run of
            the program.

            (You may choose to populate the array with randomly generated numbers
                between 1 to 100, rather than have a user enter the numbers )


*/







import java.lang.Math;
import java.util.Map;
import java.util.AbstractMap;

public class occurrence {

    public static Map<Integer,Integer> occur;

    public static void main(String args[]) {

        // Instantiate new integery array
        int[] numbers = new int[100];

        // Instantiate map class
        occur = new HashMap();

        // Populate that array
        populateNumArray(numbers);
       



    }










    // Function to populate an array of integers with random
    // numbers from 1 to 100
    public static void populateNumArray(int numbers[]) {
           

        // Iterate through length of array
        for (int i=0; i < numbers.length; ++i) {    
            
            /* Generate random number using Math.random()
             * multiplying by 100 and casting to integer, then
             * taking modulus 100 to get a number between 0 and 100
             * and continue to generate if number is 0, as to only include
             * numbers from 1 to 100
             */

            do {

                numbers[i] = ((int) (100 * Math.random()) % 100);

            } while (numbers[i] == 0);

        }
            
        return;

    }




    public static void countOccur(int numbers[], Map occur) {





    }






}

