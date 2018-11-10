    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           10/10/2018                                               !
    !                                                                            #
    #          LAB 7 - Sort Algorithm Execution Time                             !
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



   21.13 - Write a program that obtains the execution time of selection sort, bubble sort,
       merge sort, quick sort, and heap sort for input size 50,000, 100,000, 150,000, 200,000, 
       250,000, and 300,000. Your program should create data randomly and print a table as 
       shown in the following sample run (note the array size should be as specified, 
       not as shown in the example)
         




        
*/

import java.util.Random;

public class SortExecution {




    public static void main(String[] args) {

        // Just a test main fuction, will revise later

        int quantity = 100;
        int[] list = new int[quantity];

        SortExecution s = new SortExecution();
        s.generateData(list,quantity);
        s.myQuickSort(list,0,quantity-1);

        int c=0;

        while (c < quantity) {
            System.out.println(list[c++]);
        }


        return;

    }





    // Function to generate random integers to be stored in the supplied array
    public void generateData(int[] list, int quantity) {

        Random r = new Random();
        int c = 0;

        while (c < quantity) {
            list[c++] = r.nextInt();
        }


    }








    // The quicksort function's heavy lifting is done in the parition() function
    // This function serves as a recursive caller to the partition function
    // giving the maximum amount of subsets of the array to be sorted to the partition function
    //
    // This function also keeps track of the total execution time of the algorithm
    //

    public long myQuickSort(int[] list, int first, int last) {


        // Set timers
        long startTime, endTime, execTime;
        startTime = System.nanoTime();

        // Since calls to this function will be recursive, based on the continous 
        // updates on the index of the pivot number, this condition ( last > first ) 
        // will eventually fail when the subset cannot be further split into more arrays
        //

        if (last > first) {
            int pivotIndex = partition(list, first, last);
            myQuickSort(list, first, pivotIndex - 1);
            myQuickSort(list, pivotIndex + 1, last);
        } 


        // Calculate total exec time
        endTime = System.nanoTime();
        execTime = endTime - startTime;

        return execTime;
    }




    /*  Partition function - This function is recursively called
    *  by `myQuickSort()`, which returns the index to split the array.
    *
    *  Essentially, an arbitray pivot point is chosen, ( in this case it's
    *  the first element of the array ) and the two search indices 'high' and 'low'
    *  begin comparing numbers against the pivot.
    *
    *  The idea of quick sort is to move all elements less than the pivot number
    *  to the left of the array, and all elements greater than the pivot to the right
    *  of the array. 
    *
    *  The index at which the final swap is made, is returned by the function as the index
    *  where the numbers greater and less than the pivot number, and is used in `myQuickSort()`
    *  as the point in which to split the array, and perform the partition() ( again ) , on both
    *  sides, choosing another pivot point and moving the elements left and right again, until
    *  the subsets of the arrays become only a 2 element array which is swapped appropriately.
    *
    *  The subsets when put back together ( no new arrays are actually created, only the index
    *  values are used as starting and stopping points ) , will have all of the lesser elements 
    *  ascending from the left, and all the greater elements descending from the right.
    *
    *  The array is now sorted
    *
    *  @params
    *      int[] list - The array to be sorted
    *      int first - The starting index of the array
    *      int last - The ending index of the array
    *
    *
    */ 
    public int partition(int[] list, int first, int last) {

        // Set pivot as first element - Pivot point is arbitrary
        int pivot = list[first];

        // Set index for forward search to next element after pivot
        int low = first + 1;

        // Set index for backward search, last element in array
        int high = last;



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
        *
        * When the swap is completed, the new pivot index for the next recursive round
        * of partitioning is returned to the `myQuickSort()` function, and uses that 
        * as its 'divide and conquer' index to begin sorting each subset (half) of the whole
        * array independantly, until all possible halves of the array have been sorted
        */

        if (pivot > list[high]) {
            list[first] = list[high];
            list[high] = pivot;
            return high;
        }

        // If the swap wasn't necessary, meaning the pivot was really the lowest
        // number in the list, then the first element index is returned instead,
        // since that would be the dividing boundary for the next round of sorting
        else {
            return first;
        }
    }

}












