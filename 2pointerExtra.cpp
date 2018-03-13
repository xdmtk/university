/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/10/2018					     !
!									     #
#		Week 5 - Extra Pointer Assignment 2			     !
!								   	     #
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



#! This is a simple program that demonstrates parameter passing of pointers. This allows
	the receiving function to modify the value of the variable being pointed to

	Study this program and then write a program that includes a swap function to
	exchange the values of two variables.


	Below will be the program that executes a swap using pointers


(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <stdexcept>


void swp(int *x, int *y);

int main()
{
	int x = 666, y = 777;
	

	std::cout << "\n\nPre-swap:" << std::endl;
	std::cout << "The value of x is: " << x << std::endl;
	std::cout << "The value of y is: " << y << std::endl;


	// Passing address of x and y to the swap function
	// (passing as pointers)
	swp(&x,&y);



	std::cout << "\n\n\nPost-swap:" << std::endl;
	std::cout << "The value of x is: " << x << std::endl;
	std::cout << "The value of y is: " << y << std::endl;

}




void swp(int *x, int *y)
{

	// This XOR swap method is purely for aesthetics
	// as one could easily create a temporary variable
	// to execute the swap
	//

	*x ^= *y;
	*y ^= *x;
	*x ^= *y;


	/* XOR logic of the swap
	 *
	 * 	*x = 0010 1001 1010 -> 666d
	 * 	*y = 0011 0000 1001 -> 777d
	 *
	 * 	Line 99 logic:
	 *	 	*x = 0010 1001 1010 -> 666d
	 * 		*y = 0011 0000 1001 -> 777d
	 * 	
	 * 		*x ^= *y;
	 *		New values: 
	 *		*x = 0001 1001 0011 -> 403d
	 *		*y = 0011 0000 1001 -> 777d
	 *
	 *
	 *	Line 100 logic:
	 *		*x = 0001 1001 0011 -> 403d
	 *		*y = 0011 0000 1001 -> 777d
	 *		
	 *		*y ^= *x;
	 *		New Values:
	 *		*x = 0001 1001 0011 -> 403d		
	 *		*y = 0010 1001 1010 -> 666d
	 *
	 *
	 *	Line 101 logic:
	 *		*x = 0001 1001 0011 -> 403d
	 *		*y = 0010 1001 1010 -> 666d
	 *
	 *		*x ^= *y;
	 *		New Values: 
	 *		*x = 0011 0000 1001 -> 777d
	 *		*y = 0010 1001 1010 -> 666d
	 *
	 *
	 *	Values have been swapped.
	 *
}



