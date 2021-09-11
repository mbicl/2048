#include "class.h"

bool val_check = false;

void game::game_process(){
    clear();
    this->max_score=std::max(this->max_score,this->score);
    this->max_last();
    if(!val_check) this->new_value();
    this->print();

    if (this->check()){
        this->last_score=this->score;
        std::ofstream out("all_scores.txt",std::ofstream::app);
        out << this->score << '\n';
        this->score=0;
        out.close();

        printw("%s", "Yutqazdingiz\n");
        printw("%s","Yangi o'yin uchun Y tugmasini, chiqish uchun boshqa istalgan tugmani bosing.\n");
        refresh();
        char c=getchar();

        if (c=='y'){
            this->new_game();
            this->game_process();
        }
        return;
    }

    char c=getchar();

    switch (c){
        case 'a':
            this->left();
            break;

        case 'd':
            this->right();
            break;

        case 'w':
            this->up();
            break;

        case 's':
            this->down();
            break;
    }

    this->game_process();
    // getch();
}

void game::new_game(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            table[i][j]=0;
        }
    }
}

void game::new_value(){
    std::vector<std::pair<int,int>> vc;

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (table[i][j]==0){
                vc.emplace_back(i,j);
            }
        }
    }

    if (vc.empty()){
        return;
    }

    int k=rand()%vc.size();

    table[vc[k].first][vc[k].second]=2;
}

void game::scoreboard(){
    clear();
    
    std::ifstream in("all_scores.txt");
    std::vector<int> vc;
    int a;

    while (in >> a) {
        vc.push_back(a);
    }

    std::sort(vc.begin(),vc.end(),std::greater<int>());

    a=0;
    
    for (int i:vc){
        a++;
        printw("%d. %d\n",a,i);
        if (a>10) break;
    }
    printw("%s","\nBosh menyuga qaytish uchun istalgan tugmani bosing.");
    refresh();

    getch();
}

void game::help(){
    clear();
    printw("%s", "O'ynash uchun A, W, S, D tugmalaridan foydalaning.\n");
    printw("%s", "\nBosh menyuga qaytish uchun istalgan tugmani bosing.\n");
    refresh();
    getch();
}

void game::about(){
    clear();
    printw("%s", "Muallif: Baxriddinov Maqsud.\nToshkent axborot texnologiyalari universiteti Samarqand filiali \nDasturiy injiniring yo'nalishi 2-kurs talabasi.");
    printw("%s", "\nTelegram: t.me/MBI_n1\nTelegram kanal: t.me/cp_club_mbi\n\n");
    printw("Bosh menyuga qaytish uchun istalgan tugmani bosing\n");
    refresh();
    getch();
}

void game::max_last(){

    printw("Best: %d Last: %d Score: %d \n", this->max_score, this->last_score, this->score);

    refresh();
}

void game::up(){
    val_check=true;

    std::deque<int> vc;

    for (int i=0; i<4; i++){
        vc.clear();
        for (int j=0; j<4; j++){
            if (table[j][i]!=0) vc.push_back(table[j][i]);
        }
        for (int j=1; j<4; j++){
            if (table[j-1][i]==table[j][i] && table[j][i]!=0 || table[j-1][i]==0 && table[j][i]>0){
                val_check=false;
            }
        }

        for (int j=1; j<vc.size(); j++){
            if (vc[j]==vc[j-1]){
                vc[j-1]*=2;

                this->score+=vc[j-1];

                vc.erase(vc.begin()+j);
            }
        }

        for (int j=0; j<4; j++){
            if (j<vc.size()){
                table[j][i]=vc[j];
            }
            else {
                table[j][i]=0;
            }
        }
    }
}

void game::down(){
    val_check=true;

    std::deque<int> vc;

    for (int i=0; i<4; i++){
        vc.clear();
        for (int j=3; j>=0; j--){
            if (table[j][i]!=0) vc.push_back(table[j][i]);
        }
        for (int j=2; j>=0; j--){
            if (table[j+1][i]==table[j][i] && table[j][i]!=0 || table[j+1][i]==0 && table[j][i]>0){
                val_check=false;
            }
        }

        for (int j=1; j<vc.size(); j++){
            if (vc[j]==vc[j-1]){
                vc[j-1]*=2;

                this->score+=vc[j-1];

                vc.erase(vc.begin()+j);
            }
        }

        for (int j=3,k=0; j>=0; j--,k++){
            if (k<vc.size()){
                table[j][i]=vc[k];
            }
            else {
                table[j][i]=0;
            }
        }
    }
}

void game::left(){
    val_check=true;

    std::deque<int> vc;

    for (int i=0; i<4; i++){
        vc.clear();
        for (int j=0; j<4; j++){
            if (table[i][j]!=0) vc.push_back(table[i][j]);
        }
        for (int j=1; j<4; j++){
            if (table[i][j-1]==table[i][j] && table[i][j]!=0 || table[i][j-1]==0 && table[i][j]>0){
                val_check=false;
            }
        }

        for (int j=1; j<vc.size(); j++){
            if (vc[j]==vc[j-1]){
                vc[j-1]*=2;

                this->score+=vc[j-1];

                vc.erase(vc.begin()+j);
            }
        }

        for (int j=0; j<4; j++){
            if (j<vc.size()){
                table[i][j]=vc[j];
            }
            else {
                table[i][j]=0;
            }
        }
    }
}

void game::right(){
    val_check=true;

    std::deque<int> vc;

    for (int i=0; i<4; i++){
        vc.clear();
        for (int j=3; j>=0; j--){
            if (table[i][j]!=0) vc.push_back(table[i][j]);
        }
        for (int j=2; j>=0; j--){
            if (table[i][j+1]==table[i][j] && table[i][j]!=0 || table[i][j+1]==0 && table[i][j]>0){
                val_check=false;
            }
        }

        for (int j=1; j<vc.size(); j++){
            if (vc[j]==vc[j-1]){
                vc[j-1]*=2;

                this->score+=vc[j-1];

                vc.erase(vc.begin()+j);
            }
        }

        for (int j=3,k=0; j>=0; j--,k++){
            if (k<vc.size()){
                table[i][j]=vc[k];
            }
            else {
                table[i][j]=0;
            }
        }
    }
}

void game::print(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            for (int k=0;k<6-std::to_string(table[i][j]).size();k++)
                printw(" ");
            printw("%d", table[i][j]);
        }
        printw("\n\n");
    }
    refresh();
}

bool game::check(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (table[i][j]==0){
                return 0;
            }
            if (j<3){
                if (table[i][j]==table[i][j+1]){
                    return 0;
                }
            }
            if (i<3){
                if (table[i][j]==table[i+1][j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}