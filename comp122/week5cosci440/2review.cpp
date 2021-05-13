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



#! Number 2:  (with pointers)
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

	


	Basically this program is the same except we are being asked
	to pass by reference instead of by value
	
	Although passing as pointers and by reference are two different 
	concept, I will use both in this program
		


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

void passByRef(int &num, int &num1);
void passByPointer(int *num, int *num1);
int nothing(mine *varMine);


int main()
{

	int sum;
	mine varMine = {666, 777};


	// Passing the members of varMine by reference (aliasing method)
	passByRef(varMine.num, varMine.num1);

	// Passing the members of varMine as a pointer
	passByPointer(&varMine.num, &varMine.num1);






	// Sending entire varMine struct variable to function
	sum = nothing(&varMine);


	std::cout << "The sum of the two structure members are: " << sum << std::endl;


	return 0;


}




// When passing by reference, the dereferencing operator (*) is not
// need as the variables instead serve as 'aliases' for the variables passed
//
// In essence its a 'safer' way to pass parameters that require out of scope
// modification
void passByRef(int &num, int &num1)
{
	std::cout << "\n\nThese parameters were passed by reference\n";
	std::cout << num << " and  " << num1 << std::endl;

	return;
}



// When passing as pointers, the parameter variables in their regular form (without the
// dereferencing operator) contain actual memory address, in contrast to the aliasing 
// method of passsing by reference. 
//
// In this situation  we must use the dereferncing operator to properly print 
// the values pointed to by the pointer variables
void passByPointer(int *num, int *num1)
{
	std::cout << "\n\nThese parameters were passed through a pointer variable\n";
	std::cout << *num << " and  " << *num1 << std::endl;

	return;
}



// In this example, a new operator (->) the indirection operator is used.
//
// This operator is really a shorthand for *(varMine.num), as it takes the 
// pointer to the structure, and dereferences the member addressed to it
// by the indirection operator
//
// This operator is seen in any container class or structure, but in specific
// they are seen often in the creation of dynamically linked lists
int nothing(mine *varMine)
{
	std::cout << "\n\nStructure members are:\n";
	std::cout << varMine->num << " and " << varMine->num1 << std::endl;

	return (varMine->num + varMine->num1);

}
