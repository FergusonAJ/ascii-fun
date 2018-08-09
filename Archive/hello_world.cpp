#include <ncurses.h>
#include <iostream>

int main(int argc, char** argv){
    std::cout << "Foo" << std::endl;
    initscr();
    printw("Hello World!");
    refresh();
    char ch = 0;
    while(ch != ' '){
        ch = getch();
        printw(&ch);
    }
    
    endwin();
    return 0;
}
