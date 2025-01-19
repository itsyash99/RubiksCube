#include "rubiksCube.h"
    
class rubiksCube3Dmodel : public rubiksCube{
private:

    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }

public:

    char cube[6][3][3] = {};

    rubiksCube3Dmodel(){
        // default rubik cube ( solved )
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override{
        char color = cube[int(face)][row][col];
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
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++){
                    if(cube[i][j][k] == getColorLetter(COLOR(i)))continue;
                    return false;
                }
            }
        }
        return true;
    }

    rubiksCube &u() override{
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    rubiksCube &uPrime() override{
        this->u();
        this->u();
        this->u();

        return *this;
    }

    rubiksCube &u2() override{
        this->u();
        this->u();

        return *this;
    }

    rubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

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

    // checks if 2 cubes are same or not
    bool operator==(const rubiksCube3Dmodel &r1) const{
        for(int i = 0;i<6;i++){
            for(int j = 0;j<3;j++){
                for(int k = 0;k<3;k++){
                    if(r1.cube[i][j][k] != cube[i][j][k])return false;
                }
            }
        }
        return true;
    }

    rubiksCube3Dmodel &operator=(const rubiksCube3Dmodel &r1){
        for(int i = 0;i<6;i++){
            for(int j = 0;j<3;j++){
                for(int k = 0;k<3;k++){
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const rubiksCube3Dmodel &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};


