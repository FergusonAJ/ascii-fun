#include <ncurses.h>
#include <iostream>

int main(int argc, char** argv){
    WINDOW* window = initscr();
    WINDOW* miniWin = newwin(10,30,2,1);
    if(window == NULL){
        std::cerr << "Unable to initialize error!";
        return 0;
    }
    cbreak();
    noecho();
    keypad(window, 1);
    printw("Hello World!");
    refresh();
    for(char i = 32; i < 127; i++){
        waddch(window, i);
        refresh();
    }
    box(miniWin, 0, 0);
    wrefresh(miniWin);
    getch();
    endwin();
    return 0;
}
