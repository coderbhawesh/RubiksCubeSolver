//
// Created by Bhawesh Kumar Pandit on 13/08/24.
//
#include "RubiksCube.h"
class RubiksCube1dArray : public RubiksCube{

    /*
    * Given a face index, row and col, return it's flattened index
    */
    static inline int getIndex(int ind, int row, int col) {
        return (ind * 9) + (row * 3) + col;
    }




};