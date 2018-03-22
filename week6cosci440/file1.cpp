/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/21/2018					     !
!									     #
#		Creating and using header files 			     !	
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



#! This is the polar program from page 449 in the book C++ Primer 6th Edition 
	File 1	
	


	Basically this file acts as the main file of the program
	while file2 acts as the object library for the functions declared
	in the "coordin.h" header file


	In order to compile these in a unix environment, the command syntax would 
	be : gcc <file1> <file2> <file3> and so on

	Another way to make compiling easier as projects become larger is
	by specifying the -c option in gcc/g++ and compiling the program
	to object files and separately compiling the object files

	This allows you to make changes to single source files while only having
	to recompile the source file that was edited and then link the 
	corresponding object files , instead of recompiling all of the source
	files to generate the executable. 

	In smaller programs this normally is not of issue, but as projects become
	larger, it can be inconvienant to wait 10+ minutes each compile for every
	small change made 


(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "coordin.h"


int main()
{
	rect rplace;
	polar pplace;

	std::cout << "Enter the x and y values: ";
	
	
	// Does a double input by using the fact that cin is delimited by
	// spaces and the insertion operator can be overloaded to extend
	// the scope of cin
	while (std::cin >> rplace.x >> rplace.y) 
	{

		
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		std::cout << "Next two numbers (q to quit): ";
	}
	std::cout << "Bye!\n";
	return 0;

}

