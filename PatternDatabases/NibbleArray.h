//
// Created by Bhawesh Kumar Pandit on 18/08/24.
//
#include <iostream>
#include <vector>

using namespace std;
#ifndef RUBIKSCUBESOLVER_NIBBLEARRAY_H
#define RUBIKSCUBESOLVER_NIBBLEARRAY_H

class NibbleArray {
    size_t size;
    vector<uint8_t> arr;

public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t get(const size_t pos) const;

    void set(const size_t pos, const uint8_t val);

    unsigned char *data();

    const unsigned char *data() const;

    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t val = 0xFF);

};






#endif //RUBIKSCUBESOLVER_NIBBLEARRAY_H
