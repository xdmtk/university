/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/5/2018					     !
!									     #
#	       Homework: Formatting without manipulators                     ! 
!                               Part I	   				     #
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



#! Write a program that will allow the user to type in a line of text. The line
    the user types in should be printed centered in the page





(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstdio>
#include <sys/ioctl.h>
#include <unistd.h>



int main()
{

    // In order to center text without using manipulators (manually spacing/tabbing)
    // the program must be aware of the terminal window size.
    //
    // Varied sized teriminals against a fixed spacing algorithm will fail to produce
    // reliably centered text
    //
    // Therefore we must make the program aware of the width of the terminal



    // In the <sys/ioctl.h> header, the winsize structure is defined
    //
    // The terminal window as seen by the kernel can be extracted using
    // a call to ioctl() [input output control] with the parameter TIOCGWINSZ
    // indicating the operation for ioctl()

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    // By providing a pointer to the winsize structure 'w', the ioctl() call
    // is able to fill the 'w' structure with the apropriate values
    //
    //
    //  struct winsize {
    //	    unsigned short	ws_row;		/* rows, in characters */
    //	    unsigned short	ws_col;		/* columns, in characters */
    //      unsigned short	ws_xpixel;	/* horizontal size, pixels */
    //      unsigned short	ws_ypixel;	/* vertical size, pixels */    //
    //  }
    //
    //
    //
    // Set retrieved terminal width to 'twitdh', create variable for
    // text lenght 'len'
    int len, twidth = w.ws_col;
    std::string text;




    // Get input
    std::cout << "Enter text to center: ";
    std::getline(std::cin, text);

    // Put text length into len
    len = text.size();


    // Determine amount of spaces to output by dividing the terminal size by 2
    // and subtracting spaces for every two characters in the input string
    //
    // This gives the appearance of the text being perfectly centered in the terminak
    // despite the length of the text
    int spaces = (twidth/2) - (len/2);

    

    std::cout << "\n\n";

    // Fill the output line with the determined spaces
    for (int i = 0; i < spaces; ++i)
    {
        putchar(' ');
    }

    // Finish output with newline
    std::cout << text << "\n\n\n";















    
    return 0;
}




