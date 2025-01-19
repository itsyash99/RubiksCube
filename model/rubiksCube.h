#ifndef RUBIKSCUBESOLVER_RUBIKSCUBE_H
#define RUBIKSCUBESOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class rubiksCube {
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

    rubiksCube &move(MOVE ind);

    rubiksCube &invert(MOVE ind);

    virtual rubiksCube &f() = 0;

    virtual rubiksCube &fPrime() = 0;

    virtual rubiksCube &f2() = 0;

    virtual rubiksCube &u() = 0;

    virtual rubiksCube &uPrime() = 0;

    virtual rubiksCube &u2() = 0;

    virtual rubiksCube &l() = 0;

    virtual rubiksCube &lPrime() = 0;

    virtual rubiksCube &l2() = 0;

    virtual rubiksCube &r() = 0;

    virtual rubiksCube &d() = 0;

    virtual rubiksCube &dPrime() = 0;

    virtual rubiksCube &d2() = 0;

    virtual rubiksCube &rPrime() = 0;

    virtual rubiksCube &r2() = 0;

    virtual rubiksCube &b() = 0;

    virtual rubiksCube &bPrime() = 0;

    virtual rubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif