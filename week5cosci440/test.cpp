/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		3/14/2018					     !
!									     #
#		Test #1 Due March 20th at the end of the lab		     !
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



#! Write a program that will do the following: 

	Narrative: Each line of data contains a salespersons name and sales per month amount 
		for the last three months. The data should be read into a structure. The program
		is to print for each record, the salespersons name and the largest monthly sales
		amount of the three months. 




	
	


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

#define MONTH_1 0 
#define MONTH_2 1 
#define MONTH_3 2



struct Record
{
	std::string firstName, lastName;
	int month1, month2, month3;
	
	// Because data entries are to be entered in a structure
	// and we do not know beforehand the amount of entries,
	// the *next pointer is going to be used for a linked list
	struct Record *next;
};


void readFileAndPushNode(struct Record *node, struct Record *temp, std::fstream &rFile);
void sortAndPrintNodeData(struct Record *temp);
inline bool valueEquivalent(int m1, int m2, int m3);
inline int getmLarge(int m1, int m2, int m3);



int main()
{

	// Creating first node
	struct Record* node = new Record;

	// Creating node start point
	struct Record* head = node;

	// Creating referencing pointer for already existing nodes
	struct Record* temp = node;





	std::fstream rFile;
	// Opening the file in read mode
	rFile.open("records.txt", std::ios::in);
	
	

	// Collects data from records file and arranges data
	// into a linked list of Record struct's 
	readFileAndPushNode(node, temp, rFile);
	
	// Close the file as soon as we are done using it
	rFile.close();



	// Sets the rolling pointer for the linked list
	// to the beginning node 
	temp = head;
	sortAndPrintNodeData(temp);











	// Recursive destructor for linked list starting
	// at the head
	temp = head;
	while (temp->next != NULL)
	{
		// Creates temporary pointer to temps current position
		Record* ptr = temp;

		// Advances temp to next node
		temp = temp->next;

		// Deletes previous position of temp, loops around
		// untill all nodes are deleted
		delete ptr;
	}

	// The point of linked list destructors is that nodes that are not
	// explicitly destroyed by the delete keyword are left behind in memory
	// (also known as a memory) leak
	//
	// In the case that this program were to be processing sensitive/important data
	// leaked memory can be extracted using special disassemblers/debuggers and exploited
	//

	return 0;

}




void readFileAndPushNode(struct Record *node, struct Record *temp, std::fstream &rFile)
{
	std::string line, ascii, c;
	std::string::iterator pos;
	int lineCounter = 0, dataField = 0;




	// Gets line from file one by one
	while (getline(rFile, line))
	{

		dataField = 0;
		// Skips first line of data, as it does not
		// have any data
		if (lineCounter == 0)
		{
			lineCounter++;
			continue;
		}

		

		// Uses an iterator to iterate through the contents of the line
		// extracted by getline, gets 5 data fields and terminates when complete
		for (pos = line.begin(); dataField < 5; ++pos, ++dataField)
		{	


			// Logic to extract fields from comma delimited file
			int i = 0;
			while ((*pos != ',') && (i < line.size()))
			{


				// Basically storing each character read in string 'c'
				c = *pos;

				// That string is appended to the ascii string to
				ascii.append(c);

				// The characters are appended untill a comma is reached
				++pos;
				++i;
			}	
			

			// dataField variable indicates which field the program
			// is reading from and stores the data in the appropriate place
			switch (dataField)
			{
				case 0:
					node->firstName = ascii;
					break;

				case 1:
					node->lastName = ascii;
					break;

				case 2:
					node->month1 = std::stoi(ascii.c_str());
					break;

				case 3:
					node->month2 = std::stoi(ascii.c_str());
					break;
			
				case 4:
					node->month3 = std::stoi(ascii.c_str());
					break;
			}
			

			// Clears the string to be written to again next iteration
			ascii.clear();


		}

			// Creates a new node in the list after all data has been entered
			// for a particular record, links the two records, and moves the rolling pointer 'temp'
			// to the location of the newly created node
			node = new Record;
			temp->next = node;
			temp = node;

	}




	return;
}	
			









void sortAndPrintNodeData(struct Record *temp)
{

	// This function is responsible for printing out the data 
	// contained within the nodes of the linked list
	//

	Record ph;
	int mLarge[3] = {0,0,0};
	int maxVal, i, records = 0;

	
	std::cout << std::fixed << std::setw(12) << "\n\n\tName\t\t\t";
	std::cout << "Month 1\tMonth 2\tMonth 3\n\n";

	while (temp->next != NULL)
	{
		records++;
		// Load data into local placeholder for easier sorting
		ph.firstName = temp->firstName;
		ph.lastName = temp->lastName;
		ph.month1 = temp->month1;
		ph.month2 = temp->month2;
		ph.month3 = temp->month3;



		// Advances temp to the next record
		temp = temp->next;


		// Formats the data to be printed using manipulators
		// setw() and fixed
		std::cout << std::fixed << std::setw(12);
		std::cout << ph.firstName << " ";
		std::cout << ph.lastName << "\t\t";

		// If there arent multiple top values in monthly sales
		// the sorting process is simple and can be done by
		// evaulating the largest
		if (!valueEquivalent(ph.month1, ph.month2, ph.month3))
		{	
			i = getmLarge(ph.month1, ph.month2, ph.month3);
			mLarge[i] += 1;
			
			
			switch (i)
			{
				case MONTH_1:
					std::cout << ph.month1 << "\t\t";
					break;

				case MONTH_2:
					std::cout << "\t" <<  ph.month2 << "\t";
					break;

				case MONTH_3:
					std::cout << "\t\t" <<  ph.month3;
					break;
			}
		}
		// Though if there are multiple top values for a particular
		// record, they need to be handled specially
		else
		{		

			// Determines the largest value
			maxVal = ph.month1;
			(ph.month2 >= maxVal) ? maxVal = ph.month2 : maxVal;
			(ph.month3 >= maxVal) ? maxVal = ph.month3 : maxVal;


			// Although this is probably inefficient and clunky
			// the ternary conditional statement doesn't allow more
			// than one expression to be executed after the condition
			// has been evaluated, since I need both to print the value
			// and increment the counter the appropriate highest month
			if (ph.month1 == maxVal)
			{
				std::cout << ph.month1 << "\t";
				mLarge[MONTH_1]++;
			}
			else
			{
				std::cout << "\t";
			}

			if (ph.month2 == maxVal)
			{
				std::cout << ph.month2 << "\t";
				mLarge[MONTH_2]++;
			}
			else
			{
				std::cout << "\t";
			}

			if (ph.month3 == maxVal)
			{
				std::cout << ph.month3 << "\t";
				mLarge[MONTH_3]++;
			}
			else
			{
				std::cout << "\t";
			}
		}

			std::cout << "\n"; 

	}
		

	std::cout << "\n\nTotal Month 1's that are the largest: " << mLarge[MONTH_1];
	std::cout << "\nTotal Month 2's that are the largest: " << mLarge[MONTH_2];
	std::cout << "\nTotal Month 3's that are the largest: " << mLarge[MONTH_3];
	std::cout << "\nTotal records processed: " << records << std::endl;

	return;



}



// This could be implemented in a single line conditional 
// statement, but is cleaner and quicker as an inlined 
// function
inline bool valueEquivalent(int m1, int m2, int m3)
{
	if( (m1 == m2) || (m1 == m3) || (m2 == m3) )
	{
		return true;
	}
	return false;
}
	




// This function gets the largest month of the 3 
// 
// Because the function returns relatively quick
// inlining the function saves runtime overhead by
// treating the calling of the function in the source as a 
// macro for the definition of the function, and embedding 
// the instructions directly in the line of execution
// instead of creating a new stack frame and pushing the arguments
// to that stack frame
inline int getmLarge(int m1, int m2, int m3)
{
	int maxval;
	maxval = std::max(m1, m2);
	
	if (maxval == m1)
	{
		maxval = std::max(m1, m3);
		if(maxval == m1)
		{
			
			return MONTH_1;
		}
		else
		{
			return MONTH_3;
		}
	}
	else
	{
		maxval = std::max(m2,m3);
		if (maxval == m2)
		{
			return MONTH_2;
		}
		else
		{
			return MONTH_3;
		}
	}

	// Corrupted data or std::max threw an exception
	exit(1);
}
			
