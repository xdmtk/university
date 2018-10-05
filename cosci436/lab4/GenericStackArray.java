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
            System.out.println("Element left was: " + o);
        }
        System.out.println("Is stack empty:" + test.isEmpty());
    }











    // Base size for object creation set at arbitrary value
    // of 10
    private final int DEFAULT_SIZE = 10;

    // Setting up type Object array variable to placehold
    // for generic array creation and assignment
    private Object[] stack;

    // Markers for the psuedo-'stack pointer' and the 
    // current maximum size of the stack object
    private int maxSize;
    private int currentSize;


    public GenericStackArray() {

        // Constructor creates object with default value 
        // of 10, and the psuedo'stack-pointer' set to 0
        this.stack = new Object[DEFAULT_SIZE];
        this.maxSize = DEFAULT_SIZE;
        this.currentSize = 0;
    }

    /* Returns the current index of the stack pointer,
    * which will be set according to how many push()/pop()
    *  calls have been made
    */
    public int getSize() {
        return this.currentSize;
    }
    

    // Returns the top element of the array, indicated
    // by the psuedo stack pointer
    public Object peek() {
        return this.stack[this.currentSize];
    }
   

    // Returns the element at the index and
    // decrements the psuedo stackpointer
    public Object pop() {
        return this.stack[this.currentSize--];
    }


    /* This push function makes two initial checks, 
     *  1. To check whether the array is full, by examing the current  
     *      index of the stackpointer and the current maximum size of the
     *      array.
     * 
     *  2. And checks whether the incoming object is of the 
     *      correct type of the given objects stack array
     *      member
     */

    public void push(E obj) {
        if ((this.getSize()+1) != this.maxSize) {

            // If the above conditions are met, push the object
            // onto the generic stack
            this.stack[++this.currentSize] = obj;
        }
        else {

            // First double the current maximum size of the stack
            this.maxSize *= 2;

            // Next clone the original stack object
            Object[] tempStack = this.stack.clone();

            // Then assign a new object array to the class member
            // stack array
            this.stack = new Object[maxSize];

            // Copy the elements from the cloned array
            for (int i = 0; i < (this.maxSize/2); i++) {
                this.stack[i] = tempStack[i];
                this.currentSize = i;
            }
            // Set the stack pointer to the last index
            

            // Then push the element like normal
            this.stack[++this.currentSize] = obj;
        }
    }


    @Override




        









}

