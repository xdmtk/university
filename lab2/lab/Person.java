
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



           Create sub class: Student and Staff - of Person

           Create sub class: Administration and Faculty - of Staff

                enum Status: Registered, Enrolled, InActive and Archived
                
                Student extends Person
                    Status status
                    -- other relevant methods. 
                    -- use super
                
                Staff extends Person
                double salary
                    Date hiredate
                    -- Constructor(s) - using super
                    -- setters and getters
                    -- toString()
                
                Administrator extends Staff
                    String position
                    String dept
                    -- Constructor(s) - using super
                    -- setters and getters
                    -- toString()
                
                Faculty extends Staff
                    ArrayList courses
                    -- Constructor(s) - using super
                    - setters and getters
                    -- toString()



*/

import java.util.Date;
import java.util.ArrayList;


public class Person {



    // Class variables
    private Name name;
    private int id;
    private  Address address;
    private String phoneNumber;

    
    // Class enumeration 
    public enum Status {
        Registered, Enrolled, InActive, Archived;
    }
    
   
    // Parameter-less constructor
    public Person() {
        System.out.println("This constructor is being called with no arguments");
    }

    // Constructor to set all instance variables
    public Person(Name n, int id, Address a, String p) {
    
        this.name = n;
        this.id = id;
        this.address = a;
        this.phoneNumber = p;

    }


    






   
    
   // Main method to test out all classes 
   public static void main(String[] args) {


        // Setting up name and address objects
        Name myName = new Name("Nick", "Martinez");
        Address myAddress = new Address(); 


        // Setting up composite object consisting of name and address objects
        Person myPerson = new Person(myName, 9999, myAddress, "818-999-9999");

        // Setting myStudent with constructor args of status and if he has done homework
        Student myStudent = new Student(Status.Registered, true);

        // Setting up Staff object with blank constructor but setting using class methods
        Staff myStaff = new Staff();

        // Creating a Date object to send to myStaff for get method
        Date myDate = new Date();

        // Using 'safer' setter method
        if (myStaff.setHireDate(myDate)) {
        System.out.println("Hire date set");
        } 
        else {
        System.out.println("Hire date failed to set");
        }


        // Setting administrator properties
        Administrator myAdmin = new Administrator();
        myAdmin.setPosition("Director Of Operations");

        myAdmin.setDept("Human Resources");


        // Setting administrators   
        Faculty myFaculty = new Faculty();

        ArrayList<String> myAL = new ArrayList<String>();
        myFaculty.setCourses(myAL);


    }

    
        








    // This is the method to be called from sub-classes using 'super' keyword
    public void overridenMethod() {
    
        System.out.print("This method of the Person class is being called with the super");
        System.out.print(" keyword from a subclass of the Person class\n");

        return;

    }





}



