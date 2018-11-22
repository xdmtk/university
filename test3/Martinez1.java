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




        
*/

import java.util.*;


public class Martinez1 {




    public static void main(String[] args) {
       
       //Martinez1.questionTwo();
       Martinez1.questionThree();



    }




    /* 

        Perform selection sort for a list of integers. Assume the list 
        is to be sorted in the descending order. Show each of the steps in detail.

        Output of Question 2:
            
            xdmtk@DMT~/prog/fall2018/test3 (master)
            └─ $ ▶ java Martinez1 
            Test 3 - Question 1:
            ----------------------
            89 76 62 45 33 23 10 2 

            
    */


    public static void questionTwo() {

   
        // Generate new array with given size
        int[] list = new int[8];
        list[0] = 23;
        list[1] = 45;
        list[2] = 10;
        list[3] = 2;
        list[4] = 89;
        list[5] = 62;
        list[6] = 76;
        list[7] = 33;
       
        System.out.println("Test 3 - Question 2:\n----------------------");   
        
        
        // Begin insertion sort
        for (int i = 1; i < list.length; i++) {

            // Set counting index 'k' and current element value index 'currentElement'
            int currentElement = list[i];
            int k;

            // Notice 'i' starts at 1, this allows `k` to see 1 element behind 
            // for comparison against the current element `list[i]`
            for (k = i - 1; k >= 0 && list[k] < currentElement; k--) {

                // A swap occurs in this case for descending order, whether
                // the current element at index `k` (one behind `i`)
                // is less than the current element at `list[i]`
                list[k + 1] = list[k];
            }
            // Insert the current element into list[k + 1]
            list[k + 1] = currentElement;
        }

        

        // Print the sorted list
        for (int i = 0; i < list.length; i++) {
            System.out.print(list[i] + " ");
        }
    
        System.out.println("\n");

   
    
    }





    /* 

        Partition the following list of integers. Use the first element 
        of the array as the pivot.

        Output of Question 3:

            xdmtk@DMT~/prog/fall2018/test3 (master)
            └─ $ ▶ java Martinez1 
            Test 3 - Question 3:
            ----------------------
            10 23 33 2 45 62 76 89 


        Notice in this output, since we are using 45 as the pivot,
        and we are only going through one round of partitioning,
        we see all of the elements on the right of 45 are larger than
        45, and all elements to the left of 45 are less than 45

        If we recursively went through this partitioning function
        as the QuickSort algorithm  does, we would continue to 
        partition elements by halves until all subsets are sorted
            
    */


    public static void questionThree() {

        System.out.println("Test 3 - Question 3:\n----------------------");   
        int[] list = new int[8];
        list[0] = 45;
        list[1] = 23;
        list[2] = 89;
        list[3] = 2;
        list[4] = 10;
        list[5] = 62;
        list[6] = 76;
        list[7] = 33;

        int first = 0;
        // Set pivot as first element
        int pivot = list[first];
        // Set index for forward search to next element after pivot
        int low = first + 1;

        // Set index for backward search, last element in array
        int high = 7; int last = 7;



        // This while loop moves elements the left and right (swaps) 
        // based on whether the value at the given index is greater than
        // or less than the pivot 

        while (high > low) {


            /* While the low index doesn't run into the high index ( meaning there would be no more
            * values to sort ) and the element at the low index is less than the pivot ( meaning its
            * already on the left side of the array and doesnt need to be swapped ) , it will
            * continue to increment the low index until it either finds an element that is greater
            * than the pivot ( so it can be swapped with an element on the right that is lower than the pivot )
            * or the low and high indexes run into each other ( explained above) 
            */

            while (low <= high && list[low] <= pivot) {
                low++;
            }


            /*
            * The same process now happens but in reverse, finding the index of the element
            * from right to left, and stops at the index of the element that is less than the
            * pivot, meaning it needs to be swapped with the element found above, to the 
            * left side of the array
            */

            while (low <= high && list[high] > pivot) {
                high--;
            }


            /*
            * Once the two indices are set from the abobe two while loops, the following function
            * will swap the two values, moving the value that was greater than the pivot 
            * found by the `low` index and the value that was less than the pivot found by the
            * `high` index to their respective left and right sides. 
            * 
            *
            * Note this will only happen if both indices 'high' and 'low' have met the condition
            * that they have found numbers that meet the critea for swapping. 
            *
            * If they haven't met that critera, as seen by the logic above, the index `high` and
            * `index` low will run into eachother, and the following if condition will fail, and
            * not swap the elements.
            *
            */
            if (high > low) {

                // Classic XOR swap, no temp needed. 

                list[low] ^= list[high];
                list[high] ^= list[low];
                list[low] ^= list[high];
            }


        }


        /* Now once all the swaps have completed, which is indicated by the same condition
        * that stops the swapping process at line 201, we must swap the pivot into the appropriate place
        * as well, other wise our first element will be out of place
        */




        /* Now we pick up from where the `high` index left off in the swapping, which 
        * should be in the dead center of the array, and scans the remaining low entries
        * in the array whether they are less than the pivot number
        *
        * If they are, then it follows that the pivot number ( our first element ) needs 
        * to be moved to the right side of the left half of the array, since our right half
        * of the array is already sorted, since the pivot was not part of that half 
        *
        */

        while (high > first && list[high] >= pivot) {
            high--;
        }


        /* 
        * Once again using the same logic above to find the appropriate high index 
        * to swap with, the pivot is swapped and sorted
        *
        * But this is only completed if the pivot is actually greater
        * than the high index found
        */
            
        if (pivot > list[high]) {
            list[first] = list[high];
            list[high] = pivot;
        }


        // Print the sorted list
        for (int i = 0; i < list.length; i++) {
            System.out.print(list[i] + " ");
        }
    
        System.out.println("\n");
        



    }


}
