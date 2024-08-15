#include <iostream>
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
using namespace  std;
int main() {

//    RubiksCube3dArray obj;
//
//    obj.print();
//    obj.u();
//    obj.print();
//
//    cout<<obj.isSolved()<<"\n";

    //1drubik's cube

    //*******************************************************************************
    //IDDFS solver check
    RubiksCubeBitboard object;
    object.print();

    vector<RubiksCube::MOVE> moves = object.randomShuffleCube(6);
    cout<<"Moves for shuffling\n";
    for(auto it:moves)
        cout<<object.getMove(it)<<" ";
    cout<<"\n";
    object.print();

    IDDFSSolver<RubiksCubeBitboard,HashBitboard> iddfsSolver(object);
    vector<RubiksCube::MOVE> mov = iddfsSolver.solve();
    if(iddfsSolver.rubiksCube.isSolved())
    {
        cout<<"Solved!!\n";
    }
    else
        cout<<"Not solved\n";
    cout<<"Moves for solving\n";
    for(auto it:mov)
    {
        cout<<object.getMove(it)<<" ";
    }
    cout<<"\n";

    //*********************************************************
//    RubiksCube3dArray cube;
//    cube.print();
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube);
//    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    if(cube.isSolved())
//    {
//        cout<<"Solved !!\n";
//    }
//    else
//        cout<<"Not solved\n";
//    cube.print();




    return 0;
}
