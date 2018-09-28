    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           9/28/2018                                                !
    !                                                                            #
    #          LAB 3 - The Complex  Class                                        !
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


        MATH: The Complex Class:
        
        A complex number is a number in the form a + bi,
        where a and b are real numbers and i is 2 -1. The numbers a and b are known
        as the real part and imaginary part of the complex number, respectively. You can
        perform addition, subtraction, multiplication, and division for complex numbers
        using the following formulas:

              a + bi + c + di = (a + c) + (b + d)i
              a + bi - (c + di) = (a - c) + (b - d)i
              (a + bi)*(c + di) = (ac - bd) + (bc + ad)i
              (a + bi)/(c + di) = (ac + bd)/(c^2 + d^2) + (bc - ad)i/(c^2 + d^2)

        You can also obtain the absolute value for a complex number using the following
        formula:


                    | a + b(i) | = sqrt(a^2 + b^2) 

        (A complex number can be interpreted as a point on a plane by identifying the (a,b)
        values as the coordinates of the point. The absolute value of the complex number
        corresponds to the distance of the point to the origin, as shown in Figure 13.10b.)

        Design a class named Complex for representing complex numbers and the
        methods add, subtract, multiply, divide, and abs for performing complex-
        number operations, and override toString method for returning a string repre-
        sentation for a complex number. The toString method returns (a + bi) as a
        string. If b is 0, it simply returns a. Your Complex class should also implement the
        Cloneable interface.

        Provide three constructors Complex(a, b), Complex(a), and Complex().
        Complex() creates a Complex object for number 0 and Complex(a) cre-
        ates a Complex object with 0 for b. Also provide the getRealPart() and
        getImaginaryPart() methods for returning the real and imaginary part of the
        complex number, respectively.

        Write a test program that prompts the user to enter two complex numbers and
        displays the result of their addition, subtraction, multiplication, division, and abso-
        lute value. Here is a sample run:
    
    
            Enter the first complex number: 3.5 5.5
            Enter the second complex number: -3.5 1
                
                (3.5 + 5.5i) + (-3.5 + 1.0i) = 0.0 + 6.5i
                (3.5 + 5.5i) - (-3.5 + 1.0i) = 7.0 + 4.5i
                (3.5 + 5.5i) * (-3.5 + 1.0i) = -17.75 + -13.75i
                (3.5 + 5.5i) / (-3.5 + 1.0i) = -0.5094 + -1.7i
                |(3.5 + 5.5i)| = 6.519202405202649




*/



import java.lang.Math;

public class Complex {

    private double a,b;

 
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    /* * * * * * * * * * * * * * * * * * * * |
    /                                       /|
    /   All constructors + overloads for    /|
    /   Complex class go here               /|
    /                                       /|
    /* * * * * * * * * * * * * * * * * * * * |
    *///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    public Complex() { this.a = this.b = 0;}

    /*
     * @params:
     *      x : a of (a + bi)
     */

    public Complex(double x) {
        this.a = x;
        this.b = 0;
    }



    /*
     * @params:
     *      x : a of (a + bi)
     *      y : b of (a + bi)
     */

    public Complex(double x, double y) {
        this.a = x;
        this.b = y;
    }












