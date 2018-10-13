    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           10/10/2018                                               !
    !                                                                            #
    #          LAB 5 - Match tokens - 20.11                                      !
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



   20.1 - Display words in ascending alphabetical order): Write a program that reads
           words from a text file and displays all the words (duplicates allowed) in ascend-
           ing alphabetical order. The words must start with a letter. The text file is passed
           as a command-line argumen




        
*/

import java.util.Scanner;
import java.util.*;
import java.io.File;

public class TokenMatch {

    private List<String> wl = new ArrayList<String>();
    private String filePath; 
    private boolean fpSet = false;

    
    public static void main(String[] args) {
       

        // Error check for number of command line args
        if (args.length != 1) {
            System.out.println("TokenMatch requires one argument - Arguments given: " + args.length);
            return;
        }
        
    }




    public boolean determineMatching() {
        int oParen, cParen, oBrack, cBrack, oBrace, cBrace;

        for (String word : this.wordList) {
            
            switch (word) {
                case "(":
                    oParen++;
                case ")":
                    cParen++;
                case "{":
                    oBrace++;
                case "}":
                    cBrace++;
                case "[":
                    oBrack++;
                case "(":
                    cBrack++; 
            }
        }
        if ( (oParen == cParen) && (oBrace == cBrace) && (oBrack == cBrack) ) {
            return true;
        }
        return false;
    }





    public boolean setFilePath(String fp) {
        
        // Check for file existence
        File f = new File(fp);
        if (!f.exists()) {
            return false;
        }
        
        // Set file path property if file exists
        this.filePath = fp;
        this.fpSet = true;
        return true;
    }
        


    // The TokenMatch implementation of parseFile() is identical to the
    // AlphabetSort implementation, the program will use an ArrayList to
    // determine matching tokens
    public boolean parseFile() {
        
        // Make sure file path is set before attempting read
        if (!this.fpSet) {
            System.out.println("File path must be set before parsing");
            return false;
        }
        

        // Try catch because compiler does not know whether file exists
        // yet or not, throws FileFoundFound IOException without try/catch block
        try {
            
            // Create file object to supply to scanner object as source
            File p = new File(this.filePath);

            // Use file object for source in Scanner Constructor
            Scanner r = new Scanner(p);

            // Check first hasNext() method to determine if file is empty
            if (!r.hasNext()) {
                System.out.println("File is empty");
                return false;
            }
           
            // Continue to grab tokens (words) until file is empty
            while (r.hasNext()) {
                String t = r.next();
                this.wordList.add(t);
            }
            return true;
        }
        catch (Exception e) {
            return false;
        }

    }
    

     
   







}






