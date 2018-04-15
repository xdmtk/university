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
                


                                      THIS IS THE SOURCE FILE
                                      DEFINING ALL FUNCTIONS




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




void SALES::setSales(Sales& s, const double ar[], int n)
{

    // Initialize values
    s.average = 0;

    // Setting oppositie maximums/minimums for 
    // initial values, so when comparing values in 'ar[]'
    // the max and min values will be continuously updated
    // every iteration with the correct value
    s.max = DBL_MIN;
    s.min = DBL_MAX;
    


    for (int i = 0; i < n; ++i)
    {
        // Copy data
        s.sales[i] = ar[i];

        // Add values to average total
        s.average += ar[i];
        

        // If value is greater than the current maximum
        // set new maximum value
        if (ar[i] > s.max)
        {
            s.max = ar[i]; 
        }


        // If value is less than the current minimum
        // set new minimum value
        if (ar[i] < s.min)
        {
            s.min = ar[i];
        }

    }
    
    // Divide average cumulative value by
    // number of values totaled.
    s.average /= n;

}





void SALES::setSales(Sales& s)
{
    
    double ar[SALES::QUARTERS];
    int n = 4;    

    // Interactivity data entry    
    for (int i = 0; i < SALES::QUARTERS; ++i)
    {
        std::cout << "Enter sales for quarter " << i << ": ";
        std::cin >> ar[i];
        std::cout << "\n";
        
    }




// REUSABLE CODE SECTION

    for (int i = 0; i < SALES::QUARTERS; ++i)
    {
        // Copy data
        s.sales[i] = ar[i];

        // Add values to average total
        s.average += ar[i];
        

        // If value is greater than the current maximum
        // set new maximum value
        if (ar[i] > s.max)
        {
            s.max = ar[i]; 
        }


        // If value is less than the current minimum
        // set new minimum value
        if (ar[i] < s.min)
        {
            s.min = ar[i];
        }

    }
    
    // Divide average cumulative value by
    // number of values totaled.
    s.average /= n;


}





void SALES::showSales(const Sales& s)
{

    std::cout << "\n\nDisplaying structure information\n";
    std::cout << "########################################\n\n";
    
    // Iterate through sales array 
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Quarter " << (i+1) << ": " << s.sales[i] << std::endl;
    }


    std::cout << "\n\nSales average: " << s.average << std::endl;
    std::cout << "\n\nSales maximum: " << s.max << std::endl;
    std::cout << "\n\nSales minimum: " << s.min << std::endl;


}
