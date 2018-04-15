/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		4/13/2018					     !
!									     #
#	                Lab Assignment: Namespaces                           !	
!									     #
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
                


                                    THIS IS THE MAIN FILE
                                    OF THE PROGRAM



#! Write a three file propgram based on the following namespace:
        

        namespace SALES
        {
            const int QUARTERS = 4;
            struct Sales
            {
                double sales[QUARTERS];
                double average;
                double max;
                double min;
            };
        

        // Copies the lesser of 4 or n items form the array ar
        // to the sales member of s and computers and stores the 
        // average, maximum and minimum values of the entered items
        // remaining elements of sales if any set to 0
        void setSales(Sales& s, const double ar[]. int n);


        // Gathers sales for 4 quarterts interactively, stores them
        // in the sales member of s and computes and stores the
        // average, maxiumum and minimum values
        void setSales(Sales& s);

        // Display all information in structure s
        void showSales(const Sales& s);


    The first file should be a header file that contains the namespace.
    The second file should be a source code file that extends the namespace to provide
    definitions for the three prototyped functions
    The third file should declare two Sales objects

    It should use the interactive version of setSales() to provide values for one structure
    and the non-interactive version of the setSales() to provide values for the second
    structure

    It should display the contents of both structures by using showSales()





(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <stdexcept>
#include <cfloat>

#include "sales.h"



int main()
{
    SALES::Sales s1, s2;
    double ar[SALES::QUARTERS];



    // Usinig interactive overload of setSales
    // in SALES namespace
    SALES::setSales(s1);
    SALES::showSales(s1);


    // Fill ar[] with arbitrary values
    ar[0] = 324.21;
    ar[1] = 2013.99;
    ar[2] = 111.11;
    ar[3] = 1009.23;

    SALES::setSales(s2, ar, 4);
    SALES::showSales(s2);



    return 0;



}
