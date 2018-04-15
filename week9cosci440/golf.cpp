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



                                THIS IS THE SOURCE FILE FOR
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


#include "golf.h"





int main()
{

    // Create golf structure nick
    golf nick;
    

    // Call interactive setgolf overload
    if (!setgolf(nick))
    {
        // If function returns 0 value, alert user name field
        // left blank
        std::cout << "Warning: Name entry left blank ! \n";
    }
    

    // Shows results of entry
    showgolf(nick);

    
    // Call non-interactive overload of setgolf
    setgolf(nick, "Nicky", 22);



    // Show the results of the call
    showgolf(nick);



    // Set the handicap from the program
    handicap(nick, 55);


    // Show the results of the call
    showgolf(nick);






    return 0;

}



void setgolf(golf& g, const char * name, int hc)
{
    // None interactive version copys the supplied string
    // from parameter to the referenced structure
    strcpy(g.fullname, name);

    // Sets referenced structures handicap to supplied handicap
    g.handicap = hc;
}



int setgolf(golf& g)
{

    // Declare temporary string and integer variable
    // for easier data handling
    std::string name;
    int hc;

    // Getline used to tolerate whitespace in name supplied
    std::cout << "Enter golfer name: ";
    std::getline(std::cin, name, '\n');

    // Copy the name to structures fullname field,
    // notice c_str() function on std::string variable
    // is applied to properly convert std::string to char *
    strcpy(g.fullname, name.c_str());
   

    // Gets handicap
    std::cout << "Enter handicap: ";
    std::cin >> hc;

    g.handicap = hc;

    // size() function of std::string class is applied
    // to get string length
    if (name.size() == 0)
    {
       return 0;
    }
    return 1; 


}


// Self explanatory
void handicap(golf& g,int hc)
{
    g.handicap = hc;
}


void showgolf(const golf& g)
{
    // Prints out field contents of referenced structure
    std::cout << "Golfer name: " << g.fullname << std::endl;
    std::cout << "Golfer handicap: " << g.handicap << std::endl;
    std::cout << "\n\n";
}






