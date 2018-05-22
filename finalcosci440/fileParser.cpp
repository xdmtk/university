/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/21/2018					     !
!									     #
#	       FINAL EXAM  INPUT PARSING SOURCE FILE !!!!                    !
!                               	   				     #
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



#! Write a c++ program which accepts the name of a text file, reads in that file, and prints out
    the following information about the file:

            A list of all letters (A through Z) in that file, disregarding case (e.g. count "a" and "A"
            as two occurences of the same letter A), ordered with the most frequently used letter first
            and the least frequently used letter last, along with the number of times each letter was
            used

            An alphabetized list of a ll distinct words in that file with the number of times each
            word was used

            The average number of letters in a word

            The average num ber of words in a sentence



    2. Create a folder with "your name S 2018" and put the files for your application in the folder.
        For example, C Siller - S 2018



    Use the following example paragraph to setup your test input text file:


        Any experienced programmer engaged in writing programs for use by others knows that,
        once his program is working correctly, good output is a must. Few people really care how much
        time and trouble a programmer has spent in designing and debugging a program. Most people
        only see the results. Often, by the time a programmer has finished tackling a difficult problem,
        any output may look great. The programmer knows what it means and how to interpret it. However,
        the same cannot be said for others, or even for the programmer himself six months hence.






    You need to create at least one class with member functions and use it in your program




(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*//////////////////////////////////////////////////////////////////////////g


#include <iostream>
#include <iomanip>
#include <fstream>

#include "fileParser.h"



InputParser::InputParser()
{

    Formatter menuWriter;
    menuWriter.getTerminalWidth();

    // Print program banner as part of InputParser object constructor

    std::cout << "    _______ __        ___                __           _         ___ ____" << std::endl;
    std::cout << "   / ____(_/ ___     /   |  ____  ____ _/ __  _______(______   <  // __ \\" << std::endl;
    std::cout << "  / /_  / / / _ \\   / /| | / __ \\/ __ `/ / / / / ___/ / ___/   / // / / /" << std::endl;
    std::cout << " / __/ / / /  __/  / ___ |/ / / / /_/ / / /_/ (__  / (__  )   / _/ /_/ /" << std::endl;
    std::cout << "/_./   /_/_/\\___/  /_/  |_/_/ /_/\\__,_/_/\\__, /____/_/____/   /_(_\\____/" << std::endl;
    std::cout << "                           /____/\n\n\n";
  

    // Reusing formatting code from previous assignments to make layout 
    // look nice
    
    menuWriter.centerText("Please select your file from the current working directory listing:", 1);
    menuWriter.centerText("--------------------------------------------", 2);



// Portable file directory listing
//
// Executes certain system commands based on operating system detect
#ifdef _WIN32
    system("dir");
#endif 

#ifdef __linux__
    system("ls --color=auto");
#endif



}


bool InputParser::verifyFileExistence()
{

    
    std::cout << "\n\nEnter file to read: ";
    std::cin >> _filename;

    std::ifstream f(_filename.c_str());
    return f.good();


}


void InputParser::wordFrequency()
{
    Formatter obj;


    std::ifstream inputFile(_filename.c_str());
    std::string wordBuffer, wordBufferLower;


    while(inputFile)
    {
        // Get all words from input file
        inputFile >> wordBuffer;
        
        // Convert word received to lowercase for map 
        // entry, to get case-insenstive word freqeuncy
        obj.specialToLower(wordBuffer, wordBufferLower);    
        

        // Storing word into map to calculate word frequency
        if (_wordCount[wordBufferLower] == 0)
        {
            _wordCount[wordBufferLower] = 0;
        }
        else
        {
            _wordCount[wordBufferLower]++;
        }
        wordBufferLower.clear();
        _inputText.append(wordBuffer);
        
    }

    std::cout << _inputText;


    return;
}
