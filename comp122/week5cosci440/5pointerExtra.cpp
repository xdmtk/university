/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/10/2018					     !
!									     #
#		Week 5 - Extra Pointer Assignment 5			     !
!								   	     #
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



#! Write a program that gets sales data, shows the total sales for the year, and total sales
	for each quarter. 

	main()
		-Will contain a definition of an array of double called sales, that holds 4 quarters
		-Will contain a function call named getSales which will send the empty array sales
		along with the size of the array
		-Will contain a statement that sets the precision of the output to 2 decimal places
		-Will display the total sales for the year
		-Will contain an inline function named totalSales which will send the sales array
		and the size of the array

	getSales() 
		-will use a pointer 't' to accept the address of an array of doubles. The function
		should ask the user to enter sales figures and store them in the array
	
	totalSales()
		-uses a pointer to accept the address of an array. The function returns the total 
		of the elements in the array

(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <stdexcept>



inline void getSales(double *sales);
inline double totalSales(double *sales);



int main()
{
	double sales[4], total;


	getSales(sales);
	total = totalSales(sales);


	std::cout << std::fixed << std::setprecision(2);	
	std::cout << "\n\nTotal sales for the year: " << total << std::endl;

	return 0;

}


inline void getSales(double *sales)
{
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Enter sales for quarter " << (i+1) << ": "; 
		std::cin >> sales[i];
	}
}

inline double totalSales(double *sales)
{
	double total = 0;
	for (int i = 0; i < 4; ++i)
	{
		total += sales[i];
	}
	return total;
}



