#include <iostream>
#include "ThreeSum.h"

using std::cout;
using std::endl;

int main(){
    vector<int> v{-5,2,3,10,-5,22,-32};
    ThreeSum ts(v);
    
    cout << "Number of triplets summed to 0 is " << ts.count();
    return 0;
}