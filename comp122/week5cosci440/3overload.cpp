/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/14/2018					     !
!									     #
#		Week 5 - Overloaded Functions Part 3			     !
!			Program 3				   	     #
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



#! Write a program that computes and displays the charges for a patient's hospital stay. First
	the program should ask if the patient was admitted as in-patient or out-patient.

	If the patient is in-patient, the following data should be entered:
		Number of days spent in the hospital
		The daily rate charge
		Hospital medication charges
		Charges for hospital services (lab tests, etc)

	If the patient is out patient, the following data should be entered:
		Charges for hospital services
		Hospital medication charges

	
	The program should use two overloaded functions to calculate the total charges.
	One of the functions should accept arguments for inpatient data, the other function
	accepts arguments for out-patient information. Both functions should return the total
	charges



	(Input validation - do not accept negative numbers for any data)



(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <stdexcept>



// Lots of I/O made simpler without a 'using' statement
#define cout std::cout
#define cin std::cin

#define INPATIENT 1 
#define OUTPATIENT 2



inline bool isValid(int input);
inline bool isValid(double input);
double calcFees(int days, double dayRate, double medCost, double servCost);
double calcFees(double medCost, double servCost);





int main()
{
	
	bool valid = false;
	int days, inOut;
	double dayRate, medCost, servCost, total;


	// Keeps input in a loop untill every input is confirmed to be vaid	
	while (!valid)
	{
		cout << "\n\nSelect from the availible options:\n\t";
		cout << "1. In-patient\n\t";
		cout << "2. Out-patient\n";

		cin >> inOut;
		
		// Makes sure user selected either 1 or 2 for inpatient or outpatient
		if (!((inOut == INPATIENT) || (inOut == OUTPATIENT)))
		{
			cout << "Invalid choice\n\n";
		}
		else
		{
			valid = true;
		}
	}


	valid = false;
	// Valid is reset to false to repeat input validation
	while(!valid)
	{

		// Here the extra input prompts are added for the additional
		// arguments required for calculating the cost of an inpatient stay
		if (inOut == INPATIENT)
		{
			cout << "\nEnter length of stay in days: ";
			cin >> days;
			if (!isValid(days))
			{
				cout << "Invalid input \n\n";
				continue;
			}
			
			cout << "\nEnter inpatient daily rate: ";
			cin >> dayRate;
			if (!isValid(dayRate))
			{
				cout << "Invalid input \n\n";
				continue;
			}
		}


		// These inputs are required regardless of inpatient or outpatient 
		// and therefore not included in the loop
		cout << "\nEnter Medication fees: ";
		cin >> medCost;
		if (!isValid(medCost))
		{
			cout << "Invalid input \n\n";
			continue;
		}

		cout << "\nEnter service fees: ";
		cin >> servCost;
		if (!isValid(servCost))
		{
			cout << "Invalid input \n\n";
			continue;
		}



		// The point of the continue statements throughout the input
		// checking process is that it will skip the following expression
		// that sets valid to true allowing control to leave the 
		// while loop
		//
		//
		// If a continue statement is executed, the value of valid will
		// remain false and reprompt the user for valid input
		valid = true;

	}


	

	// Selecting which overloaded function to execute based on
	// input for inpatient or outpatient
	if (inOut == INPATIENT)
	{
		total = calcFees(days, dayRate, medCost, servCost);
	}
	else
	{
		total = calcFees(medCost, servCost);
	}


	// Using manipulators to output a proper dollar figure
	cout << "Total cost of stay: $" <<  std::fixed << std::setprecision(2) << total << std::endl;

}




// Simple functions that are overloaded
double calcFees(int days, double dayRate, double medCost, double servCost)
{
	return ( (days*dayRate) + medCost + servCost);
}

double calcFees(double medCost, double servCost)
{
	return (medCost + servCost);
}



// Returns a true or false val=se depending on whether
// the input is negative
//
// Except when the input is asking for days in the hospital,
// then the first function deems 0 as invalid input as well
inline bool isValid(int input)
{

       	(input <= 0) ? input = false : input = true;
	return input;

}
inline bool isValid(double input) { 

       	(input < 0) ? input = false : input = true;
	return input;
}
