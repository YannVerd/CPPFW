#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include <iostream>

void handleCursor(int& xCursor, int& yCursor, WINDOW* menuBox, const int& nbrOptions){
    int event = getch();
    switch (event)
    {
        case KEY_UP:
            if(yCursor > menuBox->_begy +1){
                yCursor--;
                move(yCursor, xCursor);
                wrefresh(menuBox);
            }
            handleCursor(xCursor, yCursor, menuBox, nbrOptions);
            break;
        case KEY_DOWN:
            if(yCursor < nbrOptions + menuBox->_begy){
                yCursor++;
                move(yCursor, xCursor);
                wrefresh(menuBox);
            }
            
            handleCursor(xCursor, yCursor, menuBox, nbrOptions);
            break;
        case 13: // Enter key
            printw("x");
            if(yCursor < nbrOptions + menuBox->_begy){
                yCursor++;
                wrefresh(menuBox);
            }
            move(yCursor, xCursor);
            handleCursor(xCursor, yCursor, menuBox, nbrOptions);
            
            break;
        default:
            break;
    }
}
int main(void)
{	

   WINDOW *titleBox, *menuBox;
    const int startYCursor = 5;
    const int startXCursor = 4;
    const int nbrOptions = 3;
    int xCursor = startXCursor;
    int yCursor = startYCursor;
    std::string options[nbrOptions] = {
        "index",
        "Portfolio",
        "Contact"
    };

    initscr();
    cbreak();
    nonl();
    noecho();
    keypad(stdscr, TRUE);
    titleBox = subwin(stdscr, 3, COLS, 0, 0 );
    menuBox = subwin(stdscr, 8, COLS, 4, 0);
    box(titleBox, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    box(menuBox, ACS_VLINE, ACS_HLINE);
    move(startYCursor, startXCursor);


   
    mvwprintw(titleBox, 1, 1, "CPPFW - Bienvenue dans le framework cpp pour HTML/CSS");
    mvwprintw(menuBox, 0, 2, "Sélectionner vos options");

    for( int i = 0; i < nbrOptions; i++){
        std::string str = "[ ] " + options[i];
        mvwprintw(menuBox, i+1, 3, str.c_str());
    }
    wrefresh(titleBox);
    wrefresh(menuBox);
    

    while(1){
        handleCursor(xCursor, yCursor, menuBox, nbrOptions);
    }

    endwin();
    
    free(titleBox);
    free(menuBox);
    
    

    return 0;


}