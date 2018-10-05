    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           10/4/2018                                                !
    !                                                                            #
    #          LAB 4 - Revising GenericStack class                               !
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



        19.1 (Revising Listing 19.1 (Links to an external site.)Links to an external site.) 
        Revise the GenericStack class in Listing 19.1 (Links to an external site.)
        Links to an external site. to implement it using an array rather than an ArrayList. 
        You should check the array size before adding a new element to the stack. 
        If the array is full, create a new array that doubles the current array size and 
        copy the elements from the current array to the new array.

        Use the following to test your code. And remember to insert the result as comments 
        at the end of your java source code.


            public static void main(String[] args){
                GenericStackArray<String> test = new GenericStackArray();
                System.out.println(test.toString());
                test.push("One");
                test.push("Two");
                test.push("Three");
                test.push("Four");
                System.out.println(test.toString());
                System.out.println("Size of stack: " + test.getSize());
                System.out.println("Top of stack: " + test.peek());
                String o = test.pop();
                System.out.println("After one Pop: \n" + test.toString());
                o = test.pop();
                o = test.pop();
                if (test.isEmpty()) { 
                    System.out.println("Is stack empty:" + test.isEmpty());}
                else {
                    o = test.pop(); 
                    System.out.println("Element left was: " + o);}
                System.out.println("Is stack empty:" + test.isEmpty());
            }





*/




public class GenericStackArray<E> {
    
    private final int DEFAULT_SIZE = 10;

    private Object[] stack;
    private int maxSize;
    private int currentSize;


    public GenericStackArray() {
        this.stack = new Object[DEFAULT_SIZE];
        this.maxSize = DEFAULT_SIZE;
        this.currentSize = 0;
    }


    public int getSize() {
        return this.currentSize;
    }
    
    public E peek() {
        return this.stack[this.currentSize];
    }
    
    public E pop() {
        return this.stack[this.currentSize--];
    }

    public void push(E obj) {
        if (((this.getSize()+1) != this.maxSize) && (obj instanceof E)) {
            this.stack[++this.currentSize] = obj;
        }
        else {
           Object[] tempStack = this.stack.clone();
           this.stack 




        









}

