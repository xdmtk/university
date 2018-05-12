/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/10/2018					     !
!									     #
#	       Test 3 ! Due May 14th 2018                                    !
!                           MAIN FILE                               	     #
#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!


TODO: Start at line 285


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




                        MAIN FILE






(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "warehouse.h"

int menu(int &choice);
int initTotals(int st[], int sz[], int slt[][STOCK_LIMIT], int w1[], int w2[], int w3[], int w4[]);


int main()
{
    // Hardcoding data values
    int w1[STOCK_LIMIT]{14,15,5,0,16};
    int w2[STOCK_LIMIT]{15,20,25,0,5};
    int w3[STOCK_LIMIT]{25,25,40,30,20};
    int w4[STOCK_LIMIT]{5,3,10,0,10};


    // Calculate item totals, zero stock items, and less than tens
    int stockTotal[STOCK_LIMIT];
    int stockZeros[STOCK_LIMIT];
    int stockLessTen[WAREHOUSES][STOCK_LIMIT];

    initTotals(stockTotal, stockZeros, stockLessTen, w1, w2, w3, w4);

    int choice;
    menu(choice);

    while (choice != QUIT_PROGRAM)
    {
        if (choice == PRINT_ZERO_REPORT)
        {
            system("clear");
            // Print ZERO Report
            //
            //
            // This could.... be made into a function, but if I did that
            // my entire codebase would reside in 'warehouse.cpp', and main
            // would consist only of two function calls and a menu, probably not what you
            // want to see, so instead im crafting each report directly in main
            //
            //
            ///////////////////////////////////////////////////////>>


            Formatter align;

            // Establish terminal width for object
            align.getTerminalWidth();


            // Create three placeholder strings for passing
            // strings to the member functions of 'align'
            std::string left, right, center;





            // Begin printing the report

            center.assign("QUANTUM CORP");

            // Parametetrs are the text to be printed, and the amount
            // of new line characters to be printed
            // following the text
            align.centerText(center,3);


            center.assign("ZERO STOCK REPORT");
            align.centerText(center,1);


            center.assign("04/07/17");
            align.centerText(center, 2);


            center.assign("Stock#   Stock#   Stock#   Stock#   Stock#");
            align.centerText(center, 1);


            // Begin the left right and center calls

            right.assign("TOTAL/WAREHOUSE");

            // You might be wondering, why am I assigning a blank spot to the
            // left text?
            //
            // Well, this particular line has a strange format to it, being that
            // the numbers are supposed to be centered, but theres only text on the right
            //
            // So in order to line everything up with the following lines, I've
            // put the same amount of spaces as in the word "WAREHOUSE *", since
            // the next lines are going to have that as their spacing requirements
            left.assign("            ");
            center.assign("  1        2        3        4        5 ");
            align.leftCenterRight(left,center,right,1);



            // Begin data lines


            left.assign("WAREHOUSE 1");

            // Here is a tricky part, we must get the data stored as integers
            // into their character equivalents to be stored in the
            // appropriate strings
            //
            // So we pass the first warehouse data array, the center string to be
            // filled with the data, and the right string to be filled with the sum
            // of the data elements
            //
            // Also we must specify the mode being used for the 'formatDataText()'
            // function, so it knows how to print each specific line,
            // since the arrays make uniform automated printing specialized
            // for each type of line
            align.formatDataText(w1, center, right, STOCK_AND_SUM);

            align.leftCenterRight(left,center,right,1);



            left.assign("WAREHOUSE 2");
            align.formatDataText(w2, center, right, STOCK_AND_SUM);
            align.leftCenterRight(left,center,right,1);



            left.assign("WAREHOUSE 3");
            align.formatDataText(w3, center, right, STOCK_AND_SUM);
            align.leftCenterRight(left,center,right,1);


            left.assign("WAREHOUSE 4");
            align.formatDataText(w4, center, right,STOCK_AND_SUM);
            align.leftCenterRight(left,center,right,2);



            // Here we are going to be switching modes to print the item totals
            // line, also feeding it the data for which stock # has more than three
            // 0's for the warehouses
            left.assign("ITEM TOTALS");
            align.formatDataText(stockTotal, center, right, ITEM_TOTALS);
            align.leftCenterRight(left,center,right,2);


            // Print the Stock items that are 0'd in 3 or more warehouses
            // by cycling through the array that contains the number of the stock
            // item.
            //
            // 0's in that array indicates a no match
            std::cout << "ZERO STOCK ITEMS IN THREE OR MORE WAREHOUSES: ";
            for (int i = 0; i < 5; ++i)
            {
                if (stockZeros[i] != 0)
                {
                    std::cout << stockZeros[i];
                }


            }
            std::cout << "\n\n\nPress any key to return to menu...";
            std::string none;
            std::cin.ignore();
            std::getline(std::cin, none);
        }


        else if (choice == PRINT_LTT_REPORT)
        {

            // This section is a duplicate from the previous report
            // and wont be re-explained here
            system("clear");
            Formatter align;

            align.getTerminalWidth();
            std::string left, right, center;


            center.assign("QUANTUM CORP");
            align.centerText(center,3);

            center.assign("ZERO STOCK REPORT");
            align.centerText(center,1);

            center.assign("04/07/17");
            align.centerText(center, 2);

            left.assign("WAREHOUSE");
            right.assign("ITEM");
            center.assign("");
            align.leftCenterRight(left,center,right,1);

            std::cout << "NUMBER\n";

            right.clear();
        // Left off here
            int totalLessTen = 0;
            align.formatDataText( stockLessTen, left, right, totalLessTen);



            std::cout << "\n\n\nPress any key to return to menu...";
            std::string none;
            std::cin.ignore();
            std::getline(std::cin, none);




        }
        else
        {
            system("clear");
            std::cout << "Invalid choice\n\n\n";

            std::cout << "Press any key to return to menu...";
            std::string none;
            std::cin.ignore();
            std::getline(std::cin, none);

        }
        system("clear");
        menu(choice);

    }




}


int menu(int &choice)
{
    Formatter menu;
    menu.getTerminalWidth();

    // Menu splash page

    std::cout << " ██████╗ ██╗   ██╗ █████╗ ███╗   ██╗████████╗██╗   ██╗███╗   ███╗     ██████╗ ██████╗ ██████╗ ██████╗\n";
    std::cout << "██╔═══██╗██║   ██║██╔══██╗████╗  ██║╚══██╔══╝██║   ██║████╗ ████║    ██╔════╝██╔═══██╗██╔══██╗██╔══██╗\n";
    std::cout << "██║   ██║██║   ██║███████║██╔██╗ ██║   ██║   ██║   ██║██╔████╔██║    ██║     ██║   ██║██████╔╝██████╔╝\n";
    std::cout << "██║▄▄ ██║██║   ██║██╔══██║██║╚██╗██║   ██║   ██║   ██║██║╚██╔╝██║    ██║     ██║   ██║██╔══██╗██╔═══╝\n";
    std::cout << "╚██████╔╝╚██████╔╝██║  ██║██║ ╚████║   ██║   ╚██████╔╝██║ ╚═╝ ██║    ╚██████╗╚██████╔╝██║  ██║██║\n";
    std::cout << "╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝    ╚═════╝ ╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═ \n";

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";



    std::cout << "\n\n Select which report to display: \n\n";
    std::cout << "1. Zero Stock Report\n";
    std::cout << "2. Less than Ten Report\n";
    std::cout << "3. Quit program\n";


    std::cin >> choice;
    return 0;
}





















int initTotals(int st[], int sz[], int slt[][STOCK_LIMIT], int w1[], int w2[], int w3[], int w4[])
{
    // Calculate stock totals
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += w1[i];
        sum += w2[i];
        sum += w3[i];
        sum += w4[i];

        st[i] = sum;
        sum = 0;
    }

    int zero = 0;
    // Determine which stock item has 0 in
    // three or more warehouses
    for (int i = 0; i < 5; ++i)
    {
        // Is there zero value in stock i? If yes, increment
        // zero
        (w1[i]) ? (zero = zero) : (zero++);
        (w2[i]) ? (zero = zero) : (zero++);
        (w3[i]) ? (zero = zero) : (zero++);
        (w4[i]) ? (zero = zero) : (zero++);


        // If theres zeros in three or more warehouses
        // for stock number (i+1), then add it to
        // the stock zero array
        (zero >= 3) ? (sz[i] = (i+1)) : (sz[i] = 0);
        zero = 0;
    }


    int lessThanTen = 0;
    // Determine whether stock item is less than 10
    // and in which warehouse
    for (int i = 0; i < 5; ++i)
    {

        // If item in warehouse is less than 10, add it
        // to corresponding row/column of slt[][] (stock less ten)
        // otherwise store a 0 so the formtter knows to skip over it
        (w1[i] < 10) ? (slt[0][i] = (i+1)) : (slt[0][i] = 0);
        (w2[i] < 10) ? (slt[1][i] = (i+1)) : (slt[1][i] = 0);
        (w3[i] < 10) ? (slt[2][i] = (i+1)) : (slt[2][i] = 0);
        (w4[i] < 10) ? (slt[3][i] = (i+1)) : (slt[3][i] = 0);


    }


    return 0;
}















