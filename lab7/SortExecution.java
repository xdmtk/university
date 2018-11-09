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

    public void generateData(int[] list, int quantity) {
    
        Random r = new Random();
        int c = 0;

        while (c < quantity) {
            list[c++] = r.nextInt();
        }


    }



    public long myQuickSort(int[] list, int first, int last) {
            long startTime, endTime, execTime;
            startTime = System.nanoTime();
                
            if (last > first) {
                int pivotIndex = partition(list, first, last);
                myQuickSort(list, first, pivotIndex - 1);
                myQuickSort(list, pivotIndex + 1, last);
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












