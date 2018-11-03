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



public class SortExecution {

    public long myInsertionSort(int[] list) {
        long startTime, endTime, execTime;
        startTime = System.nanoTime();

        for (int i=1; i < list.length; ++i) {
            int currentElement = list[i];
            int k;
            for (k = i-1; k >= 0 && list[k] > currentElement; k--) {
                list[k+1] = list[k];
            }
            list[k+1] = currentElement;
        }

        endTime = System.nanoTime();
        execTime = endTime - startTime;
        
        return execTime;
    }


    public long myBubbleSort(int[] list) {
        long startTime, endTime, execTime;
        startTime = System.nanoTime();
    
        boolean needNextPass = true;
        for (int k=1; k < list.length && needNextPass; k++) {

            needNextPass = false;
            for (int i=0; i < list.length - k; i++) {
                if (list[i] > list[i+1]) {

                    // XOR swap
                    list[i] ^= list[i+1];
                    list[i+1] ^= list[i];
                    list[i] ^= list[i+1];

                    needNextPass = true;
                }
            }
        }
        endTime = System.nanoTime();
        execTime = endTime - startTime;
        
        return execTime;
    }


    public long myMergeSort(int[] list) {
            long startTime, endTime, execTime;
            startTime = System.nanoTime();
           
            if (list.length > 1) {
                int [] firstHalf = new int[list.length/2];
                System.arraycopy(list,0,firstHalf,0,list.length/2);
                mergeSort(firstHalf);

                int secondHalfLength = list.length - (list.length/2);
                int[] secondHalf = new int[secondHalfLength];

                System.arraycopy(list,list.length/2, secondHalf, 0 
                    secondHalfLength);
                mergeSort(secondHalf);

                merge(firstHalf,secondHalf,list);
            }

            
            endTime = System.nanoTime();
            execTime = endTime - startTime;
            
            return execTime;
        }


    public void myMerge(int[] list1, int[] list2, int[] temp) {
        int current1,current2,current3;
        current1 = current2 = current3 = 0;

        while (current1 < list1.length && current2 < list2.length) {
            if (list1[current1] < list2[current2]) {
                temp[current3++] = list1[current1++];
            }
            else {
                temp[current3++] = list2[current2++];
            }
        }

        while (current1 < list1.length) {
            temp[current3++] = list1[current1++];
        }

        while (current2 < list2.length) {
            temp[current3++] = list2[current2++];
        }


    }


    public long myQuickSort(int[] list, int first, int last) {
            long startTime, endTime, execTime;
            startTime = System.nanoTime();
                
            if (last > first) {
                int pivotIndex = partition(list, first, last);
                quickSort(list, first, pivotIndex - 1);
                quickSort(list, pivotIndex + 1, last);
            } 
            
            endTime = System.nanoTime();
            execTime = endTime - startTime;
            
            return execTime;
        }



        /** Partition the array list[first..last] */
        public int partition(int[] list, int first, int last) {
            int pivot = list[first]; // Choose the first element as the pivot
            int low = first + 1; // Index for forward search
            int high = last; // Index for backward search
            while (high > low) {
                // Search forward from left
                while (low <= high && list[low] <= pivot)
                    low++;
                    // Search backward from right
                    while (low <= high && list[high] > pivot)
                        high--;
                        // Swap two elements in the list
                        if (high > low) {
                            int temp = list[high];
                            list[high] = list[low];
                            list[low] = temp;
                        }
            }
            while (high > first && list[high] >= pivot)
                high--;
                // Swap pivot with list[high]
                if (pivot > list[high]) {
                    list[first] = list[high];
                    list[high] = pivot;
                    return high;
                }
                else {
                    return first;
                }
        }
    
}












}
