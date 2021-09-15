#include "class.h"

using namespace std;

int main(){
    game g;

    ifstream in("all_scores.txt");
    int a;
    while (in >> a){
        g.max_score=max(a,g.max_score);
        g.last_score=a;
    }
    in.close();

    srand(time(NULL));
    initscr();
    start_color();

    while (1){
        printw("%s","2048 MENYU\n");
        printw("%s","1. Yangi o'yin\n");
        printw("%s","2. TOP 10\n");
        printw("%s","3. Yordam\n");
        printw("%s","4. Muallif haqida\n");
        printw("%s","5. Chiqish\n");
        printw("%s","Tanlash uchun mos raqam tugmachasini bosing.\n");
        refresh();

        char c=getchar();

        switch (c){
            case '1':
                g.new_game();
                g.game_process();
                break;

            case '2':
                g.scoreboard();
                break;

            case '3':
                g.help();
                break;

            case '4':
                g.about();
                break;

            case '5':
                refresh();
                endwin();
                return 0;
        }
        clear();
    }

    refresh();
    getch();
    endwin();
    return 0;
}