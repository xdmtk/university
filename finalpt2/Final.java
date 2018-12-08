/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!                                                                            #
#                                                                            !
!   Programmer:     Nick Martinez                                            #
#   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
!   Instructor:     Milan Samplewala                                         #
#   Date:           12/08/2018                                               !
!                                                                            #
#          Final Exam: Part Two                                              !
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


    Write an algorithm to convert a decimal number to binary number. Provide the Big O analysis. (5 points)

    Then write a java program to implement the algorithm,  name the file  FinalExam.java. (5 points)

    Provide the main() method to test your program. (5 points)

    Do not forget to run your program and show the results.


-------------------------------------------
    ALGORITHM: 

        First we need to find the highest 2^n that does not exceed our
        input number. We do this by testing 2^n over and over until 
        we exceed the input number

        Next we decrement n, so we can have the highest 2^n that is still divisible with
        a result greater than 1 into the input number. 

        Now we can start subtracting from our input number each and every 2^n that
        gets us a greater than 1 divisble result, as this would indicate that the binary
        digit at position n is 1. 

        If we do not get a result greater than 1,  we know that the binary digit at
        position n is 0.

        We do this continually until we hit n^0, and after this is complete, we will 
        have formed a string that contains all the correct binary digits for
        the corresponding number



-------------------------------------------
    OUTPUT: 
        
        
        xdmtk@DMT~/prog/fall2018/finalpt2 (master)
        └─▶ $ java Final 
        (2^2) + (2^0)  = 5
        0101

        (2^0)  = 1
        1

        0 in Binary is just 0

        (2^11) + (2^10) + (2^7) + (2^5) + (2^2) + (2^1)  = 3238
        0110010100110

        (2^6)  = 64
        1000000

        (2^3) + (2^1)  = 10
        01010

        (2^8) + (2^5) + (2^3) + (2^2)  = 300
        0100101100

        (2^8) + (2^7) + (2^3) + (2^0)  = 393
        0110001001




-------------------------------------------
    Big O: 

        The Big O notation for this algorithm  would be O(2n-1), 
        since we must iterate up to n twice, except in the second
        iteration, we have decremented n, and so we will start from 
        n-1

        So n + n -1 = O(2n-1) 






*/
import java.lang.Math;
import java.util.*;

public class Final {



    public static void main(String[] args) {


        System.out.println(Final.convertToBinaryString(5) + "\n");
        System.out.println(Final.convertToBinaryString(1) + "\n");
        System.out.println(Final.convertToBinaryString(0) + "\n");
        System.out.println(Final.convertToBinaryString(3238) + "\n");
        System.out.println(Final.convertToBinaryString(64) + "\n");
        System.out.println(Final.convertToBinaryString(10) + "\n");
        System.out.println(Final.convertToBinaryString(300) + "\n");
        System.out.println(Final.convertToBinaryString(393) + "\n");





    }




    public static String convertToBinaryString(double num) {
        
        // Add zero case
        if (num == 0) {
            return "0 in Binary is just 0";
        }



        // Initialize empty string for output
        String output = "";
        String analysis = "";
        /* First determine maximum 2^n power for input number,
         * this way we can determine the limit at which to start
         * outputting binary digits
         */
        double base,n;
        base=2;

        /* We can do this by starting at 2^0, and working our way up
         * 2^1, 2^2, 2^3 and so on, until our 2^n is greater than the
         * input number we have received, this will tell us how many
         * binary digits we will need, since each iteration of n
         * is a binary digit of 2 to the power of the position of the binary
         * digit
         */
        double sum=0;
        for (n=0; sum < num; n++) {

            // We must reset the base for each iteration so we can
            // be sure we are getting a 2^n result
            base=2;
            sum = 0;
            sum += Math.pow(base,n);
        }

        // Since our n has gone over by one power in order to exit the loop
        // above, we must decrement n by 1 to accurately start computing the
        // resulting binary digit
        --n;


        /* Now starting with our base 2^n, with the n that is the highest
         * possible n that will divide into the input number, we can
         * begin decrementing n, and subtracting the result 2^n from the input
         * number, but only if that 2^n is divisble by the input number
         *
         * The reason for this, is a binary number consists of the sum of the
         * digits, whose position represent a 2^n, so when we subtract say 2^2
         * from the decimal number 7, we are left with 3, so our next 2^n would
         * be 2^1, equating to 2, which can also be subtracted by 3, and now our
         * 2^0, is 1, can also be divided into and subtracted from 3
         * those 3 hits mean we have a binary digit '1' in position 0,1, and 2
         * resulting in the binary number '111'
         */
        double numSave = num;
        for (base=2; n >= 0; n--) {

            // Divide the input number by the current 2^n power
            if (num/Math.pow(base,n) >= 1) {

                // If our answer is divisble, we know that that 2^n is
                // a '1' digit in our binary number, so we append the 1 to the
                // string
                output += "1";

                // In order to accurately perform this operation for the next numbr
                // we have to subtract the result of that 2^n from the input number
                num -= Math.pow(base,n);
                analysis += " (2^" + (int) n + ") +";
            }
            else {

                // If the division is not successfull, then we have a '0' digit
                // for our binary number
                output += "0";
            }
        }


        System.out.println(analysis.substring(0,analysis.length()-1) + " = " + (int) numSave);

        // After the following algorithm has taken place, we have our binary
        // number in String form, if we really want to, we can convert this number
        // to an integer and supply the appropriate padding, but for timessake it is
        // better to leave it in string form
        return output;

    }


















}
