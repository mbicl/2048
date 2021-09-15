#ifndef CLASS_H
#define CLASS_H

#include <bits/stdc++.h>
#include <ncurses.h>
#include <curses.h>

class game {
private:

    int score=0;
    int table[4][4];

public:

    int max_score=0;
    int last_score=0;
    
    void game_process();
    void new_game();
    void new_value();
    void up();
    void down();
    void left();
    void right();
    void scoreboard();
    void max_last();
    void help();
    void about();
    void print();
    bool check();
    
};

#endif