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

    private List<String> lineList;
    private Map<String,Integer> keyMap; 
    private List<String> keyList = Arrays.asList( "abstract",
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

    private String filePath; 
    private boolean strSet, mLcom, fpSet;


    public CountKeywords() {
        this.lineList = new ArrayList<String>();
        this.mLcom = this.strSet = false;

        this.keyMap = new HashMap<String,Integer>();

    }


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


        // Parse words in file individually, error check if not
        if (!kl.parseFile()) {
            System.out.println("Failed to parse file");
            return;
        }

        // Begin adding keywords to the map
        kl.countKeywordsInLine();
        
        kl.toString();
        return;
       

    }



    public int countKeywordsInLine() {
        

        // Parse line from line list
        for (String line : this.lineList) {

            // Scan conditions on whether to include found keywords
            // based on strings, or comments
            if ( line.contains("//") ) { continue; } 
            if ( line.contains("/*") ) { this.mLcom = true; continue; }
            if ( line.contains("*/") ) { this.mLcom = false; } 
            if ( line.contains("\"") ) { specialCount(line);  continue; }
            if ( this.mLcom == true ) { continue; } 

            // If line passed above checks, split line into individual words
            String[] words = line.split("\\s+");

            // For each on each word, check whether keyword list contains the given word
            // if so add it to the map
            keyMapAdd(words);
        }
        return 0;
    }

    void specialCount(String line) {

        // For lines with strings in them, count only the words outside of the
        // string
        int sPos = line.indexOf("\"");
        int fPos = line.indexOf("\"", sPos+1);

        // Does this by splitting the string from the beginning to the first quote,
        // and concatenating the end quote to the end of the string
        String trimmed = line.substring(0,sPos) + line.substring(fPos, line.length());
       

        String[] words = trimmed.split("\\s+");

        // Use same implementation to add words to the map
        keyMapAdd(words);

        return;
    }


    void keyMapAdd(String[] words) {

        // For each on each word
        for (String word : words) {

            // Check if word is keyword
            if (this.keyList.contains(word)) {
                if (!this.keyMap.containsKey(word)) {
                    
                    // Start with value of 1 (seen once) if not in map
                    this.keyMap.put(word,1);
                }
                else {
                    
                    // Otherwise get current value of key and increment
                    int c = this.keyMap.get(word);
                    this.keyMap.put(word,c+1);
                }
            }
        }
        return;
    }




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
                this.lineList.add(r.nextLine());
            }
            return true;
        }
        catch (Exception e) {
            return false;
        }

    }
    

    

   @Override
   public String toString() {
        System.out.println("Contents of Map - Keywords in File");
        System.out.println("{");
        
        // Iterate through map contents
        for (Map.Entry<String,Integer> e : this.keyMap.entrySet()) {
            System.out.println("\t" + e.getKey() + " -> " + e.getValue());
        }
        
        System.out.println("}");
       
       // Dont return anything since String contents already being printed
       return "";
    }



     
   







}


/* 

    Sample output for this source file 

    xdmtk@DMT~/prog/fall2018/lab6 (master)
    └─ $ ▶ j CountKeywords CountKeywords.java 

    Contents of Map - Keywords in File
    {
        new -> 6
        private -> 5
        static -> 1
        void -> 3
        import -> 3
        for -> 3
        while -> 1
        int -> 4
        boolean -> 3
        public -> 7
        else -> 1
        true -> 1
        try -> 1
        catch -> 1
        class -> 1
        if -> 11
        return -> 8
    }


*/



