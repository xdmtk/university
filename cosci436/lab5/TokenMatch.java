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
import java.util.ArrayDeque;
import java.lang.Throwable;

public class TokenMatch {

    private List<Character> wordList = new ArrayList<Character>();
    private List<Character> tokenList = new ArrayList<Character>();
    private String filePath; 
    private boolean fpSet = false;

    
    public static void main(String[] args) {
       

        // Error check for number of command line args
        if (args.length != 1) {
            System.out.println("TokenMatch requires one argument - Arguments given: " + args.length);
            return;
        }
        
        // If input file supplied, continue with object creation
        TokenMatch wl = new TokenMatch();

        // Use the path supplied by argument to set objects path
        if (!wl.setFilePath(args[0])) {

            // Error check for invalid paths
            System.out.println("File path given does not exist: " + args[0]);
            return;
        }
       
        // Parse file word by word
        if (!wl.parseFile()) {

            // Error checking on parse file
            System.out.println("Failed to parse file");
            return;
        }

        // Run function to check number of tokens
        if (!wl.determineMatching()) {
            System.out.println("Tokens Mismatched");
        }
        else {
            System.out.println("Tokens Match");
        }


    }




    public boolean determineMatching() {
        char current, match;

        // Iterates through characters in file and 
        // pushes tokens in order onto Stack
        for (char c : this.wordList) {
            if (isToken(c) == true) {
                this.tokenList.add(c);
            }
        }

        // If the amount of tokens found in input is odd, must be a
        // mismatched token somewhere
        if ( ( this.tokenList.size() % 2 ) != 0 ) {
            return false;
        }

        while (this.tokenList.size() > 0) {
            match = returnMatching(this.tokenList.get(0));
            for (int x=1; ; ++x) {
                if (isClose(this.tokenList.get(x))) {

                    if (this.tokenList.get(x) == match) {
                        this.tokenList.remove(x);
                        this.tokenList.remove(0);
                        break;
                    }
                    else {
                        return false;
                    }
                }
                if (this.tokenList.size() <= 0) {
                    break;
                }
            }
        }
        return true;
    }






    // Determines whether the incoming character is a valid
    // java grouping token
    public boolean isToken(char c) {
        if ( (c == '(') || (c == ')') || (c == '[') || (c == ']')
            || (c == '{') || (c == '}') ) {
            return true;
        }
        return false;
    }


    public boolean isClose(char c) {
        if (c == ']') { return true; }
        if (c == '}') { return true; }
        if (c == ')') { return true; }
        
        return false;
    } 

    public char returnMatching(char c) {
        if (c == '(') { return ')'; }
        if (c == '[') { return ']'; }
        if (c == '{') { return '}'; }
        
        System.out.println("Mismatched tokens");
        System.exit(0);
        return 0xFF;
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
        


    // The TokenMatch implementation of parseFile() is almost identical to the
    // AlphabetSort implementation, except instead of parsing full words, it will
    // read the file character by character
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
                for (char c : t.toCharArray() ){
                    this.wordList.add(c);
                }

            }
            return true;
        }
        catch (Exception e) {
            return false;
        }

    }
    

     
   







}






