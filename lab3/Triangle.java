    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           9/28/2018                                                !
    !                                                                            #
    #          LAB 3 - The Triangle Class                                        !
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


            Upload the Triangle class created during lecture.
            


            ** NOTE: Compiles but with a couple warnings about unused variables
*/



import java.lang.Math;
import java.util.Scanner;

public class Triangle  {

    // Required class data members
    private double side1;
    private double side2;
    private double side3;
    private String color;
    private boolean filled;

    
    
    // Some extras for special implementations 
    private double base;
    private double height;
    
    private static Scanner scanner = new Scanner(System.in);
    
    private double theta1;
    private double theta2;
    private double theta3;



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
        System.out.println("Color: " + this.color);
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

    public double getSide1() { return this.side1; };
    public double getSide2() { return this.side2; };
    public double getSide3() { return this.side3; };








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
       
       int choice;
       System.out.println("\n\nWhich side would you like to set as the base?");
        
        System.out.println("----------------------------------------");
        System.out.println("Side 1: "  + this.side1);
        System.out.println("Side 2: " + this.side2);
        System.out.println("Side 3: " + this.side3);


        System.out.println("\n\n\nEnter 1,2, or 3\n");
        
        try {

            // Gets base choice from user using scanner and nextDouble()
            // method from scanner class
            choice = scanner.nextInt();

            // Shows user choice of base made
            System.out.print("The base you chose for this Triangle object is ");

            // Sets choice to the chosen side for base
            switch (choice) {
                case 1: 
                    this.base = this.side1;
                    return this.base;
                case 2: 
                    this.base = this.side2;
                    return this.base;
                case 3:
                    this.base = this.side3;
                    return this.base;


                // Unless choice wasn't a listed option
                default: 
                    System.out.println("Sorry, the input you entered was not valid");
                    // Return -1 on error
                    return -1;
                    
            }

        }

        /* If user fails to enter a value that can be parsed as a double
           catch the exception thrown by nextDouble() and alert user
           of invalid choice
        */

        catch (Exception e) {
            System.out.println("Sorry, the input you entered was not valid");

            // Return -1 on error
            return -1;
        }
        
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
        
        // In order to get the heigh of the triangle, the base must be set and two sides must be set
        if ( (this.base == 0) || (this.side1 == 0) || (this.side2 == 0) || (this.side3 == 0) ){
            System.out.print("You must set the base side of the Triangle before you can get ");
            System.out.println("the height!");
            
            // Return -1 on error
            return -1;
        }
       




        double thetaSide, thetaHeight, sideSide, sideHeight;

        // Use law of cosines to find theta's
        this.theta1 = Math.acos(    (( ((Math.pow(this.side2,2)) + (Math.pow(this.side3,2))) - (Math.pow(this.side1,2))))/(2*this.side2*this.side3)   );
        this.theta2 = Math.acos(    (( ((Math.pow(this.side3,2)) + (Math.pow(this.side1,2))) - (Math.pow(this.side2,2))))/(2*this.side3*this.side1)   );
        this.theta3 = Math.acos(    (( ((Math.pow(this.side1,2)) + (Math.pow(this.side2,2))) - (Math.pow(this.side3,2))))/(2*this.side1*this.side2)   );

        
        // Figure out which side is the base
        if (this.base == this.side1) {
            thetaSide = this.theta2;
            thetaHeight = this.theta3;
            sideSide = this.side2;
            sideHeight = this.side3;

        }
        else if (this.base == this.side2) {
            thetaSide = this.theta1;
            thetaHeight = this.theta3;
            sideSide = this.side1;
            sideHeight = this.side3;
        }
        else {
            thetaSide = this.theta2;
            thetaHeight = this.theta1;
            sideSide = this.side2;
            sideHeight = this.side1;
        }

        // Use of law of sins to return the altitude
        this.height = Math.sin(thetaHeight)*sideSide;
        
        return this.height;

        

    }


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    /* * * * * * * * * * * * * * * * * * * * |
    /                                       /|
    /    The following are (or would be)    /| 
    /    overrides on functions from the    /|
    /    geometric object class, since all  /|
    /    geometric objects should have an   /|
    /    area and perimeter. The Geometric  /|
    /    object class, wont be delivered    /|
    /    with this assignment though, so    /|
    /    the overrides aren't true          /|
    /    overrides.                         /|
    /                                       /|
    /* * * * * * * * * * * * * * * * * * * * |
    *///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


    // @Override
    // These would be overrides if the class GeometricObject was included with the assignment
    public double getArea() {

        // In order to get the area of the Triangle, the base and height must be set
        if ( (this.base == 0) || (this.height == 0) ) {

            System.out.print("You must set the base and height of the Triangle before you can get ");
            System.out.println("the area!");
            return -1;
        }


        return ((1/2)*(this.base)*(this.height));
    }

    // @Override
    // These would be overrides if the class GeometricObject was included with the assignment
    public double getPerimeter() {

        // In order to get the perimeter of the Triangle, all sides must be set
        if ( (this.side1 == 0) || (this.side2 == 0) || (this.side3 == 0) ){
        
            System.out.print("You must set the base and height of the Triangle before you can get ");
            System.out.println("the area!");
            return -1;
        }
        
        return (this.side1+this.side2+this.side3);
    }





    

}

