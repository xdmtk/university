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
        
        if (args.length != 1) {
            System.out.println("AlphabetSort requires one argument - Arguments given: " + args.length);
            return;
        }

        AlphabetSort wl = new AlphabetSort();
        if (!wl.setFilePath(args[0])) {
            System.out.println("File path given does not exist: " + args[0]);
            return;
        }
        
        if (!wl.parseFile()) {
            System.out.println("Failed to parse file");
            return;
        }








        return;
    }




    public boolean setFilePath(String fp) {
        
        File f = new File(fp);
        if (!f.exists()) {
            return false;
        }
        
        this.filePath = fp;
        this.fpSet = true;
        return true;
    }
        

    public boolean parseFile() {
        
        if (!this.fpSet) {
            System.out.println("File path must be set before parsing");
            return false;
        }
       
        try {
            File p = new File(this.filePath);
            Scanner r = new Scanner(p);
            if (!r.hasNext()) {
                System.out.println("File is empty");
                return false;
            }
            
            while (r.hasNext()) {
                String t = r.next();
                System.out.println(t);
                this.wordList.add(t);
            }
            return true;
        }
        catch (Exception e) {
            return false;
        }

    }
    

    public boolean sortList() {

        if (!this.wordList.isEmpty()) {
            java.util.Collections.sort(this.wordList); 
            return true;
        }
        return false;
    }
     
    








}






