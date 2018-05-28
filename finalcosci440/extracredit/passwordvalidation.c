#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>



// Ncurses library for actively updating line of terminal 
// while typing. 
#include <ncurses.h>

#define MAX_PASSLEN 24


// Function to check password strength based on conditions
char *returnPassStrength(char pass[]);

int main()
{


    int ch, row, col, i = 0;
    char password[MAX_PASSLEN];
    char *strength;


    // Initscr() basically makes the program aware of the terminal
    // environment
    initscr();	

    // Gets the boundarys of the terminal    
    getmaxyx(stdscr,row,col);



    // Looks for 'q' as the sentinal value to end program
    while (ch != 'q')
    {

        // This function moves the curse to the first 2 arguments
        // (row,column), and uses the third argument as what to print
        // at the cursor location
        mvprintw(1,0,"Password strength:");


        // Moves the cursor to (row,col) parameters
        // Plus i for moving the cursor as the user types
        move(2,0+(i));


        // Getch() to get input, which by default
        // echos input onto screen
        ch = getch();

        // Looks for DEL character (backspace on standard keyboards)
        // If not found, add character to password array, as long
        // as there is still space left in the array
        if (ch != 127)
        {
            if (i > MAX_PASSLEN)
            {
                move(5,0);
                printw("Password too long");
            }
            else
            {
                password[i++] = ch;
            }
            
        }
        // If DEL is found, then decrement the index for password
        // and also fill deleted spot with null terminaator
        //
        // Then also to make ncurses show empty space where deleted
        // move the curse back 3 positions from current (1 for current letter)
        // (2 for backspace output characters) and print spaces
        //
        // Refresh to update the window
        else
        {
            password[--i] = '\0';
            getyx(stdscr,row,col);
            move(row,col-3);
            printw("   ");
            refresh();
        }

        // If all is well with the entry,
        // run the current typed password to the password
        // strength checking function, which will return a pointer
        // to a string containing the message 
        // for whether the string is strong or not
        strength = returnPassStrength(password);
        if (strength)
        {
            move(3,0);
            clrtoeol();
            mvprintw(3,0,"%s\r", strength);
            // Dont forget to free the string allocated by malloc
            free(strength);
        }

        // Update the window
        refresh();
    }
    endwin();

    return 0;
}






char *returnPassStrength(char pass[])
{


    // Counters for uppers, lowers, alphas, digits, 
    // and specials and length    
    int u,l,a,d,sp, len;
    char c;
   
     
    
    u = l = a = d = sp = len = 0;



    for(int i = 0; i < MAX_PASSLEN; ++i)
    {
        c = pass[i];
        c ? len++ : c;

        // Increment counter for corresponding character
        // type
        (isupper(c)) ? (u++) : (u);
        (islower(c)) ? (l++) : (l);
        (isalpha(c)) ? (a++) : (a);
        (isdigit(c)) ? (d++) : (d);
    

        // Increment special counter for the
        // selected special characters
        switch(c)
        {
            case '!':
                sp++;
                break;

            case '#':
                sp++;
                break;


            case '$':
                sp++;
                break;


            case '&':
                sp++;
                break;

            case '~':
                sp++;
                break;
                
            case '_':
                sp++;
                break;

        }
    }


    // Strength guidelines
    // Must be at least 8 characters long
    // Have one uppercase, and 2 digits
    // for to pass valid check
    if( (len < 8) || (u == 0) || (d < 2) )
    {
        char *invalid = (char *) malloc(sizeof(char)*256);
        strcpy(invalid,"Invalid Password");

        // Depending on which asset is missing, the invalid string
        // will have the appropriate error messages concatenated
        if (len < 8)
        {
            strcat(invalid, " - Not enough characters");
        }
        if (u == 0)
        {
            strcat(invalid, " - Need at least one uppercase");
        }
        if (d < 2)
        {
            strcat(invalid, " - Need at least two numeric digits");
        }
        if (sp == 0)
        {
            strcat(invalid, " - Need at least one special character");
        }
        return invalid;
    }
    
    // If it does pass the valid test, then  check the conditons
    // for password strength
    else
    {

        // If Only one uppercase and 2 digits (minimum required digits)
        // then weak
        if ((u < 2) && (d < 3))
        {
            char *weak = (char *) malloc(sizeof(char)*256);
            strcpy(weak, "Weak Password");
            return weak;
        }

        // Only one upper, but more than 3 digits and two special
        // then strong
        else if ((u < 2) && (d >= 3) && (sp >= 2))
        {
            char *strong = (char *) malloc(sizeof(char)*256);
            strcpy(strong, "Strong Password");
            return strong;
        }
        
        // More than two uppers, digits, specials, and more
        // then 14 characters then strongest
        else if ((u >= 2) && (d >= 2) && (sp >= 2) && (len >= 14))
        {
            char *strongest = (char *) malloc(sizeof(char)*256);
            strcpy(strongest, "Strongest Password");
            return strongest;
        }
        else
        // Otherwise weak
        {
            char *weak = (char *) malloc(sizeof(char)*25);
            strcpy(weak, "Weak Password");
            return weak;
        }
    }



    return NULL;



}




