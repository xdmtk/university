#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

#include <ncurses.h>

#define MAX_PASSLEN 24


enum propertyTags{Uppers, Lowers, Alphas, Digits, Specials, Length};
char *returnPassStrength(char pass[]);

int main()
{
    int ch, row, col, i = 0;
    char password[MAX_PASSLEN] = "Yo fuck";
    char *strength;

    initscr();			
    getmaxyx(stdscr,row,col);

    while (ch != 'q')
    {
        mvprintw(1,0,"Password strength:");
        move(2,0+(i));
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




