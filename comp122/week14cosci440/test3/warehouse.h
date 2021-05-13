/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/10/2018					     !
!									     #
#	       Test 3 ! Due May 14th 2018                                    !
!                           HEADER FILE    	   			     #
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


    


                HEADER FILE
  

 



(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#ifndef WAREHOUSE_H


#define WAREHOUSE_H


// Array limit macros
#define WAREHOUSES 4
#define STOCK_LIMIT 5


// Formatting modes
#define STOCK_AND_SUM 0
#define ITEM_TOTALS 1


// Menu choices
#define PRINT_ZERO_REPORT 1
#define PRINT_LTT_REPORT 2
#define QUIT_PROGRAM 3


class Formatter
{

    public: 

        

        void getTerminalWidth();

        void centerText(std::string line, int newlines);
        void leftCenterRight(std::string left, std::string center, std::string right, int newlines);
       
        void formatDataText(int dataArray[], std::string &center, std::string &right, int mode);
        void formatDataText(int dataArray[][5], std::string &left, std::string &right, int &totalLessThanTen);

        inline bool checkLineFit(int l1, int l2, int l3);
        inline bool checkLineFit(int l1);



        inline void printSpaces(int spaces);
        inline void printNewLines(int newlines);


    private:

        int _twidth;
      

        // Hope its alright if I hard code the data in
        //
        // I could do a read/input for this but hardcoding it
        // takes out a lot of unnecessary code for the point
        // of this test


};



#endif



