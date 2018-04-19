/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		4/17/2018					     !
!									     #
#	                Lab Assignment: Classes                              !	
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
                


                                THIS IS THE MAIN FILE



#! A Betelguesuan plorg has these properties:

    Data: 
            A plorg has a name with no more than 19 letters
            A plorg has a contentment index (CI) which is an integer

    Operations:
            
            A new plorg starts out with a name and a CI of 50
            A plorgs CI can change
            A plorg can report its name and CI
            The default plorg has a name "Plorga"


            
        1. Write a Plorg lass declaration including data members and member
            function protoypes that represents a plorg

        2. Write the function definitions for the member functions

        3. Write a short program that demonstrates all the feautures of the
            Plorg class



(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <cstring>



// Macro constant for name length
#define MAX_NAME_LEN 17


// Class definition
class Plorg
{

    // All functions that access datamember are decalred public
    // so non-class callers can access them
    public: 

        // Constructor declaration, but not definition
        Plorg();

        // Function prototype
        void setCI(int ci);
        void getPlorgInfo();

    private:
        

        // Data members declared as private members
        // to protect data
        char _name[MAX_NAME_LEN];
        int _ci;
};







int main()
{

    // Declare new instance of Plorg class 'p'
    // which calls default constructor, asking for name
    // and sets CI index to 50, if name is blank
    // default name "Plorgra is applied"
    Plorg p;


    // Show results of constructor call
    p.getPlorgInfo();


    // Access setCI function of Plorga class through
    // Plorga object 'p'
    p.setCI(32);


    // Show results of call to setCI()
    p.getPlorgInfo();


    return 0;


}




// Construct is defined using the classname as the function name
// Scope operator is applied because class function is defined outside of
// class definition
Plorg::Plorg()
{

    // Gets name
    std::cout << "Enter new name for Plorg (If blank default name is chosen): ";
    std::cin.getline(_name,17);


    // If no name entered, make name "Plorga"
    // Also notice data members are by convention, prefixed with
    // an underscore, to identify them apart from other variables in the function
    if (strlen(_name) ==  0)
    {
        strcpy(_name, "Plorga");
    }

    // Set CI to 50
    _ci = 50;

}



// Sets CI data member of calling object
void Plorg::setCI(int ci)
{
    _ci = ci;
}




// Pulls datamembers from calling object, and displays them
void Plorg::getPlorgInfo()
{
    std::cout << "Plorg name: " << _name <<  std::endl;
    std::cout << "Plorg contentment index: " << _ci <<  std::endl;

}

