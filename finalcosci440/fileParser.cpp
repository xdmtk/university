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
#include <climits>



#include "fileParser.h"



InputParser::InputParser()
{

    Formatter menuWriter;
    menuWriter.getTerminalWidth();

    // Print program banner as part of InputParser object constructor

    menuWriter.centerText("    _______ __        ___                __           _         ___ ____",1);
    menuWriter.centerText("   / ____(_/ ___     /   |  ____  ____ _/ __  _______(______   <  // __ \\",1);
    menuWriter.centerText("  / /_  / / / _ \\   / /| | / __ \\/ __ `/ / / / / ___/ / ___/   / // / / /",1);
    menuWriter.centerText(" / __/ / / /  __/  / ___ |/ / / / /_/ / / /_/ (__  / (__  )   / _/ /_/ /",1);
    menuWriter.centerText("/_./   /_/_/\\___/  /_/  |_/_/ /_/\\__,_/_/\\__, /____/_/____/   /_(_\\____/",1);
    menuWriter.centerText("                           /____/",1);
    
    
    
    menuWriter.centerText("Author: Nicholas Martinez",1);
    menuWriter.centerText("COSCI 440 - Mari Rettke",1);
    menuWriter.centerText("Final Exam Program",1);
    menuWriter.centerText("5/22/2018",3);



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


void InputParser::readFileAndWordFrequency()
{
    Formatter obj;


    std::ifstream inputFile(_filename.c_str());
    std::string wordBuffer, wordBufferLower;


    while(inputFile >> wordBuffer)
    {
        // Get all words from input file

        // Convert word received to lowercase for map
        // entry, to get case-insenstive word freqeuncy
        obj.specialToLower(wordBuffer, wordBufferLower);


        // Storing word into map to calculate word frequency
        if (_wordCount[wordBufferLower] == 0)
        {
            _wordCount[wordBufferLower] = 1;
        }
        else
        {
            _wordCount[wordBufferLower]++;
        }
        wordBufferLower.clear();

        // Read file and store into _inputText
        _inputText.append(wordBuffer);
        _inputText.append(" ");

    }



    return;
}




void InputParser::printWordMap()
{
    std::map<std::string, int>::iterator iter;


    // Cross platform screen clearing using OS macros
#ifdef __linux__
    system("clear");
#endif

#ifdef WIN32
    system("cls");
#endif

    // Create Formatter object to center text
    Formatter obj;
    obj.getTerminalWidth();


    obj.centerText(" __    __              _     __ _     _",1);
    obj.centerText(" / / /\\ \\ \\___  _ __ __| |   / /(_)___| |_",1);
    obj.centerText(" \\ \\/  \\/ / _ \\| '__/ _` |  / / | / __| __|",1);
    obj.centerText(" \\  /\\  / (_) | | | (_| | / /__| \\__ \\ |_",1);
    obj.centerText("   \\/  \\/ \\___/|_|  \\__,_| \\____/_|___/\\__|",1);


    obj.centerText("  _  _     _  _     _  _     _  _     _  _",1);
    obj.centerText(" _| || |_ _| || |_ _| || |_ _| || |_ _| || |_",1);
    obj.centerText("  |_  ..  _|_  ..  _|_  ..  _|_  ..  _|_  ..  _|",1);
    obj.centerText("  |_      _|_      _|_      _|_      _|_      _|",1);
    obj.centerText("  |_||_|   |_||_|   |_||_|   |_||_|   |_||_|",1);
    obj.centerText("--------------------------------------------------------------------------",3);




    // Iterate through the map containing words and the number of times
    // they have been seen in the file
    for (iter = _wordCount.begin(); iter != _wordCount.end();)
    {

        std::string line;
        
        // Print three word/value entries per line
        for (int i = 0; i < 3; ++i)
        {

            // The reason this is in a try/catch block is because
            // for the last line that may or may not lack a third
            // word, a std::bad_alloc exception is thrown because
            // it would try an append a garbage value caused from
            // reading past the boundary of the map
            try
            {

                // Construct the line to print
                line.append(iter->first);
                line.append(" -> x");
                line.append(std::to_string(iter->second));


                // Dont print spaces if its the last word in the line
                if (i != 2)
                {
                    if (iter->first.size() >= 9)
                    {
                        line.append("          ");
                    }
                    else
                    {
                        line.append("               ");
                    }
                }


                // Increment the map iterator
                ++iter;
            }
            catch (std::bad_alloc& ba)
            {
                // Break from the loop on exception
                break;
            }
        }
        
        // Print the line using the formatter object
        obj.centerText(line,1);
        line.clear();
    }

    obj.centerText("--------------------------------------------------------------------------",3);
    return;
}







void InputParser::printCharFrequency()
{
    Formatter obj;
    obj.getTerminalWidth(); 

    std::string::iterator iter;
    std::string line;
    
    std::vector<int> sortedF;
    std::vector<int>::iterator iterSortedF;
    
    std::vector<char> sortedC;
    std::vector<char>::iterator iterSortedC;

    std::map<char,int>::iterator mIter;

    char c;

    
    // Retrieve characters from input text, store them in map
    // to count how many times seen in file
    for (iter = _inputText.begin(); iter != _inputText.end(); ++iter)
    {

        c = *iter;

        // Only store if its a letter
        if (isalpha(c))
        {

            // Ignore cases by converting all letters to lowercase
            c = tolower(c);

            // Increment the value on first time seeing letter
            // otherwise set value to 1
            if (_characterCount[c] == 0)
            {
                _characterCount[c] = 1;
            }
            else
            {
                _characterCount[c]++;
            }
        }
    }


    // Record initial size of _characterCount map
    // since line 367 erases elements
    int initialSize = _characterCount.size();

    // Iterate for as many entries in character frequency map
    for (int i = 0; i < initialSize; ++i)
    {

        // Set high value to lowest possible value
        int high = INT_MIN;


        for (mIter = _characterCount.begin(); mIter != _characterCount.end(); ++mIter)
        {
            // This quick algorithm will set the highest value key found
            // in the map to 'c' and its value to high
            if (mIter->second > high)
            {
                high = mIter->second;
                c = mIter->first;
            }
        }

        // After retrieving the most frequent character 
        // followed by its value, push those data items into
        // their respective vectors
        sortedC.push_back(c);
        sortedF.push_back(high);


        // Then erase the character found in map to avoid duplicate
        // vector entries
        _characterCount.erase(c);
    }


    // Set iterators of character and value vectors
    // to beginning
    iterSortedC = sortedC.begin();
    iterSortedF = sortedF.begin();

    for (int i = 0; iterSortedC != sortedC.end(); ++i, ++iterSortedC,++iterSortedF)
    {

        std::string line;
        
        // In order to get a proper cast from char to std::string, the append()
        // member function accepts a pair of range iterators that automatically
        // do the correct cast, where as the dereferenced iterator below isnt
        // necessary because to_string will not store an improperly casted value
        //
        line.append(sortedC.begin()+i, sortedC.begin()+i+1);
        
        line.append(" -> x");
        
        line.append(std::to_string(*iterSortedF));
      
      
        // If the number value has less than two digits,
        // apply an extra space to keep good formatting
        if (*iterSortedF < 10)
        {
            line.append(" ");
        }
        if (i == 0)
        {
            obj.centerText("Most to Least Frequent",2);
        }
        obj.centerText(line,1);
        line.clear();

            
        
    }


    return;
}
        


    




















