#include "../model/rubiksCube.h"
#include<bits/stdc++.h>
using namespace std;

template<typename T,typename H>
class BFS_solver{

private:

    vector<rubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T,rubiksCube::MOVE,H> moves_done;

    T bfs(){
        queue<T> q;
        q.push(rubikcube_tosolve);
        visited[rubikcube_tosolve] = true;
        while(!q.empty()){
            T cube_state = q.front();
            q.pop();
            if(cube_state.isSolved()){
                return cube_state;
            }
            for(int i = 0;i<18;i++){
                auto curr_move = rubiksCube::MOVE(i);
                cube_state.move(curr_move);
                if(!visited[cube_state]){
                    visited[cube_state] = true;
                    moves_done[cube_state] = curr_move;
                    q.push(cube_state);
                }
                cube_state.invert(curr_move);
            }
        }
        rubikcube_tosolve.print();
        return rubikcube_tosolve;
    }

public:

    T rubikcube_tosolve;
    T rubikcube_tosolve2;

    BFS_solver(T cube){
        rubikcube_tosolve = cube;
        rubikcube_tosolve2 = cube;
    }

    vector<rubiksCube::MOVE> solve(){
        T solvedcube = bfs();
        assert(solvedcube.isSolved());
        T curr_cube = solvedcube;
        cout<<(curr_cube == rubikcube_tosolve2)<<"\n";
        while(!(curr_cube == rubikcube_tosolve)){
            rubiksCube::MOVE curr_move = moves_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubikcube_tosolve = solvedcube;
        reverse(moves.begin(),moves.end());
        return moves;
    }

};