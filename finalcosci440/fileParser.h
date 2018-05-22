/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		5/21/2018					     !
!									     #
#	       FINAL EXAM  HEADER FILE !!!!                                  !
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
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>



#ifndef FILEPARSER_H
#define FILEPARSER_H


class Formatter
{

    public: 

        void getTerminalWidth();

        void centerText(std::string line, int newlines);
        void leftCenterRight(std::string left, std::string center, std::string right, int newlines);
    

        void specialToLower(std::string regularString, std::string &lowerString);

        inline bool checkLineFit(int l1, int l2, int l3);
        inline bool checkLineFit(int l1);
        
        inline void printSpaces(int spaces);
        inline void printNewLines(int newlines);

        
    private:

        int _twidth;      

};


class InputParser
{
    public:   
        
        InputParser();

        bool verifyFileExistence();
        void readFileAndWordFrequency();
        void printWordMap();



    private:

        std::string _filename;
        std::string _inputText;

        std::map<char,int> _characterCount;
        std::map<std::string,int> _wordCount;
        
        

};



#endif

