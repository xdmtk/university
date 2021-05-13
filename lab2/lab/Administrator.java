
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





public class Administrator extends Staff {
    
    String position;
    String dept;


    public Administrator() {
        
        super.overridenMethod();

    }

   

    // Getters and setters
    //

    public boolean setPosition(String p) {
       
        this.position = p;
        // Return true if assignment is sucessful
        if (this.position == p) {
            return true;
        }
        // Return false otherwise
        return false;
    }

    public String getPosition() {
        // Gets and returns the calling object's hiredate
        return this.position;
    }



    public boolean setDept(String d) {
       
        this.dept = d;
        // Return true if assignment is sucessful
        if (this.dept == d) {
            return true;
        }
        // Return false otherwise
        return false;
    }

    public String getDept() {
        // Gets and returns the calling object's hiredate
        return this.dept;
    }



    @Override
    public String toString() {

        return ("Position: " + this.position + "\n" + "Department: " + this.dept);
    }
}



