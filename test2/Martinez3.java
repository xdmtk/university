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


        Write a method third(), that creates two linked hash sets, {53, 42, 65, 91, 87, 65} and {65, 93, 42, 67, 87}. Add 
        your birthday day, to the first list. Add a number between 12 and 40 to the second list. Display their union, 
        difference, and intersection.

        Upload java source code named your Lastname.java (ex. Samplewala.java) and the run/result, fir the above 3 sub modules.

        
*/

import java.util.*;


public class Martinez3 {




    public static void main(String[] args) {
        
        Martinez3 foo = new Martinez3();
        foo.third();



    }



    public void third() {
        
        LinkedHashSet<Integer>  s1 = new LinkedHashSet<Integer>();
        LinkedHashSet<Integer>  s2 = new LinkedHashSet<Integer>();


        /////////////////////////////////////
        // Create two LinkedHashSet and add requested elements



        s1.add(53);
        s1.add(42);
        s1.add(65);
        s1.add(91);
        s1.add(87);
        s1.add(65);

        // Birthday 
        s1.add(471993);
        

        s2.add(65);
        s2.add(93);
        s2.add(42);
        s2.add(67);
        s2.add(87);
        s2.add(65);

        // Num between 12 and 40
        s2.add(35);













        // Display union of two LinkedHashSet
        
        Iterator<Integer> it1 = s1.iterator();
        Iterator<Integer> it2 = s2.iterator();

        System.out.println("LinkedHashSet 1\n---------------------------------");
        while (it1.hasNext()) {

            int n = it1.next();
            
            System.out.println(n);
        }

        System.out.println("\n\n");
        System.out.println("LinkedHashSet 2\n---------------------------------");
        while (it2.hasNext()) {
            int n = it2.next();
            
            System.out.println(n);
        }

        System.out.println("\n\n");

       












        //////////////////////////////////////////////
        // Display difference of two prioriy queues


        it1 = s1.iterator();
        it2 = s2.iterator();

        System.out.println("LinkedHashSet 1 Difference");
        System.out.println("( Elements in s1 not contained in s2 )");
        System.out.println("----------------------------------------\n");
        
        do{

            int n = it1.next();
            
            if (!s2.contains(n)) {
                System.out.println(n);
            }

        } while (it1.hasNext());
        System.out.println("\n\n");


        System.out.println("LinkedHashSet 2 Difference");
        System.out.println("( Elements in s2 not contained in s1 )");
        System.out.println("----------------------------------------\n");
        
        do  {

            int n = it2.next();
            
            if (!s1.contains(n)) {
                System.out.println(n);
            }

        } while (it2.hasNext());
        System.out.println("\n\n");












        //////////////////////////////////////////////
        // Display intersection of two prioriy queues


        it1 = s1.iterator();
        it2 = s2.iterator();

        System.out.println("LinkedHashSet 1  and 2 Intersection");
        System.out.println("( Elements in both s1 and s2 )");
        System.out.println("----------------------------------------\n");
        
        while (it1.hasNext()) {

            int n = it1.next();
            
            if (s2.contains(n)) {
                System.out.println(n);
            }

        }

    }



}
