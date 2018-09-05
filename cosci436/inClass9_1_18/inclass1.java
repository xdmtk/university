
    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           9/1/2018                                                 !
    !                                                                            #
    #          In Class 1 - Exercise 3.6 - Objected Orient BMI Calculator        !
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



    (Health application: BMI) Revise Listing 3.4:
        ComputeAndInterpretBMI.java

    Write a program to let the user enter weight, feet, and inches. For example, if a person is 5 feet and 10
    inches, you will enter 5 for feet and 10 for inches. Here is a sample run:


        Enter weight in pounds: 140
        Enter feet: 5
        Enter inches: 10
        BMI is 20.087702275404553
        Normal 







*/


import java.lang.Utils;
import java.io.BufferedReader;
import java.lang.String;




public class ComputeAndInterpretBMI {



    public static void main(String args[]) {







    }









    public static void getInput(

}


public class BMI extends ComputeAndInterpretBMI {


    private double weight;
    private int heightF;
    private int inches;
    
   
    // Constructor for BMI class opens an input prompt for the user
    // to store weight and height information
    public BMI() {
        
        BufferedReader reader = new BufferedReader();
        String input; 
        
        System.out.print("Enter weight: ");
        input = reader.readline();
        
        System.out.println(input);
        
        








    }







}

























