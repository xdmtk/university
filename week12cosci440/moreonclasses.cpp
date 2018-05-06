/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/1/2018					     !
!									     #
#	        In Class: More on Classes 
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





(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <ios>
#include <ctime>

#include "moreonclasses.h"




int main()
{
    // Create Date object
    Date foo;

    std::cout << "\n\nCurrent Date: \n";
    // Get the current date
    foo.init();

    // Print the current date
    foo.print();

    // The reason these values are called with
    // -1, -1 and -1900 is that the print()
    // function is designed to work with
    // the tm struct which puts values in a particular format
    //
    //
    //
    // From the /stuct_tm.h file which is included in time.h

            /* ISO C `broken-down time' structure.  
            struct tm
            {
              int tm_sec;			 Seconds.	[0-60] (1 leap second)
              int tm_min;			 Minutes.	[0-59] 
              int tm_hour;			 Hours.	[0-23] 
              int tm_mday;			 Day.		[1-31] 
              int tm_mon;			 Month.	[0-11] 
              int tm_year;			 Year	- 1900.  
              int tm_wday;			 Day of week.	[0-6] 
              int tm_yday;			 Days in year.[0-365]	
              int tm_isdst;			 DST.		[-1/0/1]

            */
    //
    //
    //
    //
    //

    std::cout << "\n\nAfter init with parameters: \n";

    foo.init(11-1, 25-1, 2018-1900);
    foo.print();

    return 0;
}


void Date::init(int month, int day, int year)
{

    _month = month;
    _day = day;
    _year = year;
}


void Date::init(void)
{

    // Get current time in time_t format
    time_t timer;
    time(&timer);

    // Pass that time value to localtime() which
    // converts that time value into a struct tm
    // data type
    struct tm *tstruct = localtime(&timer);


    // Which then can be used to extract the individual
    // values as they are listed above
    _month = tstruct->tm_mon;
    _day = tstruct->tm_mday;
    _year = tstruct->tm_year;
}




void Date::print()
{

    // Notice the compensations for the way struct tm 
    // handles the data supplied to it by a time-t pointer
    std::cout << "Month: " << _month+1 << std::endl;
    std::cout << "Day: " << _day+1 << std::endl;

    // This one is the most interesting because struct tm
    // handles the date by an integer value that is how many years
    // after the year 1900, therefore we must add 1900 to get our original value
    std::cout << "Month: " << _year+1900 << std::endl;
    
}
