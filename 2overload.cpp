/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/14/2018					     !
!									     #
#		Week 5 - Overloaded Functions Part 2			     !
!			Program 2				   	     #
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



#! Write a simple program that will use overloaded functions to calculate the
	gross weekly pay of hourly paid or salary paid employees

	

	Use three functions: 
		void getChar(char &letter) // get an H or S for either salaried or hourly employee
		double calcWeekly(int, double);
		double calcWeekly(double);



		For the salaried user the function will take the yearly pay as a parameter




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




void getSalariedOrHourly(char &letter);
double calcWeekly(int hours, double rate);
double calcWeekly(double yearly);

int main()
{
	char letter;
	int hours;
	double rate, yearly, weekly;


	// Gets H or S from user
	getSalariedOrHourly(letter);
	



	// If H is entered, input data required for hourly
	// and calculate
	if ((toupper(letter) == 'H') || (letter == 'h'))
	{
		std::cout << "Enter hours worked for the week: ";
		std::cin >> hours;

		std::cout << "Enter hourly rate for selected employee: ";
		std::cin >> rate;

		weekly = calcWeekly(hours, rate);
	}
	// If S is entered, input data required for hourly
	// and calculate
	else
	{

		std::cout << "Enter annual salary: ";
		std::cin >> yearly;
		
		weekly = calcWeekly(yearly);
	}

	std::cout << "\n\nThe weekly salary for this employee is: $";
	
	// Use manipulators to get a dollar value expression
	std::cout << std::fixed << std::setprecision(2) <<  weekly << std::endl;
	return 0;


}

void getSalariedOrHourly(char &letter)
{

	// Input validation for entering appropriate character
	while ((toupper(letter) != 'S') || (toupper(letter != 'H'))
	{

		std::cout << "\n\nEnter H for hourly or S for salaried employee: ";
		std::cin >> letter;
	}
	return;
}


// Overloading the calculation function with different argument types
double calcWeekly(int hours, double rate)
{	
	return (hours * rate);
}

double calcWeekly(double yearly)
{
	return (yearly/52);
}

