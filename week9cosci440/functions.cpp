/*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
!									     #
#									     !
!	Programmer: 	Nick Martinez					     #
#	Class:		COSCI 440 - TUE 5:45 - 10:00PM			     !
!	Instructor:	Mari Rettke					     #
#	Date:		4/13/2018					     !
!									     #
#	                Lab Assignment: Functions                            !	
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
                





#! The following is a structure template: 
    struct box
    {
        char maker[40];
        float height;
        float width;
        float length;
        float volume;
    };

    
        a) Write a function that has a reference to a box structure as its formal
            arguments and displays the value of each member. 

        b) Write a function that has a reference to a box structure as its formal
            argument and sets the volume member to the product of the 
            other three dimensions


(Section is commented out via the extended line comment syntax rather than //)
/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <cstring>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showBox(box &b);
void setBox(box &b);



int main()
{
    

   box b;
   setBox(b);
 
   return 0;

    
    
}


// Function that sets the volume member to the 
// product of the other three dimensions
//
// Assuming you want us to collect dimension info inside
// function rather than pass them as parameters
void setBox(box &b)
{

    std::string maker;
    std::cout << "\n\nEnter maker: ";
    std::getline(std::cin, maker, '\n');

    strcpy(b.maker, maker.c_str());

    std::cout << "\n\nEnter height: ";
    std::cin >> b.height;


    std::cout << "\n\nEnter width: ";
    std::cin >> b.width;


    std::cout << "\n\nEnter length: ";
    std::cin >> b.length;

    b.volume = (b.height * b.width * b.length);
    

    showBox(b);
}

// Function that displays value of each member
void showBox(box &b)
{
    std::cout << "\n\nMaker: " << b.maker << std::endl;
    std::cout << "Height: " << b.height << std::endl;
    std::cout << "Width: " << b.width << std::endl;
    std::cout << "Length: " << b.length << std::endl;
    std::cout << "Volume: " << b.volume << std::endl;
}

