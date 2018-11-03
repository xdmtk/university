    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           10/10/2018                                               !
    !                                                                            #
    #          LAB 6 - State Capitals 21.9                                       !
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



   Programming Exercise 21.9 (Guess the capitals using maps) Rewrite Programming Exercise 8.37 to store pairs 
   of each state and its capital in a map. Your program should prompt the user to enter a state and should 
   display the capital for the state.
          




        
*/

import java.util.*;
import java.util.Scanner;
import java.io.File;


public class StateCapital {
    private int score = 0;
    private Map<String,String> stateMap = new HashMap<String,String>();
    private String[] stateList = {
        "Montgomery",  "Alabama",
        "Juneau",  "Alaska",
        "Phoenix", "Arizona",
        "Little Rock",  "Arkansas",
        "Sacramento",  "California",
        "Denver",  "Colorado",
        "Hartford",    "Connecticut",
        "Dover",   "Delaware",
        "Tallahassee", "Florida",
        "Atlanta", "Georgia",
        "Honolulu",    "Hawaii",
        "Boise",   "Idaho",
        "Springfield", "Illinois",
        "Indianapolis",    "Indiana",
        "Des Moines",  "Iowa",
        "Topeka",  "Kansas",
        "Frankfort",   "Kentucky",
        "Baton Rouge", "Louisiana",
        "Augusta", "Maine",
        "Annapolis",   "Maryland",
        "Boston",  "Massachusetts",
        "Lansing", "Michigan",
        "Saint Paul",  "Minnesota",
        "Jackson", "Mississippi",
        "Jefferson City",  "Missouri",
        "Helena",  "Montana",
        "Lincoln", "Nebraska",
        "Carson City", "Nevada",
        "Concord", "New Hampshire",
        "Trenton", "New Jersey",
        "Santa Fe",    "New Mexico",
        "Albany",  "New York",
        "Raleigh", "North Carolina",
        "Bismarck",    "North Dakota",
        "Columbus",    "Ohio",
        "Oklahoma City" , "Oklahoma",
        "Salem",   "Oregon",
        "Harrisburg",  "Pennsylvania",
        "Providence",  "Rhode Island",
        "Columbia",    "South Carolina",
        "Pierre",  "South Dakota",
        "Nashville",   "Tennessee",
        "Austin",  "Texas",
        "Salt Lake City", "Utah",
        "Montpelier",  "Vermont",
        "Richmond",    "Virginia",
        "Olympia", "Washington",
        "Charleston",  "West Virginia",
        "Madison", "Wisconsin",
        "Cheyenne", "Wyoming"
    };

    public StateCapital() {

        // Populate state/capital map
        for (int i=0; i < this.stateList.length; i+=2) {
            this.stateMap.put(this.stateList[i+1], this.stateList[i]);
        }
    }


    public static void main(String[] args) {
    
        StateCapital foo = new StateCapital();
        // Get input from command line
        Scanner r = new Scanner(System.in);
        
        for (int i=0; i < foo.stateList.length; i+=2) {
            System.out.println("What is the capital of " + foo.stateList[i+1] + "?");
            System.out.print(">> ");

            // Get input
            String input = r.next();
            input = input.trim();

            if (foo.stateMap.get(foo.stateList[i+1]) == input) {
                System.out.println("Congrats, you got it correct");
                foo.score++;
            }
            else {
                System.out.println("You got it wrong");
            }
        }
        
    }
}














