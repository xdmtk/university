
    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           8/28/2018                                                !
    !                                                                            #
    #          LAB 2 -  Classes/Inheritence                                      !
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


        Count occurence of numbers: 

           Create sub class: Student and Staff - of Person

           Create sub class: Administration and Faculty - of Staff




*/

import java.util.Date;

public class Staff extends Person {

    private Date hiredate;
    private double salary;
    
    public Staff() {

        // Constructor for Staff class
        super.overridenMethod(); 

    }



    // Getters and setters
    /*
     *
     *
     *
     */
    public boolean setHireDate(Date hd) {
       
        this.hiredate = hd;
        // Return true if assignment is sucessful
        if (this.hiredate == hd) {
            return true;
        }
        // Return false otherwise
        return false;
    }

    public Date getHireDate() {
        // Gets and returns the calling object's hiredate
        return this.hiredate;
    }



    public boolean setSalary(double s) {
       
        this.salary = s;
        // Return true if assignment is sucessful
        if (this.salary == s) {
            return true;
        }
        // Return false otherwise
        return false;
    }
    
    public double getSalary() {
        // Gets and returns the calling object's salary
        return this.salary;
    }


    // Overriding the object's toString method with a custom textual
    // representation of the object
    @Override
    public String toString() {

        return ("Hiredate: " + this.hiredate.toString() + "\n" + "Salary: " + this.salary);
    }



}
