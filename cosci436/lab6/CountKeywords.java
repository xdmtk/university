    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           10/10/2018                                               !
    !                                                                            #
    #          LAB 6 - Count Keywords 21.3                                       !
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



   20.3 - Revise the program in 21.7 to count java keywords in a source file. 
          Make sure to check whether the keyword is within a comment or string




        
*/

import java.util.*;
import java.util.Scanner;
import java.io.File;


public class CountKeywords {

    private List<String> lineList  = new ArrayList<String>();
    private String filePath; 
    private boolean fpSet = false;

    
    
    private List<String> keywords = Arrays.asList( "abstract",
        "assert", "boolean", "break",
        "byte",    "case",    "catch",   "char",
        "class",   "const",   "continue",    "default",
        "do",  "double",  "else",    "enum",
        "extends", "final",   "finally", "float",
        "for", "goto",    "if",  "implements",
        "import",  "instanceof",  "int", "interface",
        "long",    "native",  "new", "package",
        "private", "protected",   "public",  "return",
        "short",   "static",  "strictfp",    "super",
        "switch",  "synchronized",    "this",    "throw",
        "throws",  "transient",   "try", "void",
        "volatile",    "while",    "true",    "false",
        "null");


    public static void main(String[] args) {
       
        CountKeywords kl = new CountKeywords();

        // Error check for number of command line args
        if (args.length != 1) {
            System.out.println("CountKeywords requires one argument - Arguments given: " + args.length);
            return;
        }
        
        // If input file supplied, continue with object creation
        // Use the path supplied by argument to set objects path
        if (!kl.setFilePath(args[0])) {

            // Error check for invalid paths
            System.out.println("File path given does not exist: " + args[0]);
            return;
        }
       

    }



    public int countKeywordsInLine() {
        




    // Create file object for path
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
        

    
    // While this File parsing function is similar to other
    // implementations, we instead must read line by line, rather
    // than word by word
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
            if (!r.hasNextLine()) {
                System.out.println("File is empty");
                return false;
            }
           
            // Continue to grab tokens (words) until file is empty
            while (r.hasNextLine()) {
                lineList.add(r.nextLine());
            }
            return true;
        }
        catch (Exception e) {
            return false;
        }

    }
    

     
   







}






