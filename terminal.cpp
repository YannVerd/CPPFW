#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include <iostream>

int main(void)
{	

   WINDOW *titleBox, *menuBox;
    const int startXCursor = 5;
    const int startYCursor = 3;
    initscr();
    keypad(stdscr, TRUE);
    titleBox= subwin(stdscr, 3, COLS, 0, 0 );
    menuBox= subwin(stdscr, 8, COLS, 4, 0);
    box(titleBox, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    box(menuBox, ACS_VLINE, ACS_HLINE);
    move(startXCursor, startYCursor);

   
    mvwprintw(titleBox, 1, 1, "CPPFW - Bienvenue dans le framework cpp pour HTML/CSS");
    mvwprintw(menuBox, 0, 2, "Sélectionner vos options");
    wrefresh(titleBox);
    wrefresh(menuBox);
    

    while(1){
        int c = getch();
        move(startXCursor, startYCursor);
        clrtoeol();
        if(c == KEY_UP){
            printw("key up pressed");
        }
        if(c == KEY_DOWN){
            printw("key down pressed");
        }
        
        wrefresh(menuBox);
    }

    endwin();
    
    free(titleBox);
    free(menuBox);
    

    return 0;


}