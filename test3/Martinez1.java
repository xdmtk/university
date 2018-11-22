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
       //Martinez1.questionThree();
       Martinez1.questionFour(q4list);



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





/* 

        Show the steps that merge sort takes when sorting the following list of 
        integers. Assume the list is to be sorted in the ascending order.


        Output of Question 4:

            xdmtk@DMT~/prog/fall2018/test3 (master)
            └─ $ ▶ java Martinez1 
            Test 3 - Question 4:
            ----------------------
            23 
            45 
            23 45 
            10 
            2 
            2 10 
            2 10 23 45 
            89 
            62 
            62 89 
            76 
            33 
            33 76 
            33 62 76 89 
            2 10 23 33 45 62 76 89 
            

        In this output you can view each step mergesort takes
        to get the values in ascending order

        Recursively splitting the array in half until single values are
        fed to the merge() function, which compare and sort them accordingly

        Each half goes through this process and are recursively 'merged' back
        together until all 'halves' have been merged back to the original array
        except they have been sorted

            
    */

    static boolean banner = false;
    static int[] q4list = new int[8];
    
    public static void questionFour(int[] q4list) {

        // Some hacky sorcery to set and display values only once
        if (!banner) {
            System.out.println("Test 3 - Question 4:\n----------------------");   
            q4list[0] = 23;
            q4list[1] = 45;
            q4list[2] = 10;
            q4list[3] = 2;
            q4list[4] = 89;
            q4list[5] = 62;
            q4list[6] = 76;
            q4list[7] = 33;
            banner = true;
        }


       if (q4list.length > 1) {
           
           // Merge sort the first half
           int[] firstHalf = new int[q4list.length / 2];
           System.arraycopy(q4list, 0, firstHalf, 0, q4list.length / 2);
           questionFour(firstHalf);
       
       
           // Merge sort the second half
           int secondHalfLength = q4list.length - q4list.length / 2;
           int[] secondHalf = new int[secondHalfLength];
           
           System.arraycopy(q4list, q4list.length / 2,
           secondHalf, 0, secondHalfLength);
           questionFour(secondHalf);
           
           
           // Merge firstHalf with secondHalf into list
           questionFourMerge(firstHalf, secondHalf, q4list);
       }
       // Print the sorted list
        for (int i = 0; i < q4list.length; i++) {
            System.out.print(q4list[i] + " ");
        }
    
        System.out.println("");
        


    }


    /** Merge two sorted lists */
    public static void questionFourMerge(int[] list1, int[] list2, int[] temp) {


        int current1, current2, current3;
        current1 = current2 = current3 = 0;


        while (current1 < list1.length && current2 < list2.length) {


            if (list1[current1] < list2[current2])
                temp[current3++] = list1[current1++];
            else
                temp[current3++] = list2[current2++];
        }

        while (current1 < list1.length)
            temp[current3++] = list1[current1++];

            while (current2 < list2.length)
                temp[current3++] = list2[current2++];
    }








/* 
        Output of Question 5:


            
    */
    
    public static void questionFive() {



    }

}














