/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/8/2018					     !
!									     #
#	       Abstract Array Class Header Source File                       ! 
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
                
            THIS IS THE MAIN FILE



(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include "abstarr.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>






IntegerList::IntegerList(int size)
{

    // Allocate array of size elements and 
    // link to member pointer variable pVector
    pVector = new int[size];
    numElements = size;

}


IntegerList::IntegerList()
{
    
    // If no size parameter is called upon
    // object creation, create vector
    // with default size
    
    pVector = new int[DEFAULT_SIZE];
    numElements = DEFAULT_SIZE;


}






IntegerList::~IntegerList()
{
    
    // Deallocate the memory allocated
    // by the constructor
    delete pVector;
}





// Bool function returns true or false depending on whether
// the value can be stored successfuly
bool IntegerList::setElement(int pos, int value)
{


    // Out of bounds checking
    if ((pos >= numElements) || (pos < 0))
    {
        return false;
    }

    // Set the value of the dynamically allocated array
    pVector[pos] = value;


    // Return true because validation was passed
    // successfully
    return true;
}




// This function returns the requested element
//
// If the element was unsuccesful, the
// function returns a predefined macro sentinal 
//
int IntegerList::getElement(int pos)
{

    // Out of bounds checking
    if ((pos >= numElements) || (pos < 0))
    {
        return OUT_OF_BOUNDS;
    }

    // Otherwise return the requested value
    return pVector[pos];
}































