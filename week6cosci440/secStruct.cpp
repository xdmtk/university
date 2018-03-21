/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/20/2018					     !
!									     #
#		C++ Second Structure Assignment				     !	
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



#! Write a program that creates a structure of student names and grades. 
	The structure members should be

		Fname, Lname, ID number, grade

	Allow the user to enter data for 10 students, duplicate at least two of
	the ID numbers when doing data entry


	Print  an error listing showing duplicated if numbers and the 
	students name




	
	


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
#include <algorithm>

#define RECORD_LENGTH 10




struct Student
{
	std::string fName, lName;
	int idnum, grade;
	
	// Because data entries are to be entered in a structure
	// and we do not know beforehand the amount of entries,
	// the *next pointer is going to be used for a linked list
	struct Student *next;
};



void sortAndPrintNodeData(struct Student *temp);
void pushTenNodes(struct Student *node, struct Student *temp, std::vector<int> &dupes);


int main()
{

	// Creating first node
	struct Student* node = new Student;

	// Creating node start point
	struct Student* head = node;

	// Creating referencing pointer for already existing nodes
	struct Student* temp = node;


	// Creates a vector and corresponding iterator to store
	// duplicate records
	std::vector<int> dupes;
	std::vector<int>::iterator it;
	int i = 0;



	// Push nodes for student record entry
	pushTenNodes(node, temp,dupes); 

	
	








	temp = head;

	// This area cycles through the existing nodes untill the
	// next pointer of the referenced node is NULL, meaning it has 
	// reached the end of the linked list
	while (temp->next != NULL)
	{


		// Here it finds the current position of the linked list
		// node and checks to see if that position is marked 
		// in the dupes vector (the vector that recorded all positions with duplicate values)
		// and if it is, it prints the information of the student that has a duplicate ID number
		it = std::find(dupes.begin(), dupes.end(), i);
		if (it != dupes.end())
		{
			std::cout << "Duplicate student ID entry: \n";
			std::cout << "Name: " << temp->fName << " " << temp->lName << std::endl;
			std::cout << "ID Number: \n\n" << temp->idnum << std::endl;
		}
		
		i++;



		// In this program the recursive destructor is embedded into the 
		// output code
		Student* ptr = temp;
		temp = temp->next;
		delete ptr;
	}

//

	return 0;

}




void pushTenNodes(struct Student *node, struct Student *temp, std::vector<int> &dupes)
{


	// Sets up local duplicate check array to store ID numbers
	// entered so far
	int dupeCheck[RECORD_LENGTH], cmpInt;
	std::vector<int>::iterator it;



	for (int i = 0; i < RECORD_LENGTH; ++i)
	{


		// Data entry goes directly to the pointed to node
		std::cout << "Entering for record " << i+1 << std::endl;
		std::cout << "Enter first name: ";
		std::cin >> node->fName;

		std::cout << "Enter last name: ";
		std::cin >> node->lName;

		std::cout << "Enter ID number: ";
		std::cin >> node->idnum;
			
		dupeCheck[i] = node->idnum;

		std::cout << "Enter grade: ";
		std::cin >> node->grade;
		
		std::cout << "\n\n\n";	


		// Creates new node
		node = new Student;

		// Links existing referring node to the new node
		temp->next = node;

		// Sets the temp pointer to the newly created node
		temp = node;

	
	}



	// This area cycles through the entered ID's
	for (int i = 0; i < RECORD_LENGTH; ++i)
	{

		// The next nested loop cycles through the same
		// entered ID array except the starting position
		// is advanced by one, as to not identify itself as a duplicate
		for (int x = (i+1); x < RECORD_LENGTH; ++x)
		{

			// If there are duplicates from the compared element to the 
			// search element, the position the duplicates are found
			// will be pushed to a vector
			if (dupeCheck[i] == dupeCheck[x])
			{


				// This area checks to make sure that the positions being
				// pushed have already been pushed into the area
				// as to identify the duplicates only once
				it = std::find(dupes.begin(), dupes.end(), i);
			
			
				// The way this works is that if std::find does not find the
				// requested value (its third parameter), it returns an iterator
				// to the end of the vector
				if (it == dupes.end()) 
				{

					// Therefore if the 'it' iterator is equivalent to the pointed position
					// of dupes.end(), the std::find did not find the value i already
					// existing in the array
					dupes.push_back(i);
				}

				it = std::find(dupes.begin(), dupes.end(), x);
				if (it == dupes.end()) 
				{
					dupes.push_back(x);
				}
			}
		}
	}

		 


	return;
}	
			











