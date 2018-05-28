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
    raw();			
    getmaxyx(stdscr,row,col);

    while (ch != 'q')
    {
        mvprintw(1,0,"Password strength:");
        move(2,0+(i));
        ch = getch();
        password[i++] = ch;

        strength = returnPassStrength(password);
        refresh();
    }
    
    if (strength)
    {
        mvprintw(3,0,"%s", strength);
        free(strength);
    }
    refresh();
    system("sleep 4");
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
        char *invalid = (char *) malloc(sizeof(char)*25);
        strcpy(invalid,"Invalid Password");
        return invalid;
    }
    else
    {
        int properties[] = {u,l,a,d,sp,len};
        
    }



    return NULL;



}




