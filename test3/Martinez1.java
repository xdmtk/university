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
       
       Martinez1.questionTwo();



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


}
