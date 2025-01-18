#include "bits/stdc++.h"

using namespace std;

class rubiksCubeGeneral {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const = 0;

    static string getMove(MOVE ind);

    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);

    rubiksCubeGeneral &move(MOVE ind);

    rubiksCubeGeneral &invert(MOVE ind);

    virtual rubiksCubeGeneral &f() = 0;

    virtual rubiksCubeGeneral &fPrime() = 0;

    virtual rubiksCubeGeneral &f2() = 0;

    virtual rubiksCubeGeneral &u() = 0;

    virtual rubiksCubeGeneral &uPrime() = 0;

    virtual rubiksCubeGeneral &u2() = 0;

    virtual rubiksCubeGeneral &l() = 0;

    virtual rubiksCubeGeneral &lPrime() = 0;

    virtual rubiksCubeGeneral &l2() = 0;

    virtual rubiksCubeGeneral &r() = 0;

    virtual rubiksCubeGeneral &d() = 0;

    virtual rubiksCubeGeneral &dPrime() = 0;

    virtual rubiksCubeGeneral &d2() = 0;

    virtual rubiksCubeGeneral &rPrime() = 0;

    virtual rubiksCubeGeneral &r2() = 0;

    virtual rubiksCubeGeneral &b() = 0;

    virtual rubiksCubeGeneral &bPrime() = 0;

    virtual rubiksCubeGeneral &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};
