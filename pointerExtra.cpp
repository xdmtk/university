/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/10/2018					     !
!									     #
#		Week 5 - Extra Pointer Assignment 1			     !
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



#! 


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


void edit();

int main()
{
	/* What does the following program print? Run the program, thenb comment out
	 * the line that shows *j = 4 and run the program again. What is the difference?
	 * Why? What does that line do?
	*/


	/* Going to use a seperate function for the original and the 
	 * version that is commented out. The original program
  	 * will stay in main, and the edited version 
	 * will have its own function
	 */



	int x = 3, *j, k;


	// Sets j to mem address of x. Sets *j to 3
	j = &x;

	// Sets k to 3
	k = *j;

	// Sets *j to 4. Also sets x to 4, as j is referencing the location in memory of x
	*j = 4;


	// Program will print:
	// x = 4, *j = 4, k = 3
	//
	std::cout << "x = " << x << " *j = " << *j << " k = " << k  << std::endl;



	edit();
	return 0;


		



}

/* 
 * The difference between these two functions is that when the 
 * line *j = 4, is executed, it is effectively assigning 4 to the memory
 * location of x, which j points to. Therefore 
 * 					j = memoryLoc of x
 * 					*j = value of x
 * 					x = value of x;
 *
 * 					So by executing an assignment to *j, 
 * 					the program is essentially executing the assignment to x
 *
 */











void edit()
{
	int x = 3, *j, k;


	// Sets j to mem address of x. Sets *j to 3
	j = &x;

	// Sets k to 3
	k = *j;

	//*j = 4;


	// Program will print:
	// x = 3, *j = 3, k = 3
	//
	std::cout << "x = " << x << " *j = " << *j << " k = " << k  << std::endl;

}
