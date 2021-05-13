/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/8/2018					     !
!									     #
#	       Abstract Array Class Main File                                ! 
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



#! Write a program that will allow the user to type in a line of text. The line
    the user types in should be printed centered in the page

                    MAIN FILE



(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include "integerList.h"



#define SIZE 20


int main()
{


    // Create integer list object with SIZE as argument for constructor
    IntegerList test(SIZE);

    // Create temporary variable to hold return value
    // of getElement
    int x;



// Setting
///////////////////////////////////////////////////////////////
//


    std::cout << "\n\nStoring nines into array\n\n";
    std::cout << "###################################\n";
    
    
    for (int i = 0; i < 20; ++i)
    {
        // If the element is sucessfully able to be set
        // then print out the asterisk
        if (test.setElement(i,9))
        {
            std::cout << "*" << std::endl;
        
        }
        // Otherwise print out which element is out of bounds
        else
        {
            std::cout << "Element " << i << " is out of range" << std::endl;
        }
    }

//
///////////////////////////////////////////////////////////////
//








// Getting - (Valid Values)
///////////////////////////////////////////////////////////////
//


    std::cout << "\n\nGetting valid values\n\n";
    std::cout << "###################################\n";


    for (int i = 0; i < 20; ++i)
    {
        // Return the element specified by i
        // and store into x, then print x
        x  = test.getElement(i);
       
       
        // getElement() returns the macro constant 
        // OUT_OF_BOUNDS if the requested element is out of
        // bounds of the array
        //
        // Therefore we test x for that value to determine whether we have
        // a value to print or not
        if (x == OUT_OF_BOUNDS)
        {
            std::cout << "Element " << i << " is out of range" << std::endl;
        }
        else
        {
            std::cout << x << std::endl;
        }
    }

//
///////////////////////////////////////////////////////////////
//





// Trying to retrieve values out of bounds 
///////////////////////////////////////////////////////////////
//




    std::cout << "\n\nStarting at range 10 to 30, should produce 10 invalid range errors\n\n";
    std::cout << "###################################\n";

    // Starting at a valid range but ending 
    // in an invalid range
    for (int i = 10; i < 30; ++i)
    {
        x  = test.getElement(i);
       
       
        if (x == OUT_OF_BOUNDS)
        {
            std::cout << "Element " << i << " is out of range" << std::endl;
        }
        else
        {
            std::cout << x << std::endl;
        }
    }

//
///////////////////////////////////////////////////////////////
//






}
