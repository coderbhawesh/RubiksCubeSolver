#include <iostream>
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
using namespace  std;
int main() {

//    RubiksCube3dArray obj;
//
//    obj.print();
//    obj.u();
//    obj.print();
//
//    cout<<obj.isSolved()<<"\n";

    RubiksCube3dArray cube;
    cube.print();
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube);
    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();

    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    if(cube.isSolved())
    {
        cout<<"Solved !!\n";
    }
    else
        cout<<"Not solved\n";
    cube.print();




    return 0;
}
