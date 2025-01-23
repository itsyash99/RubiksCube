#include "../model/rubiksCube.h"
#include<bits/stdc++.h>
using namespace std;

template<typename T,typename H>

class DFS_solver{

private : 

    vector<rubiksCube::MOVE> moves;
    int max_search_depth;

    bool dfs(int depth){
        if(obj.isSolved())return true;
        if(depth > max_search_depth)return false;
        for(int i = 0;i<18;i++){
            obj.move(rubiksCube::MOVE(i));
            moves.push_back(rubiksCube::MOVE(i));
            if(dfs(depth+1))return true;
            moves.pop_back();
            obj.invert(rubiksCube::MOVE(i));
        }
        return false;
    }   

public : 

    T obj;
    DFS_solver(T cube,int max_search_depth = 20){
        obj = cube;
        this->max_search_depth = max_search_depth;
    }

    vector<rubiksCube::MOVE> solve(){
        dfs(1);
        return moves;
    }

};

