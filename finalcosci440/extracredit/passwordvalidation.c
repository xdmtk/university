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
    char password[MAX_PASSLEN] = "Yo fuck";
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
        else
        {
            password[--i] = '\0';
            getyx(stdscr,row,col);
            move(row,col-3);
            printw("   ");
            refresh();
        }
        strength = returnPassStrength(password);
        if (strength)
        {
            move(3,0);
            clrtoeol();
            mvprintw(3,0,"%s\r", strength);
            free(strength);
        }
        refresh();
    }
    endwin();

    return 0;
}






char *returnPassStrength(char pass[])
{
    
    int u,l,a,d,sp, len;
    char c;
    bool valid;
   
     
    
    u = l = a = d = sp = len = 0;



    for(int i = 0; i < MAX_PASSLEN; ++i)
    {
        c = pass[i];
        c ? len++ : c;


        (isupper(c)) ? (u++) : (u);
        (islower(c)) ? (l++) : (l);
        (isalpha(c)) ? (a++) : (a);
        (isdigit(c)) ? (d++) : (d);
    
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

    if( (len < 8) || (u == 0) || (d < 2) )
    {
        char *invalid = (char *) malloc(sizeof(char)*256);
        strcpy(invalid,"Invalid Password");
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
    else
    {
        if ((u < 2) && (d < 3))
        {
            char *weak = (char *) malloc(sizeof(char)*256);
            strcpy(weak, "Weak Password");
            return weak;
        }
        else if ((u < 2) && (d >= 3) && (sp >= 1))
        {
            char *strong = (char *) malloc(sizeof(char)*256);
            strcpy(strong, "Strong Password");
            return strong;
        }
        else if ((u >= 2) && (d >= 2) && (sp >= 2) && (len >= 14))
        {
            char *strongest = (char *) malloc(sizeof(char)*256);
            strcpy(strongest, "Strongest Password");
            return strongest;
        }
        else
        {
            char *weak = (char *) malloc(sizeof(char)*25);
            strcpy(weak, "Weak Password");
            return weak;
        }
    }



    return NULL;



}




