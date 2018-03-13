/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/14/2018					     !
!									     #
#		Week 5 - Review - Using just enough			     !
!			Program 1				   	     #
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



#! Number 1:  (without pointers)
	Write a structure called mine with two integer variables (num and num1)
	In the main(), create a variable of the type mine and assign an integer value
		to num and num1
	Write a function call that will pass these parameters by value
	Write a function called nothing that will receive a variable of the structure
		type mine
	The function called nothing will print the structure members num and num1,
		add num and num1 together and send them back the sum
	The main() will print the sum when it comes back from the function called
		nothing. 

	Do NOT use the function call in the cout << statement (??) 

	
	


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

struct mine
{
	int num, num1;
};

void passByVal(int num, int num1);
int nothing(mine varMine);


int main()
{

	int sum;
	mine varMine = {666, 777};


	// Passing the members of varMine by value
	passByVal(varMine.num, varMine.num1);
	
	// Sending entire varMine struct variable to function
	sum = nothing(varMine);


	std::cout << "The sum of the two structure members are: " << sum << std::endl;


	return 0;


}



void passByVal(int num, int num1)
{
	std::cout << "\n\nThese parameters were passed by value\n";
	std::cout << num << " and  " << num1 << std::endl;

	return;
}



int nothing(mine varMine)
{
	std::cout << "\n\nStructure members are:\n";
	std::cout << varMine.num << " and " << varMine.num1 << std::endl;

	return (varMine.num + varMine.num1);

}
