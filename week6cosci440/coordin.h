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



#! This is the polar program header file
	from page 449 in the book C++ Primer 6th Edition 
	
	


(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


// Header guards here to make sure the same file is not included twice
// Basically if the following macro COORDIN_H_ is not found to be defined,
// then it follows that the file has not yet been processed by the compiler
// 
// Therefore the code between ifndef COORDIN_H_ and endif will be compiled into
// the program, which includes the definition of the macro COORDIN_H_. 
//
// By defining this macro under the condition it has not already been defined
// it follows that the code in the section between the ifndef and endif 
// will only be included once, because if the compiler attempts to include
// this file again, it will find that COORDIN_H_ has already been defined
// by a previous inclusion, and therefore skips over processing the code
// between ifndef and endif
//
// 
#ifndef COORDIN_H_
#define COORDIN_H_






struct polar
{
	double distance;
	double angle;

};


struct rect
{
	double x;
	double y;
};


// prototypes

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);


#endif





