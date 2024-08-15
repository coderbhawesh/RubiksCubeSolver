//
// Created by Bhawesh Kumar Pandit on 15/08/24.
//
#include <iostream>
#include <vector>
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"
#ifndef RUBIKSCUBESOLVER_IDDFSSOLVER_H
#define RUBIKSCUBESOLVER_IDDFSSOLVER_H

template<typename T,typename H>
class IDDFSSolver{
private:
    vector<RubiksCube::MOVE> moves;
    int max_search_depth;
public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube::MOVE> solve(){

        for(int i=1;i<=max_search_depth;i++)
        {
            DFSSolver<T,H> dfsSolver(rubiksCube,i);
            moves = dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }

        return moves;



    }


};








#endif //RUBIKSCUBESOLVER_IDDFSSOLVER_H
