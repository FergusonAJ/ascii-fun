#include <ncurses.h>
#include <iostream>

int main(int argc, char** argv){
    WINDOW* window = initscr();
    if(window == NULL){
        std::cerr << "Unable to initialize error!";
        return 0;
    }
    start_color();
    for(char i = 0; i < 8; i++){
        for(char j = 0; j < 8; j++){
            init_pair(i*8 + j + 1, i, j);
        }
    }
    cbreak();
    noecho();
    keypad(window, 1);
    printw("Hello World!");
    refresh();
    for(char i = 32; i < 127; i++){
        attron(COLOR_PAIR(i-31));
        waddch(window, i);
        attroff(COLOR_PAIR(i-31));
        refresh();
    }
    getch();
    endwin();
    return 0;
}
