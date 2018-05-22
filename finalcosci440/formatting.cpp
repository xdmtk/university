/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/21/2018					     !
!									     #
#	       FINAL EXAM FORMATTING  SOURCE FILE !!!!                       !
!                               	   				     #
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



#! Write a c++ program which accepts the name of a text file, reads in that file, and prints out
    the following information about the file:

            A list of all letters (A through Z) in that file, disregarding case (e.g. count "a" and "A"
            as two occurences of the same letter A), ordered with the most frequently used letter first
            and the least frequently used letter last, along with the number of times each letter was
            used

            An alphabetized list of a ll distinct words in that file with the number of times each
            word was used

            The average number of letters in a word

            The average num ber of words in a sentence



    2. Create a folder with "your name S 2018" and put the files for your application in the folder.
        For example, C Siller - S 2018



    Use the following example paragraph to setup your test input text file:


        Any experienced programmer engaged in writing programs for use by others knows that,
        once his program is working correctly, good output is a must. Few people really care how much
        time and trouble a programmer has spent in designing and debugging a program. Most people
        only see the results. Often, by the time a programmer has finished tackling a difficult problem,
        any output may look great. The programmer knows what it means and how to interpret it. However,
        the same cannot be said for others, or even for the programmer himself six months hence.






    You need to create at least one class with member functions and use it in your program




(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////g


#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>


#include <locale>
#include <iterator>



#include "fileParser.h"


///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//////////////////////////////////////////////////
//
// From here on is reused code from the formatting assignment
// to make formatting nice output easier. The way I wrote the functions
// actually makes them easier to use than <iomanip> functions for 
// formatting
//
//





void Formatter::getTerminalWidth()
{
    // IOCTL call to kernel requesting current 
    // terminal window dimensions
    //
    // Return the width by accessing the 
    // 'ws_col' member of 'w'
        
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    _twidth = w.ws_col;
}


inline void Formatter::printNewLines(int newlines)
{
    

    for (int i = 0; i < newlines; ++i)
    {
        std::cout << "\n";
    }

    return;

}


// Just a quick inline to print new lines at the end
// of a formatted text function call
inline void Formatter::printSpaces(int spaces)
{
    

    for (int i = 0; i < spaces; ++i)
    {
        std::cout << " ";
    }

    return;

}


// Function to store the lowercase version of 'regularString' into 'lowerString'
void Formatter::specialToLower(std::string regularString, std::string &lowerString)
{
    std::string::iterator iter;
    std::string c;
    iter = regularString.begin();
    for (;iter != regularString.end(); ++iter)
    { 
        c = *iter;
        lowerString.append(c);
    }
    return;
}






// Function to print a line with the text passed as a parameter
// centered, and also print the specified amount of newlines
void Formatter::centerText(std::string line, int newlines)
{
    

    // Get length of string to determine spaces
    int len = line.size();




    // If the line supplied is too long for the terminal window
    // to fit all on one line, the program will exit
    if (!checkLineFit(len))
    {
        exit(1);
    }




    // Use terminal width dimension and line length to
    // compute spaces needed to center text
    int spaces = (_twidth/2) - (len/2);



    // Output necessary amount of spaces using for loop
    // and putchar
    for (int i = 0; i < spaces; ++i)
    {
        putchar(' ');
    }


    // No manipulators!
    std::cout << line;

    printNewLines(newlines);
    
    return;
}














// This function prints a line with three formatting justifications, text right justified
// text left justified, and text centered between the two
void Formatter::leftCenterRight(std::string left, std::string center, std::string right, int newlines)
{


    // Get the lengths' of all three parts of the line
    int lenLeft = left.size();
    int lenCenter= center.size();
    int lenRight= right.size();
                  



    // If the line supplied is too long for the terminal window
    // to fit all on one line, the program will exit
    if (!checkLineFit(lenLeft, lenRight, lenCenter))
    {
        exit(1);
    }





    // In order to get one line of text on the right, the other on
    // the left, and ALSO something in the center, we first need 
    // to calculate the space between the left and right text,
    // in order to divide it up equally for the spaced text in the center
    //
   
    int centerSpace = _twidth - (lenLeft + lenRight);

    
    // Resusing the centered text code from other function
    // but instead of _twidth as total available width in the terminal
    // we replace with centerSpace, which is the leftover
    // space between the left and right text lines
    //

    int spaces = (centerSpace/2) - (lenCenter/2);

  




    // Print left justified text 
    std::cout << left;
  

    // Output spaces    
    printSpaces(spaces);

    // Print center text
    std::cout << center;


    // Output spaces    
    printSpaces(spaces);


    // Output right text 
    std::cout << right;


    printNewLines(newlines);
    return;

}






// Overloaded instance for the center only printing function
inline bool Formatter::checkLineFit(int l1)
{
    if (l1  > _twidth)
    {
        std::cout << "\n\nLine print error, terminal size too small, please";
        std::cout << " resize winow and try again\n\n";
        
        return false;
    }
    else
    {
        return true;
    }


}







// Quick inline function to make sure the contents of the line
// to be printed is not larger than the terminal width 
inline bool Formatter::checkLineFit(int l1, int l2, int l3)
{
    if ((l1 + l2 + l3)  > _twidth)
    {
        std::cout << "\n\nLine print error, terminal size too small, please";
        std::cout << " resize winow and try again\n\n";
        
        // A line entered that exceeds the terminal size will break the
        // algorithm used to format. If the terminal window is too small for 
        // for the text supplied, the program will end because the desired
        // formatting results will be impossible to acheive

        return false;
    }
    else
    {
        return true;
    }


}



