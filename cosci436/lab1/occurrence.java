
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






// Import to generate random numbers
import java.lang.Math;

// Import to use Map and HashMap class
import java.util.*;

// Import to format number padding
import java.lang.String.*;


public class occurrence {


    public static void main(String args[]) {

        // Instantiate new integer array
        int[] numbers = new int[1000];
        
        // Instantiate map class
        Map<Integer, Integer>occur = new HashMap<Integer,Integer>();



        // Populate the array
        populateNumArray(numbers);
        
        // Count occurances by key/value map pairings
        countOccur(numbers, occur);
       
        // Print the map
        printMap(occur);

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



    // Function to create key/value pairs between the numbers found in
    // the numbers array, and how many times they appear
    public static void countOccur(int numbers[], Map<Integer, Integer> occur) {

        for (int i=0; i < numbers.length; ++i) {    

            // Check if Map contains the current number in the array
            if (occur.containsKey(numbers[i]) ) {

                // If so, get the current value in the map (the amount of times
                // its already been seen) and add 1
                int val = occur.get(numbers[i]) + 1;

                // Then store back into map
                occur.put(numbers[i], val);
            }
            else {

                // If its the first time the number has been seen,
                // entry in map and put value as 1
                occur.put(numbers[i],1);
            }
        }



    }




    // Function to print out the key/value pairs of the map
    public static void printMap(Map<Integer, Integer> occur) {
       



        System.out.println("* * * * * * * * * * * * * * * * * *");

        // Set up a Map iterator using the Entry interface and the entrySet() method
        // of the map class
        for (Map.Entry<Integer, Integer> e : occur.entrySet()) {

            // Get the keys and values of the current iteration
            int key = e.getKey();
            int val = e.getValue();

            // Print them out in a table style
            System.out.print("*  Number: " + String.format("%02d", key));
            System.out.print("  -  Occurence: " + String.format("%02d", val));
            System.out.println("   *");
        } 

        System.out.println("* * * * * * * * * * * * * * * * * *");




    }


    


    



}




// Output 
/*
* * * * * * * * * * * * * * * * * *
*  Number: 01  -  Occurence: 11   *
*  Number: 02  -  Occurence: 13   *
*  Number: 03  -  Occurence: 10   *
*  Number: 04  -  Occurence: 08   *
*  Number: 05  -  Occurence: 13   *
*  Number: 06  -  Occurence: 07   *
*  Number: 07  -  Occurence: 09   *
*  Number: 08  -  Occurence: 10   *
*  Number: 09  -  Occurence: 09   *
*  Number: 10  -  Occurence: 15   *
*  Number: 11  -  Occurence: 09   *
*  Number: 12  -  Occurence: 06   *
*  Number: 13  -  Occurence: 07   *
*  Number: 14  -  Occurence: 10   *
*  Number: 15  -  Occurence: 06   *
*  Number: 16  -  Occurence: 11   *
*  Number: 17  -  Occurence: 12   *
*  Number: 18  -  Occurence: 12   *
*  Number: 19  -  Occurence: 06   *
*  Number: 20  -  Occurence: 11   *
*  Number: 21  -  Occurence: 09   *
*  Number: 22  -  Occurence: 13   *
*  Number: 23  -  Occurence: 04   *
*  Number: 24  -  Occurence: 08   *
*  Number: 25  -  Occurence: 03   *
*  Number: 26  -  Occurence: 09   *
*  Number: 27  -  Occurence: 12   *
*  Number: 28  -  Occurence: 10   *
*  Number: 29  -  Occurence: 08   *
*  Number: 30  -  Occurence: 08   *
*  Number: 31  -  Occurence: 09   *
*  Number: 32  -  Occurence: 17   *
*  Number: 33  -  Occurence: 08   *
*  Number: 34  -  Occurence: 17   *
*  Number: 35  -  Occurence: 15   *
*  Number: 36  -  Occurence: 10   *
*  Number: 37  -  Occurence: 06   *
*  Number: 38  -  Occurence: 13   *
*  Number: 39  -  Occurence: 12   *
*  Number: 40  -  Occurence: 09   *
*  Number: 41  -  Occurence: 08   *
*  Number: 42  -  Occurence: 11   *
*  Number: 43  -  Occurence: 09   *
*  Number: 44  -  Occurence: 10   *
*  Number: 45  -  Occurence: 13   *
*  Number: 46  -  Occurence: 10   *
*  Number: 47  -  Occurence: 09   *
*  Number: 48  -  Occurence: 06   *
*  Number: 49  -  Occurence: 09   *
*  Number: 50  -  Occurence: 11   *
*  Number: 51  -  Occurence: 04   *
*  Number: 52  -  Occurence: 10   *
*  Number: 53  -  Occurence: 13   *
*  Number: 54  -  Occurence: 07   *
*  Number: 55  -  Occurence: 05   *
*  Number: 56  -  Occurence: 21   *
*  Number: 57  -  Occurence: 09   *
*  Number: 58  -  Occurence: 08   *
*  Number: 59  -  Occurence: 08   *
*  Number: 60  -  Occurence: 10   *
*  Number: 61  -  Occurence: 11   *
*  Number: 62  -  Occurence: 09   *
*  Number: 63  -  Occurence: 09   *
*  Number: 64  -  Occurence: 10   *
*  Number: 65  -  Occurence: 11   *
*  Number: 66  -  Occurence: 14   *
*  Number: 67  -  Occurence: 07   *
*  Number: 68  -  Occurence: 09   *
*  Number: 69  -  Occurence: 08   *
*  Number: 70  -  Occurence: 10   *
*  Number: 71  -  Occurence: 11   *
*  Number: 72  -  Occurence: 12   *
*  Number: 73  -  Occurence: 17   *
*  Number: 74  -  Occurence: 07   *
*  Number: 75  -  Occurence: 10   *
*  Number: 76  -  Occurence: 15   *
*  Number: 77  -  Occurence: 16   *
*  Number: 78  -  Occurence: 06   *
*  Number: 79  -  Occurence: 11   *
*  Number: 80  -  Occurence: 09   *
*  Number: 81  -  Occurence: 07   *
*  Number: 82  -  Occurence: 05   *
*  Number: 83  -  Occurence: 15   *
*  Number: 84  -  Occurence: 07   *
*  Number: 85  -  Occurence: 09   *
*  Number: 86  -  Occurence: 09   *
*  Number: 87  -  Occurence: 15   *
*  Number: 88  -  Occurence: 15   *
*  Number: 89  -  Occurence: 08   *
*  Number: 90  -  Occurence: 08   *
*  Number: 91  -  Occurence: 12   *
*  Number: 92  -  Occurence: 14   *
*  Number: 93  -  Occurence: 11   *
*  Number: 94  -  Occurence: 09   *
*  Number: 95  -  Occurence: 11   *
*  Number: 96  -  Occurence: 10   *
*  Number: 97  -  Occurence: 16   *
*  Number: 98  -  Occurence: 09   *
*  Number: 99  -  Occurence: 12   *
* * * * * * * * * * * * * * * * * *
*/










