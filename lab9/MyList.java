    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/30/2018                                               !
    !                                                                            #
    #          LAB 9 - Implementing List, Stacks Queues and Priority Queues      ! 
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

        Exercise 24.1:


        (Add set operations in MyList ) Define the following methods in MyList and
        implement them in MyAbstractList :
            
            
            /** Adds the elements in otherList to this list.
            * Returns true if this list changed as a result of the call *
           
               public boolean addAll(MyList<E> otherList);
            
            
            /** Removes all the elements in otherList from this list
            * Returns true if this list changed as a result of the call *
                public boolean removeAll(MyList<E> otherList);
            
            
            /** Retains the elements in this list that are also in otherList
            * Returns true if this list changed as a result of the call *
                public boolean retainAll(MyList<E> otherList);
            
            
            
            Write a test program that creates two MyArrayList s, list1 and list2 , with
            the initial values {"Tom", "George", "Peter", "Jean", "Jane"} and {"Tom", "George", "Michael", "Michelle", "Daniel"}
            then perform the following operations:
            
            ■ Recreates list1 and list2 with the same initial values, invokes
            ■ Invokes list1.addAll(list2) , and displays list1 and list2 .
                    list1.removeAll(list2) , and displays list1 and list2 .
            ■ Recreates list1 and list2 with the same initial values, invokes
                    list1.retainAll(list2) , and displays list1 and list2 .
        

*/
|import java.util.*;

public class MyList<E> extends MyArrayList<E> {

    private Object[] mlist = new Object[16];


    public static void main(String[] args) {

    }


    public MyList(Object[] init) {
        
        for 



    }


    /** Adds the elements in otherList to this list.
    * Returns true if this list changed as a result of the call */

    public boolean addAll(MyList<E> otherList) {
            
        int otherLen = otherList.mlist.length;
        if (otherLen == 0) {
            return false;
        }
        
        Object[] temp = new Object[mlist.length+otherLen];
        
        System.arraycopy(mlist,0,temp,0,mlist.length);


        System.arraycopy(otherList.mlist,0,temp,mlist.length,otherLen);
        mlist = temp;

        return true;
    }



    /** Removes all the elements in otherList from this list
    * Returns true if this list changed as a result of the call */
    
    public boolean removeAll(MyList<E> otherList) {

        int otherLen = otherList.mlist.length;
        if (otherLen == 0) {
            return false;
        }

        for (int i=0; i < mlist.length; ++i) {
            for (int x=0; x < otherList.mlist.length; ++x) {
                if (mlist[i] == otherList.mlist[x]) {
                    mlist[i] = null;
                }
            }
        }
        return true;
    }






    /** Retains the elements in this list that are also in otherList
    * Returns true if this list changed as a result of the call */
    
    public boolean retainAll(MyList<E> otherList) {

        int otherLen = otherList.mlist.length;
        if (otherLen == 0) {
            return false;
        }

        for (int i=0; i < mlist.length; ++i) {
            for (int x=0; x < otherList.mlist.length; ++x) {
                if (mlist[i] != otherList.mlist[x]) {
                    mlist[i] = null;
                }
            }
        }
        return true;

    }



    @Override
    public String toString() {
        System.out.print("\n");
        for (int i=0; i < mlist.length; ++i) {
            if (mlist[i] != null) {
                System.out.println(mlist[i]);
            }
        }
        System.out.print("\n");
        return "";
    }





}
    



    
