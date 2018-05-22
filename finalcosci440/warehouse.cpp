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

TODO: Fixed the spacing issue 

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

#include <cstdio>
#include <cstdlib>


#include <sys/ioctl.h>
#include <unistd.h>


#include "warehouse.h"


// Function to get the current terminal width
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







// Just a quick inline to print new lines at the end
// of a formatted text function call
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







// This function will take the integer data stored in the integer
// arrays, and return them as a line of text to be printed
// in the following print function
void Formatter::formatDataText(int dataArray[], std::string &center, std::string &right, int mode)
{



// 
// Stock and Sum Line Priting Mode
// ////////////////////////////////////////////////////////////////////////////
// //
// /
//

    if (mode == STOCK_AND_SUM)
    {
        std::string data;
        int sumint = 0; 

        // For each data member, append it to the string
        for (int i = 0; i < STOCK_LIMIT; ++i)
        {

            // Total the data elements in sum
            sumint += dataArray[i];



            // First convert the data member to a character string
            // stored in 'data' by the function itoa() 
            data = std::to_string(dataArray[i]); 

            // This switch is going to craft the center string
            // with the appropriate amount of spacing 
            //
            // The gist of this switch statement is that, the first data item
            // simply gets appended to the string, then the next 3 data items,
            // being the middle data items, get appended witha particular amount of 
            // spacing that matches the "Stock #" spacing
            //
            // Then we calculate for numbers less than 10 requiring an
            // extra space to fill a width requirement, in line 440
            //
            // The last line is essentially the same except without the trailing
            // space after the data item
            switch (i)
            {
                case 0:
                    center.assign(data);
                    break;


                case 4: 
                    center.append("       ");
                    center.append(data);
                    center.append(" ");
                    break;


                default:

                    center.append("       ");
                    center.append(data);
                    break;

            }
            if (dataArray[i] < 10) 
            {
                center.append(" ");
            }
        }

        // This final append is necessary for the centering process to work
        center.append("        ");




        // Setting the sum of the data items to a string
        // then appending it to the 'right' parameter 
        // to be crafted for the following format function
        right.assign(std::to_string(sumint));
        int spaceToAppend = 3 - right.size();
        for( int i = 0; i < spaceToAppend; ++i)
        {
            right.append(" ");
        } 
    }

//
// /
// // 
// End Stock and Sum Line Priting Mode
// ////////////////////////////////////////////////////////////////////////////
//









// 
// Item Totals Line Printing Mode 
// ////////////////////////////////////////////////////////////////////////////
// //
// /
//



    else if (mode == ITEM_TOTALS)
    {
        std::string data;    

        for (int i = 0; i < STOCK_LIMIT; ++i)
        {

    

            data = std::to_string(dataArray[i]); 

            switch (i)
            {
                case 0:
                    center.assign(data);
                    break;


                case 4: 
                    center.append("       ");
                    center.append(data);
                    center.append(" ");
                    break;


                default:

                    center.append("       ");
                    center.append(data);
                    break;

            }
            if (dataArray[i] < 10) 
            {
                center.append(" ");
            }
        }

        // This final append is necessary for the centering process to work
        center.append("        ");

        right.assign("    ");
    }


//
// /
// // 
// End Stock and Sum Line Priting Mode
// ////////////////////////////////////////////////////////////////////////////
//











    return;
}




// Since the Less than Ten array is a multidimensional array, we need an overloaded
// instance of the formatDataText function
//
// Additionally that array and its output will be handled very differently than the above function
// 
void Formatter::formatDataText(int dataArray[][5], std::string &left, std::string &right, int &totalLessThanTen)
{

    // Here were going to set a bool to see if the
    // given warehouse has items with less than 10 stock
    bool ltt = false;
    
    // Also since there is only a right and left justified 
    // text in these lines, we can calculate the spacing like
    // we have in the centered functions, by subtracting the
    // size of the left and right texts from the terminal width
    int spaces;



    // Here were going to loop through each warehouse and their corresponding
    // stocks in the multidimensional array
    for (int i = 0; i < 4; ++i)
    {
        for (int x = 0; x < 5; ++x)
        {

            // A non zero value in this array indicates
            // that one of the data members has less than ten stock
            //
            // See the initDataValues() function for why that is so
            if (dataArray[i][x] != 0)
            {

               // Next we change the bool to true to indicate
               // this line will be printed in the report
               ltt = true;

               // Also we up the less than ten count
               // for when we need to print the total
               totalLessThanTen++;
            }
        }

        // Here if the line was indicated to be printed,
        // we enter the code body that will handle this
        if (ltt)
        {


            // Like always, since we are formatting text manually,
            // we must set our left and right elements
            // using the string functions assign() and append()
            left.assign(std::to_string(i+1));
            for (int x = 0; x < 5; ++x)
            {


                // Once again we check for a non zero value,
                // if one is detected, we add it to the right hand list
                // (as a string of course), and put a comma for th next value
                if (dataArray[i][x])
                {
                    right.append(std::to_string(dataArray[i][x]));

                    right.append(",");
                }
            }
            

            // Once all values that are less than 10 have been 
            // stored into the right text segment, we use pop_back()
            // to remove the trailing comma appended after each value
            right.pop_back();


            // We also reset the bool for the next warehouse iteration
            ltt = false;

            // Calculate spacing like normal
            spaces = _twidth - (left.size() + right.size());


            // Print the left text
            std::cout << left;


            // Apply spacing
            for (int z = 0; z < spaces; ++z)
            {
                std::cout << " ";
            }
            

            // Print the right text
            std::cout << right;

            // Then  clear the right string for the next iteration
            right.clear();
        }


    
    }
    return;


}
















