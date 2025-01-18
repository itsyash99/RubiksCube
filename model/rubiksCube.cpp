#include "rubiksCubeGeneral.h"
#define space(x) for(int i = 0;i<x;i++)cout<<" ";
#define line cout<<"\n"

char rubiksCubeGeneral::getColorLetter(COLOR color){
    switch(color){
        case COLOR::GREEN : return 'G';
        case COLOR::YELLOW : return 'Y';
        case COLOR::ORANGE : return 'O';
        case COLOR::RED : return 'R';
        case COLOR::WHITE : return 'W';
        case COLOR::BLUE : return 'B';
    }
}

string rubiksCubeGeneral::getMove(MOVE ind){
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
    }
}

rubiksCubeGeneral &rubiksCubeGeneral::move(MOVE ind){
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
    }
}

rubiksCubeGeneral &rubiksCubeGeneral::invert(MOVE ind){
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}

void rubiksCubeGeneral::print() const{

    cout<<"RUBIK'S CUBE : \n\n";

    /*
    face(f);
    f1 : white,
    f2 : green,
    f3 : red,
    f4 : blue,
    f5 : orange,
    f6 : yellow
    */

    for(int i = 0;i<=8;i++){
        for(int j = 0;j<=11;j++){
            if(i>=0 && i<=2){
                if(j>=3 && j<=5){
                    // UP face
                    cout<<getColorLetter(getColor(FACE::UP,i%3,j%3));
                }else{
                    space(1)
                }
            }else if(i>=3 && i<=5){
                if(j>=0 && j<=2){
                    // LEFT face
                    cout<<getColorLetter(getColor(FACE::LEFT,i%3,j%3));
                }else if(j>=3 && j<=5){
                    // FRONT face
                    cout<<getColorLetter(getColor(FACE::FRONT,i%3,j%3));
                }else if(j>=6 && j<=8){
                    // RIGHT face
                    cout<<getColorLetter(getColor(FACE::RIGHT,i%3,j%3));
                }else if(j>=9 && j<=11){
                    // BACK face
                    cout<<getColorLetter(getColor(FACE::BACK,i%3,j%3));
                }
            }else if(i>=6 && i<=8){
                if(j>=3 && j<= 5){
                    // DOWN face
                    cout<<getColorLetter(getColor(FACE::DOWN,i%3,j%3));
                }else{
                    space(1);
                }
            }
        }
        line;
    }
    line;
}

vector<rubiksCubeGeneral::MOVE> rubiksCubeGeneral::randomShuffleCube(unsigned int times){
    vector<MOVE> moves_performed;
    srand(time(0));
    for(unsigned int i = 0;i<times;i++){
        unsigned int selected_move = (rand()%18);
        moves_performed.push_back(static_cast<MOVE>(selected_move));
        this->move(static_cast<MOVE>(selected_move));
    }
    return moves_performed;
}

string rubiksCubeGeneral::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {

        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t rubiksCubeGeneral::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t rubiksCubeGeneral::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}