#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include <iostream>

int main(void)
{	

   WINDOW *titleBox, *menuBox;
    
    initscr();
    titleBox= subwin(stdscr, 3, COLS, 0, 0 );
    menuBox= subwin(stdscr, 8, COLS, 4, 0);
   
    box(titleBox, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    box(menuBox, ACS_VLINE, ACS_HLINE);
  
    mvwprintw(titleBox, 1, 1, "CPPFW - Bienvenue dans le framework cpp pour HTML/CSS");
    mvwprintw(menuBox, 0, 2, "Sélectionner vos options");
    wrefresh(titleBox);
    wrefresh(menuBox);
    getch();
    endwin();
    
    free(titleBox);
    free(menuBox);
    

    return 0;


}