import java.io;
import java.util.Scanner;

public class Triangle extends GeometricObject {

    // Required class data members
    private double side1;
    private double side2;
    private double side3;
    private String color;
    private boolean filled;

    
    
    // Some extras for special implementations 
    private double base = null;
    private static Scanner scanner = new Scanner(System.in);




    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    /* * * * * * * * * * * * * * * * * * * * |
    /                                       /|
    /   All constructors + overloads for    /|
    /   triangle class go here              /|
    /                                       /|
    /* * * * * * * * * * * * * * * * * * * * |
    *///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


    // Default constructor for Triangle class
    public Triangle() {

        // Information to be printed about new instance of triangle class
        System.out.println("New default instance of triangle class spawned");
        System.out.println("----------------------------------------");
        System.out.println(this.toString());
    }

    public Triangle(double s1, double s2, double s3) {

        // Constructor overload setting side values from parameters
        this.side1 = s1;
        this.side2 = s2;
        this.side3 = s3;

        // Information to be printed about new instance of triangle class
        System.out.println("New instance of triangle class spawned");
        System.out.println("----------------------------------------");

        // With side information
        System.out.println("Side 1: "  + this.side1);
        System.out.println("Side 2: " + this.side2);
        System.out.println("Side 3: " + this.side3);
    }



    public Triangle(double s1, double s2, double s3, String col, boolean fill) {

        // Constructor overload setting side values from parameters
        // and color + filled status
        this.side1 = s1;
        this.side2 = s2;
        this.side3 = s3;
            
        this.color = col;
        this.filled = fill;

        // Information to be printed about new instance of triangle class
        System.out.println("New instance of triangle class spawned");
        System.out.println("----------------------------------------");

        // With side information + color and filled information
        System.out.println("Side 1: "  + this.side1);
        System.out.println("Side 2: " + this.side2);
        System.out.println("Side 3: " + this.side3);
        System.out.println("Color: " this.color);
        System.out.println("Filled: " + this.filled);

    }



    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    /* * * * * * * * * * * * * * * * * * * * |
    /                                       /|
    /   All get and set methods for         /|
    /   triangle class go here              /|
    /                                       /|
    /* * * * * * * * * * * * * * * * * * * * |
    *///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


    // Very simple get and sets 
    public void setSide1(double s1) { this.side1 = s1; }
    public void setSide2(double s2) { this.side2 = s2; }
    public void setSide3(double s3) { this.side3 = s3; }

    public double getSide1() { return this.side1 };
    public double getSide2() { return this.side2 };
    public double getSide3() { return this.side3 };








    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    /* * * * * * * * * * * * * * * * * * * * |
    /                                       /|
    /    The getBase() method allows the    /|
    /    user to select which set side      /|
    /      to use as the base               /|
    /                                       /|
    /* * * * * * * * * * * * * * * * * * * * |
    *///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    
    public double getBase() {
       
       double choice;
       System.out.println("\n\nWhich side would you like to set as the base?");
        
        System.out.println("----------------------------------------");
        System.out.println("Side 1: "  + this.side1);
        System.out.println("Side 2: " + this.side2);
        System.out.println("Side 3: " + this.side3);


        System.out.println("\n\n\nEnter 1,2, or 3\n");
        
        try {

            // Gets base choice from user using scanner and nextDouble()
            // method from scanner class
            choice = scanner.nextDouble();

            // Shows user choice of base made
            System.out.print("The base you chose for this Triangle object is ");

            // Sets choice to the chosen side for base
            switch (choice) {
                case 1: 
                    choice = this.side1;
                    break;
                case 2: 
                    choice = this.side2;
                    break;
                case 3:
                    choice = this.side3;
                    break;


                // Unless choice wasn't a listed option
                default: 
                    System.out.println("Sorry, the input you entered was not valid");
                    // Return -1 on error
                    return -1;
                    
            }
            System.out.println(choice);

        }

        /* If user fails to enter a value that can be parsed as a double
           catch the exception thrown by nextDouble() and alert user
           of invalid choice
        */

        catch (InputMismatchException e) {
            System.out.println("Sorry, the input you entered was not valid");

            // Return -1 on error
            return -1;
        }
        
        this.base = choice;
        return choice; 
    } 





    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    /* * * * * * * * * * * * * * * * * * * * |
    /                                       /|
    /    The getHeight() method calculates  /|
    /    the height of the triangle, given  /|
    /    the base is set. It also prompts   /|
    /    the user to enter theta's for      /|
    /    the triangle                       /|
    /                                       /|
    /* * * * * * * * * * * * * * * * * * * * |
    *///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    public double getHeight() {
        

        // In order to get the heigh of the triangle, the base must be set. 
        if (this.base == null) {
            System.out.print("You must set the base side of the Triangle before you can get ");
            System.out.println("the height!");
            
            // Return -1 on error
            return -1
        }













    }

}

