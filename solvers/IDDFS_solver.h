#include "../model/rubiksCube.h"
#include<bits/stdc++.h>
using namespace std;

template<typename T , typename H>

class IDDFS_solver{

private:

    vector<rubiksCube::MOVE> moves_to_solve;

    int max_search_depth = 20;

    bool dfs(int depth){
        if(rubikscube_to_solve.isSolved())return true;
        if(depth > max_search_depth)return false;
        for(int i = 0;i<18;i++){
            rubikscube_to_solve.move(rubiksCube::MOVE(i));
            moves_to_solve.push_back(rubiksCube::MOVE(i));
            if(dfs(depth+1))return true;
            moves_to_solve.pop_back();
            rubikscube_to_solve.invert(rubiksCube::MOVE(i));
        }
        return false;
    } 

public:

    T rubikscube_to_solve;

    IDDFS_solver(T obj){
        rubikscube_to_solve = obj;
    }

    vector<rubiksCube::MOVE> solve(){
        for(int i = 1;i<=20;i++){
            max_search_depth = i;
            if(dfs(1)){
                return moves_to_solve;
            }
        }
    }

};