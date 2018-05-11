/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/10/2018					     !
!									     #
#	       Test 3 ! Due May 14th 2018                                    !
!                       Function Source File    			     #
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



#! NOTE: The previous assignment was to develop code to align data elements. For this
    test, you will create an object called align and use the code you developed in the
    previous assignment for the alignment functions.

    You will turn in 3 sections of the program - one section is the creation of the object,
    the second section is the .cpp file that contains the function definition s, and
    the third section is the code to use the object and produce the following program.




    You own four warehouses across the country, each of which can stock five particular items.
    There are two types of reports that will be produced. These two choices will appear on a menu.

    The menu selections will offer the user their choice of the two reports listed below
    and create the appropriate reports.


    The Zero Stock Report prints all items and indicates any items that have a stock of zero, in 
    three or more warehouses The Less Than Ten Report indicates, by warehouse, items that have a 
    stock of less than ten.


    Please center your reports on the screen. A program that produces these exact results will
    earn a grade of 80. You can earn additional points as follows: 

            - 10 points by right justifying the numbers
            - 5 points by including a menu
            - 5 points using a menu and parameter passing



                    FUNCTION SOURCE FILE 

 



(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "warehouse.h"

#include <cstdio>
#include <sys/ioctl.h>
#include <unistd.h>


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


void Formatter::rightJustify(std::string line, int newlines)
{
    // This function is just for text that needs
    // to be right justified, no special centered
    // additions

    // Only one line seems to require this in the expected
    // output, so this function should only need to be called
    // once

    int len = line.size();
   

    // If the line supplied is too long for the terminal window
    // to fit all on one line, the program will exit
    if (!checkLineFit(len))
    {
        exit(1);
    }



    // Set spaces to the remaining width of the 
    // terminal minus the text to be printed 
    int spaces = _twidth - len;
 
    for (int i = 0; i < spaces; ++i)
    {
        putchar(' ');
    }

    std::cout << line;

    printNewLines(newlines);


    return;
}





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
    for (int i = 0; i < spaces; ++i)
    {
        putchar(' ');
    }


    // Print center text
    std::cout << center;


    // Output spaces    
    for (int i = 0; i < spaces; ++i)
    {
        putchar(' ');
    }
   
    // Output right text 
    std::cout << right;


    printNewLines(newlines);
    return;

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




inline void Formatter::printNewLines(int newlines)
{
    

    // Just a quick inline to print new lines at the end
    // of a formatted text function call
    for (int i = 0; i < newlines; ++i)
    {
        std::cout << "\n";
    }

    return;

}









