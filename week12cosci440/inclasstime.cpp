/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/1/2018					     !
!									     #
#	        In Class: Time Classes
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



#! Create a time class that will accept a time and print it in either Universal format or in Standard format.
    Once class Time has been defined, it can be used as a type in object, array, pointer and reference 
    declarations as follows: 
            
        Time sunset;
        Time arrayOfTimes[5];
        Time &dinnerTime = sunset
        Time *timePtr = &dinnerTime;




    Now create a program that uses Time in the following manner:
        
        1. Instantiates a single object of class  Time called
        2. Call the Time constructor to intialzie each private data member to 0
        3. Print the time in universal and standard formats to confirm that the members we 
            initialized properly
        4. Sets a new time by calling member function setTime
        5. Print the time again in both formats
        6. Use setTime to set the data members to invalid values
        7. The setTime function should recognize this and set the invalid values to 0
        8. Print the time again in both formats






	


(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <ios>




class Time 
{
    public:
        Time();
        void setTime(int h, int m, int s);
        void printUniversal();
        void printStandard();
        inline bool validate(int tvar, int upper, int lower);



    private: 
        int _hour;
        int _minute;
        int _second;

};


int main()
{


    Time tobj;
    // Constructor is implictly called
    //




    // Begin calling/printing sequence
    std::cout << "In class time program:";



    std::cout << "\n\n\n\tThe initial standard time is";
    tobj.printStandard();
    std::cout << "\tThe initial universal time is ";
    tobj.printUniversal();



    tobj.setTime(13,27,6);



    std::cout << "\tThe standard time after calling setTime is";
    tobj.printStandard();
    std::cout << "\tThe universal time after calling setTime is ";
    tobj.printUniversal();


    // Invalid settings
    tobj.setTime(133,127,336);


    std::cout << "After calling invalid settings:\n\n";
    std::cout << "\tStandard time:";
    tobj.printStandard();
    std::cout << "\tUniversal time: ";
    tobj.printUniversal();






    return 0 ;
}



// Constructor to initialize values
Time::Time()
{
    _hour = 0;
    _minute = 0;
    _second = 0;
}



// Sets the time for hours mins and seconds
// using an inline validation function
void Time::setTime(int h, int m, int s)
{

    validate(h, 24, 0) ? (_hour = h) : (_hour = 0);
    validate(m, 59, 0) ? (_minute = m) : (_minute = 0);
    validate(s, 59, 0) ? (_second= s) : (_second = 0);

    return;
}



// Quick validation function that returns true or false
// based on whether supplied time variable 'tvar'
// is within the upper and lower bounds specified by the caller
//
inline bool Time::validate(int tvar, int upper, int lower)
{
    if ((tvar >= lower ) && (tvar <= upper))
    {
        return true;
    }
    else
    {
        return false;
    }
}



// Print standard time
void Time::printStandard()
{
    std::string ampm;
    int h,m,s;

    // Makes ampm "PM" if beyond or equal to 12
    if (_hour >= 12)
    {
        ampm.assign("PM");
        // Gets standard hour equivalent by subtracting
        // value by 12 unless time is actually 12
        if (_hour != 12)
        {
            h = _hour - 12;
        }
        else
        {
            h = _hour;
        }
    }

    // AM login, makes display value 12
    // if time is 0, for midnight
    else
    {
        ampm.assign("AM");
        if (_hour == 0)
        {
            h = 12;
        }
        else
        {
            h = _hour;
        }
    }



    // Minutes and seconds dont require special handling
    m = _minute;
    s = _second;



    // Print formated time

    std::cout << " " << h << ":" << std::setfill('0') << std::setw(2) << m;
    std::cout << ":" << std::setfill('0') << std::setw(2) << s;
    std::cout << " " << ampm << std::endl;
    
}







void Time::printUniversal()
{
    int h,m,s;
    // No formatting required therefore no need for special
    // cases

    h = _hour;
    m = _minute;
    s = _second;


    std::cout << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m;
    std::cout << ":" << std::setfill('0') << std::setw(2) << s << "\n\n";
    
}















