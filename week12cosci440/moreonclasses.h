/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/1/2018					     !
!									     #
#	        In Class: More on Classes                                    !
!				HEADER FILE                                  #
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



#! Define the class Date for this purpose using three integral data members
    for the day, month and year. Additionally declare the following methods:


        void init(int month, int day, int year);
        void init(void);
        void print(void);



    Store the definition of the class Date in a header file

        Implement the methods for the class Date in a sperate source file:
            1. The method print() outputs the date to standard output using the
                format Month-Day-Year
            2. The method init() uses three parameters and copies the values
                passed to it to corresponding members. A range check is not required
                at this stage, but will be added later
            3. Te method init() without parameters writes the current dagte to the
                corresponding members.


            NOTE: Use the functions declared in ctime


                time_t time(time_t *ptrSec);
                struct tm *localtime(const time_t *ptrSec);


                    THIS IS THE HEADER FILE


(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <ios>
#include <ctime>

#ifndef _MOREONCLASSES_H
#define _MOREONCLASSES_H


class Date
{
    public:
            
        void init(int month, int day, int year);
        void init(void);
        void print(void);


    private: 
        int _month;
        int _day;
        int _year;

};

#endif
