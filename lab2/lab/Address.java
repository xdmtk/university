
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

    In class we create Name class


        Name:
            fields: String fName
            fields: String lName
            
            Constructor Name()
            Constructor Name(fName, lName)
            
            setFName(fName)
            getFName()
            setLName(lName)
            getLName()
           
            getName(): "FirstName LastName"
            getLastFirst(): "LastName, FirstName"
           
            toString(): String displays fName and lName

            Tested the Name class in 3 different ways
                
                main() -- 3 alternatives
                -- Within the Class
                -- Class Under the same Class
                -- Separate Class - TestName

            
            Created Array of Objects
                - declare, initialize and print

    In class we then created Address class


        Address
        
            -USA addresses
            String addressLine1
            String addressLine2

        Followed by creating a "composite" object


            Person -- composite object (Name and Address)
            Name name -- naming conventions for variables and methods
            int id
            Address address
            String phoneNumber
        
        
        
        Test by creating an object with no parameters - test1
            -an object with all parameters - test2
            -an object with only Name and int passed



*/




public class Address {

    private String addressLine1;
    private String addressLine2;



    public Address() {
        
        System.out.println("This is an Address constructor with no arguments");
        // Empty constructor....

    }

    

    // Constructor with arguments
    public Address(String line1, String line2) {

        System.out.println("This is an Address constructor with arguments");

        this.addressLine1 = line1;
        this.addressLine2 = line2;



    }



    // Getters and setters....
    // 
    public void setAddressLine1(String line1) {

        this.addressLine1 = line1;
    
    }
    
    public String getAddressLine1() {
        
        return this.addressLine1;

    }



    // Getters and setters....
    // 
    public void setAddressLine2(String line2) {

        this.addressLine2 = line2;
    
    }
    
    public String getAddressLine2() {
        
        return this.addressLine2;

    }




    // Override on the toString method for Java objects
    @Override 
    public String toString() {

        return "Address Line 1: " + this.addressLine1  + "\nAddress Line 2" + this.addressLine2;
    }















}
