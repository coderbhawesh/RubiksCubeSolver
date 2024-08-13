#include <iostream>
#include "Model/RubiksCube3dArray.cpp"
using namespace  std;
int main() {
    //std::cout << "Hello, World!" << std::endl;
    RubiksCube3dArray obj;

    obj.print();
    obj.u();
    obj.print();

    cout<<obj.isSolved()<<"\n";

    return 0;
}
