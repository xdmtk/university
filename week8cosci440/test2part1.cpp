/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		4/4/2018					     !
!									     #
#		Test #2 Due April 9th at the end of the lab		     !
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



#! For the final result you must be able to read the entire attatched data file. 
	To get started, either create a small file, 3 or 4 lines. Use that to read
	in the file and fill the structure when everything works. Use the entire 
	datafile

	You must use the data that is attatched. Create the textfile (use notepad).

	The finished file will look like the attatch data file.


	PART 1: 
		Create a text file by entering user input from the keyboard.
		The data for the file is attatched. Each line contains the last and first,
		name of a person, the letter S or N and two integer numbers

			Print a parer list of the text file after it has been
			created. Turn this in along with the program that creates the file.
			The final text file should match exactly the listing on the 
			paper provided.


	PART 2:
		Menu for this test (?????)
		
		1. Enter data from keyboard to create the file
		2. Read data from file (send empty structure to the function)
		3. Print the report (send structure with the data to the function
					to print)
		4. exit


		Read the text from the data file into a structure and print it out
		In the listing (print out), print the first name first, and then the last
		name followed by the other data in the same record. 





		QUESTIONS: 
			At line 47 you say to create the textfile to use in notepad,
			but in both part 1 and part 2, you want the program 
			to create the textfile (via user input)?



	
THIS PROGRAM WILL BE PART 1	


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




std::string cwriteFile(void);
void creadFile(std::string filename);


int main()
{

	std::string filename = cwriteFile();
	creadFile(filename);

	return 0;

}








std::string cwriteFile(void)
{

	// Gives user option to submit filename
	// assume good input...
	std::string filename;
	std::cout << "Please enter filename to write records to: ";
	std::cin >> filename;


	// Opens file
	std::fstream outputFile(filename,std::fstream::out);
	

	// Variables for input
	std::string first, last, sOrN, yN;
	int num1, num2, i = 1;
	

	// Print title
	outputFile << std::right <<  std::setw(40) << "airline test\n";


	do
	{
		// Start input sequence
		std::cout <<"\n\nEntering for Record " << i++ << "\n";
		std::cout <<"# # # # # # # # # # # # # # # # # # # # # # \n";


		std::cout << "Enter first name: ";
		std::cin >> first;


		std::cout << "Enter last name: ";
		std::cin >> last;


		std::cout << "Enter S or N: ";
		std::cin >> sOrN;


		std::cout << "Enter integer 1: ";
		std::cin >> num1;


		std::cout << "Enter integer 2: ";
		std::cin >> num2;



		// Write formatted data
		outputFile << std::left << std::setw(20) << last+" "+first;
		outputFile << std::left << std::setw(10) << sOrN;
		outputFile << std::left << std::setw(10) << num1;
		outputFile << std::left << std::setw(10) << num2 << "\n";


		// Ask for more input
		std::cout << "Enter more records? (y/N):\n";
		std::cin >> yN;


	}while (yN == "Y" || yN == "y");


	// Returns filename for read function to open file
	return filename;
}










void creadFile(std::string filename)
{
	std::fstream inFile(filename, std::fstream::in);
	std::string line;	
	


	std::cout << "\n\n\nDisplaying Records:\n\n";


	// Get lines from file until EOF
	while (std::getline(inFile, line))
	{
		// Print lines
		std::cout << line << "\n";
	}
	return;

}



