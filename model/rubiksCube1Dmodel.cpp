#include "rubiksCube.h"

class rubiksCube1Dmodel : public rubiksCube {

private : 

    static int getIndex(int ind,int row,int col){
        return (9*ind + 3*row + col); 
    }

    void rotateFace(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i * 3 + j] = cube[getIndex(ind, i, j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 0, i)] = temp_arr[getIndex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
    }

    // void rotateFace(int ind){
    //     vector<int> helper = {2,4,6,-2,0,2,-6,-4,-2};
    //     vector<char> temp;
    //     for(int i = ind*9;i<=ind*9 + 8;i++){
    //         temp.push_back(cube[i]);
    //     }
    //     for(int i = ind*9;i<=ind*9 + 8;i++){
    //         int x = i+helper[i%8];
    //         cube[x] = temp[i%9];
    //     }
    // }

public : 

    char cube[54] = {};

    rubiksCube1Dmodel(){
        for(int i = 0;i<54;i++){
            cube[i] = getColorLetter(COLOR(i/9));
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override{
        char color = cube[getIndex(int(face),row,col)];
        switch(color){
            case 'G' : return COLOR :: GREEN;
            case 'Y' : return COLOR :: YELLOW;
            case 'B' : return COLOR :: BLUE;
            case 'R' : return COLOR :: RED;
            case 'O' : return COLOR :: ORANGE;
            case 'W' : return COLOR :: WHITE;
        }
    }

    bool isSolved() const override{
        for(int i = 0;i<54;i++){
            if(this->cube[i]!=getColorLetter(COLOR(i/9)))return false;
        }
        return true;
    }

    rubiksCube &u() override{
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    }

    rubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    rubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    rubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    rubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    rubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    rubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    rubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    rubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    rubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    rubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    rubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    rubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    rubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    rubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    rubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    rubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    rubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const rubiksCube1Dmodel &r1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    rubiksCube1Dmodel &operator=(const rubiksCube1Dmodel &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];
        }
        return *this;
    }
};

struct Hash1d {
    size_t operator()(const rubiksCube1Dmodel &r1) const {
        string str = "";
        for (int i = 0; i < 54; i++) str += r1.cube[i];
        return hash<string>()(str);
    }
};