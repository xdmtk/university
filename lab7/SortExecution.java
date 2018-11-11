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
         

        SAMPLE OUTPUT:


            └─ $ ▶ java SortExecution 
            QuickSort Algorithm on 50000 elements
            ------------------------------------------------

            Trial 1 - Execution time: 16893167
            Trial 2 - Execution time: 11687327
            Trial 3 - Execution time: 10270868
            Trial 4 - Execution time: 10240783
            Trial 5 - Execution time: 11894012

            -> Average exeution time for QuickSort Algorithm on 50000 elements: 12197231



            QuickSort Algorithm on 100000 elements
            ------------------------------------------------

            Trial 1 - Execution time: 21683682
            Trial 2 - Execution time: 23238403
            Trial 3 - Execution time: 22615259
            Trial 4 - Execution time: 22218576
            Trial 5 - Execution time: 22415118

            -> Average exeution time for QuickSort Algorithm on 100000 elements: 22434207



            QuickSort Algorithm on 150000 elements
            ------------------------------------------------

            Trial 1 - Execution time: 34892178
            Trial 2 - Execution time: 33598847
            Trial 3 - Execution time: 34471787
            Trial 4 - Execution time: 34943795
            Trial 5 - Execution time: 34587946

            -> Average exeution time for QuickSort Algorithm on 150000 elements: 34498910



            QuickSort Algorithm on 200000 elements
            ------------------------------------------------

            Trial 1 - Execution time: 51871560
            Trial 2 - Execution time: 46288448
            Trial 3 - Execution time: 45431604
            Trial 4 - Execution time: 46103804
            Trial 5 - Execution time: 46334363

            -> Average exeution time for QuickSort Algorithm on 200000 elements: 47205955



            QuickSort Algorithm on 250000 elements
            ------------------------------------------------

            Trial 1 - Execution time: 57860944
            Trial 2 - Execution time: 57158346
            Trial 3 - Execution time: 57484411
            Trial 4 - Execution time: 57013168
            Trial 5 - Execution time: 57451514

            -> Average exeution time for QuickSort Algorithm on 250000 elements: 57393676



            QuickSort Algorithm on 300000 elements
            ------------------------------------------------

            Trial 1 - Execution time: 68646372
            Trial 2 - Execution time: 67532898
            Trial 3 - Execution time: 70098561
            Trial 4 - Execution time: 68053311
            Trial 5 - Execution time: 68207363

            -> Average exeution time for QuickSort Algorithm on 300000 elements: 68507701




        
*/

import java.util.Random;

public class SortExecution {




    public static void main(String[] args) {

        long sortAvg, currentSort, qSortTotal, mrgSortTotal, bubSortTotal, insSortTotal;
        sortAvg = currentSort = qSortTotal = mrgSortTotal = bubSortTotal = insSortTotal = 0;

        // Generate new object
        SortExecution s = new SortExecution();
        

        // NOTE: Because I'm implementing the additional algorithms and execs times
        // quick and dirty, the code may a little longer than necessary


        //////////////////////////////////////////////////////
        ////
        //
        //      QuickSort Execution Times
        //
        //
        ////
        //////////////////////////////////////////////////////


        // Begin executing tests on input
        for (int quantity = 50000; quantity <= 300000; quantity += 50000) {
       
            // Generate new array with given size
            int[] list = new int[quantity];
            
            System.out.println("QuickSort Algorithm on " + quantity + " elements");
            System.out.println("------------------------------------------------\n");
            sortAvg=0;
            for (int x=0; x<5; ++x) {

                // Generate random data
                s.generateData(list,quantity);
               
                // Get execution time for current round
                currentSort = s.myQuickSort(list,0,quantity-1);

                // Show execution time for current round
                System.out.println("\tTrial " + (x+1) + " - Execution time: " + currentSort);
               
                // Add to averages
                sortAvg += currentSort;

                qSortTotal = sortAvg/5;
            }
            System.out.println("\n\t-> Average exeution time for QuickSort Algorithm on " + quantity
                + " elements: " + qSortTotal + "\n\n\n");

        }







        //////////////////////////////////////////////////////
        ////
        //
        //      MergeSort Execution Times
        //
        //
        ////
        //////////////////////////////////////////////////////



        // Begin executing tests on input
        for (int quantity = 50000; quantity <= 300000; quantity += 50000) {
       
            // Generate new array with given size
            int[] list = new int[quantity];
            
            System.out.println("MergeSort Algorithm on " + quantity + " elements");
            System.out.println("------------------------------------------------\n");
            sortAvg=0;
            for (int x=0; x<5; ++x) {

                // Generate random data
                s.generateData(list,quantity);
               
                // Get execution time for current round
                currentSort = s.mergeSort(list);

                // Show execution time for current round
                System.out.println("\tTrial " + (x+1) + " - Execution time: " + currentSort);
               
                // Add to averages
                sortAvg += currentSort;
                mrgSortTotal = sortAvg/5;
            }
            System.out.println("\n\t-> Average exeution time for MergeSort Algorithm on " + quantity
                + " elements: " + mrgSortTotal + "\n\n\n");

        }



        //////////////////////////////////////////////////////
        ////
        //
        //        BubbleSort Execution Times
        //
        //
        ////
        //////////////////////////////////////////////////////




        // Begin executing tests on input
        for (int quantity = 50000; quantity <= 300000; quantity += 50000) {
       
            // Generate new array with given size
            int[] list = new int[quantity];
            
            System.out.println("BubbleSort Algorithm on " + quantity + " elements");
            System.out.println("------------------------------------------------\n");
            sortAvg=0;
            for (int x=0; x<5; ++x) {

                // Generate random data
                s.generateData(list,quantity);
               
                // Get execution time for current round
                currentSort = s.bubbleSort(list);

                // Show execution time for current round
                System.out.println("\tTrial " + (x+1) + " - Execution time: " + currentSort);
               
                // Add to averages
                sortAvg += currentSort;
                bubSortTotal = sortAvg/5;
            }
            System.out.println("\n\t-> Average exeution time for BubbleSort Algorithm on " + quantity
                + " elements: " + bubSortTotal + "\n\n\n");

        }






        //////////////////////////////////////////////////////
        ////
        //
        //        InsertionSort Execution Times
        //
        //
        ////
        //////////////////////////////////////////////////////




        // Begin executing tests on input
        for (int quantity = 50000; quantity <= 300000; quantity += 50000) {
       
            // Generate new array with given size
            int[] list = new int[quantity];
            
            System.out.println("InsertionSort Algorithm on " + quantity + " elements");
            System.out.println("------------------------------------------------\n");
            sortAvg=0;
            for (int x=0; x<5; ++x) {

                // Generate random data
                s.generateData(list,quantity);
               
                // Get execution time for current round
                currentSort = s.insertionSort(list);

                // Show execution time for current round
                System.out.println("\tTrial " + (x+1) + " - Execution time: " + currentSort);
               
                // Add to averages
                sortAvg += currentSort;
                insSortTotal = sortAvg/5;
            }
            System.out.println("\n\t-> Average exeution time for InsertionSort Algorithm on " + quantity
                + " elements: " + insSortTotal + "\n\n\n");

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



    public long insertionSort(int[] list) {

        long startTime, endTime, execTime;
        startTime = System.nanoTime();
        
        
        for (int i = 1; i < list.length; i++) {
            /** Insert list[i] into a sorted sublist list[0..i-1] so that
            list[0..i] is sorted. */
            int currentElement = list[i];
            int k;
            for (k = i - 1; k >= 0 && list[k] > currentElement; k--) {
                list[k + 1] = list[k];
            }
            // Insert the current element into list[k + 1]
            list[k + 1] = currentElement;
        }


        // Calculate total exec time
        endTime = System.nanoTime();
        execTime = endTime - startTime;

        return execTime;



    }

    public long bubbleSort(int[] list) {
        long startTime, endTime, execTime;
        startTime = System.nanoTime();
        
        
        boolean needNextPass = true;
        for (int k = 1; k < list.length && needNextPass; k++) {
            // Array may be sorted and next pass not needed
            needNextPass = false;
            for (int i = 0; i < list.length - k; i++) {
                if (list[i] > list[i + 1]) {
                    // Swap list[i] with list[i + 1]
                    int temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    needNextPass = true; // Next pass still needed
                }
            }
        }
        endTime = System.nanoTime();
        execTime = endTime - startTime;

        return execTime;
    }

    /** Merge two sorted lists */
    public static void merge(int[] list1, int[] list2, int[] temp) {
        int current1 = 0; // Current
        int current2 = 0; // Current
        int current3 = 0; // Current
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


    public long mergeSort(int[] list) {
        long startTime, endTime, execTime;
        startTime = System.nanoTime();



       if (list.length > 1) {
           // Merge sort the first half
           int[] firstHalf = new int[list.length / 2];
           System.arraycopy(list, 0, firstHalf, 0, list.length / 2);
           mergeSort(firstHalf);
           // Merge sort the second half
           int secondHalfLength = list.length - list.length / 2;
           int[] secondHalf = new int[secondHalfLength];
           System.arraycopy(list, list.length / 2,
           secondHalf, 0, secondHalfLength);
           mergeSort(secondHalf);
           // Merge firstHalf with secondHalf into list
           merge(firstHalf, secondHalf, list);
       }
        endTime = System.nanoTime();
        execTime = endTime - startTime;

        return execTime;
    }










}












