//
// Created by Bhawesh Kumar Pandit on 17/08/24.
//

#ifndef RUBIKSCUBESOLVER_PATTERNDATABASE_H
#define RUBIKSCUBESOLVER_PATTERNDATABASE_H
// for checking if the IDA* algorithms working correctly without heuristics or not
// dummy class due to which A* = dijkstra
template<typename T>
class PatternDatabaseEstimate {
private:

public:
    int getEstimate(T rubiksCube) {
        return 0;
    }

};

#endif //RUBIKSCUBESOLVER_PATTERNDATABASE_H
