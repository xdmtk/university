    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           10/10/2018                                               !
    !                                                                            #
    #          LAB 5 - Display Words in Ascending Alphabetic Order -  20.1       !
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

public class AlphabetSort {


    private List<String> wordList = new ArrayList<String>();
    private String filePath; 
    private boolean fpSet = false;

    
    public static void main(String[] args) {
       

        // Error check for number of command line args
        if (args.length != 1) {
            System.out.println("AlphabetSort requires one argument - Arguments given: " + args.length);
            return;
        }
        
        // If input file supplied, continue with object creation
        AlphabetSort wl = new AlphabetSort();

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
        

        // Parsed list to string before sort
        System.out.println("Before sort:\n" + wl.toString());
        wl.sortList();


        // Parsed list to string after sort
        System.out.println("\n\nAfter sort:\n" + wl.toString());

        return;
    }

/* SAMPLE OUTPUT

    Before sort:
    Object description:
    --------------------------
    [foo, dddddddddd, kdmwqkmd, aaaaaaa, bbbbbbbbbbb]


    After sort:
    Object description:
    --------------------------
    [aaaaaaa, bbbbbbbbbbb, dddddddddd, foo, kdmwqkmd]

*/










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
    

    public boolean sortList() {


        // Use static Collection method sort() to sort list
        // according to natural order of the elements
        if (!this.wordList.isEmpty()) {
            java.util.Collections.sort(this.wordList); 
            return true;
        }

        return false;
    }
     
   

    // Override on toString to print object contents in custom format
    @Override
    public String toString() {

        String output = "Object description:\n--------------------------\n";
        output = output.concat(this.wordList.toString());
        return output;
    }







}






