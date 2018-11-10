    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/10/2018                                               !
    !                                                                            #
    #          Test2 - Question 1                                                !
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


        Write a method first() that creates two priority queues, {"Pineapple", "Pear", "Quamquat", 
        "Grape", "Dragon Fruit", "Boysenberries"} and {"Pineapple", "Cantaloupe", "Dragon Fruit", 
        "Blueberries", "Pomegrante"}. Add to the first list a green skin fruit. Add your favorite fruit 
        to the second list. Display their union, difference, and intersection. Note that priority queue 
        can have duplicates. The union of two prority queues may have duplicates.



        
*/

import java.util.*;


public class Test21 {




    public static void main(String[] args) {
        
        



    }



    public void first() {
        
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
            System.out.println(it1.next());
        }

        System.out.println("Priority Queue 2\n---------------------------------");
        while (it2.hasNext()) {
            System.out.println(it2.next());
        }

    }



}
