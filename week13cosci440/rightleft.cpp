/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/5/2018					     !
!									     #
#	       Homework: Formatting without manipulators                     ! 
!                               Part II	   				     #
#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!


		  _             _           _            _              _     
		/\ \           /\ \        / /\        /\ \            /\ \
	       /  \ \         /  \ \      / /  \      /  \ \           \ \ \
	      / /\ \ \       / /\ \ \    / / /\ \__  / /\ \ \          /\ \_\
	     / / /\ \ \     / / /\ \ \  / / /\ \___\/ / /\ \ \        / /\/_/ 
	    / / /  \ \_\   / / /  \ \_\ \ \ \ \/___/ / /  \ \_\      / / /    
	   / / /    \/_/  / / /   / / /  \ \ \    / / /    \/_/     / / /     
	  / / /          / / /   / / /    \ \ \  / / /             / / /      
	 / / /________  / / /___/ / /_/\__/ / / / / /________  ___/ / /__     
	/ / /_________\/ / /____\/ /\ \/___/ / / / /_________\/\__\/_/___\
	\/____________/\/_________/  \_____\/  \/____________/\/_________/    



			       _            _            _          
			   _  /\ \      _  /\ \        / /\
			  /\_\\ \ \    /\_\\ \ \      / /  \
			 / / / \ \ \  / / / \ \ \    / / /\ \
			/ / /   \ \ \/ / /   \ \ \  / / /\ \ \
			\ \ \____\ \ \ \ \____\ \ \/_/ /  \ \ \
			 \ \________\ \ \________\ \ \ \   \ \ \
			  \/________/\ \/________/\ \ \ \   \ \ \
				    \ \ \        \ \ \ \ \___\ \ \
				     \ \_\        \ \_\ \/____\ \ \
				      \/_/         \/_/\_________\/



#! Write a program that wil left justify a list of names and then right justify
    a line of characters on the same line.

    Use the following array and the following list of names to test your solution


        char Next[3][5] = { {'1', '2', '4', '6', '7'}, {'2','4'}, {'1', '3', '5'}};





(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstdio>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>



int main()
{

    char numbers[3][5] = { {'1', '2', '4', '6', '7'}, {'2','4'}, {'1', '3', '5'}};
    char *names[3] = {"Jackson", "Samantha", "Sam"};


    // See explanation for the following lines in previous file
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int twidth = w.ws_col, z;


    int nameLen, numLen[3], numLenVar, spaces;

    // 
    // In order to get the length of the entries in *names[], we can use string length
    // but in the case of the multidimensional array, the lengths must be hard coded in.
    //
    // To avoid writing a lengthy conditional for loop to determine how many characters to
    // print, we can hard code those values into an array

    numLen[0] = 5;
    numLen[1] = 2;
    numLen[2] = 3;



    std::cout << "\n\n\n";
    for (int i = 0; i < 3; ++i)
    {
        // Setting variable attributes for width requirements of terminal 
        numLenVar = numLen[i];
        nameLen = strlen(names[i]);

        // 'twidth, total width of terminal
        //  numLenVar, number of entries in row of multi-dim array numbers[][]
        //  numLenVar-1, number of commas to put
        spaces = twidth - (nameLen + numLenVar + (numLenVar - 1));



        // Print the name left justified
        printf("%s", names[i]);

        // Apply spaces for right justification
        for (int x = 0; x < spaces; ++x)
        {
            putchar(' ');
        }

        // Use x as index for numbers to print in numbers[][]
        // and use z as a counter to determine whether to output a 
        // comma or a number
        for (int x = z = 0; z < (numLenVar + ( numLenVar-1)); ++z)
        {
            if ((z % 2) == 0)
            {
                printf("%c", numbers[i][x++]);
            }
            else
            {
                putchar(',');
            }
        }
        std::cout << "\n";


    }

    std::cout << "\n\n\n";
    return 0;
}
