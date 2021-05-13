/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		4/13/2018					     !
!									     #
#		Lab Assignment: header files, memory modules, namespaes      !
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



                                THIS IS THE HEADER FILE FOR
                                PROGRAM 1 OF THE WORK SHEET




#! Put together a multi file program based on this header.
    One file named golf.cpp should provice suitable function definitons to match
    the protoypes in the header file. 

    For example a loop should solicit input for an array of golf structures and terminate
    when the array is full or the user enters an empty string for the golfers name.

    The main() function should use only the protyped functions to access the golf structures





	


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
#include <cstring>

// Header guard set here
#ifndef GOLF_H 
#define GOLF_H 

#define MAX_NAME_LEN 512


struct golf
{
    char fullname[MAX_NAME_LEN];
    int handicap;
};



/*
 * Non interactive version: 
 *  Function sets golf structure to provided name, handi
 *  using values passed as arguments to functions
 */
void setgolf(golf& g, const char * name, int hc);




/*
 * Interactive version:
 *  Function solicits name and handicap from user
 *  and sets the members of g to the values entered
 *  returns 1 if name is entered, 0 if name is empty string
 */
int setgolf(golf& g);



// Function resets handicap to new value
void handicap(golf& g,int hc);


// Function displays contents of golf structure
void showgolf(const golf& g);





/*
 * Note that sethgolf() is overloaded. Using the first version of setgolf() would look like
 * this:
 *
 *      golf ann;
 *      setgolf(ann, "Ann Birdfree", 24);
 *
 *
 * The function call provides the information thats stored in the ann structure.
 * Using the second version fo setholf() would look like this:
 *
 *      golf andy;
 *      setgolf(andy)
 *
 *
 *  The function would prompt the user to enter the name and handicap and store
 *  them in the andy structure. This function could (nbut doesnt need to) use the first
 *  version internally.
 *
 */







#endif
