    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/10/2018                                               !
    !                                                                            #
    #          Test2 - Question 2                                                !
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


        Create a method Second(), that modifies the first(), to print the list of fruits beginning with letter b.


        
*/

import java.util.*;


public class Test22 {




    public static void main(String[] args) {
        
        Test22 foo = new Test22();
        foo.second();



    }



    public void second() {
        
        PriorityQueue<String> pq1 = new PriorityQueue<String>();
        PriorityQueue<String> pq2 = new PriorityQueue<String>();


        /////////////////////////////////////
        // Create two priorities queues and add requested elements



        pq1.add("Pineapple");
        pq1.add("Pear");
        pq1.add("Quamquat");
        pq1.add("Grape");
        pq1.add("Dragonfruit");
        pq1.add("Boysenberries");

        pq2.add("Pineapple");
        pq2.add("Cantaloupe");
        pq2.add("Dragonfruit");
        pq2.add("Blueberries");
        pq2.add("Pomegranite");

        /////////////////////////////////////
        // Add green skin fruit to list 1
        // And favorite fruit to list 2

        pq1.add("Mango");
        pq2.add("Watermelon");













        // Display union of two prioriy queues
        
        Iterator<String> it1 = pq1.iterator();
        Iterator<String> it2 = pq2.iterator();

        System.out.println("Priority Queue 1\n---------------------------------");
        while (it1.hasNext()) {

            String n = it1.next();
            
            if (( n.toLowerCase().charAt(0) == 'b')) {
                System.out.println(n);
            }
        }

        System.out.println("\n\n");
        System.out.println("Priority Queue 2\n---------------------------------");
        while (it2.hasNext()) {
            String n = it2.next();
            
            if (( n.toLowerCase().charAt(0) == 'b')) {
                System.out.println(n);
            }
        }

        System.out.println("\n\n");

       












        //////////////////////////////////////////////
        // Display difference of two prioriy queues


        it1 = pq1.iterator();
        it2 = pq2.iterator();

        System.out.println("Priority Queue 1 Difference");
        System.out.println("( Elements in PQ1 not contained in PQ2 )");
        System.out.println("----------------------------------------\n");
        
        do{

            String n = it1.next();
            
            if (!pq2.contains(n) && ( n.toLowerCase().charAt(0) == 'b')) {
                System.out.println(n);
            }

        } while (it1.hasNext());
        System.out.println("\n\n");


        System.out.println("Priority Queue 2 Difference");
        System.out.println("( Elements in PQ2 not contained in PQ1 )");
        System.out.println("----------------------------------------\n");
        
        do  {

            String n = it2.next();
            
            if (!pq1.contains(n) && ( n.toLowerCase().charAt(0) == 'b')) {
                System.out.println(n);
            }

        } while (it1.hasNext());
        System.out.println("\n\n");












        //////////////////////////////////////////////
        // Display intersection of two prioriy queues


        it1 = pq1.iterator();
        it2 = pq2.iterator();

        System.out.println("Priority Queue 1  and 2 Intersection");
        System.out.println("( Elements in both PQ1 and PQ2 )");
        System.out.println("----------------------------------------\n");
        
        while (it1.hasNext()) {

            String n = it1.next();
            
            if (pq2.contains(n)  && ( n.toLowerCase().charAt(0) == 'b')) {
                System.out.println(n);
            }

        }

    }



}
