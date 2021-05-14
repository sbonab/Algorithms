#include <fstream>
#include <string>
#include "QuickUnionUF.h"

using std::cout;
using std::endl;

int main(){
    
    std::ifstream inf{ "tinyUF.txt" };

    if (!inf){
        std::cout << "File could not opened for reading!" << std::endl;
        return 0;
    }
    std::string str;
    inf >> str;
    int N = std::stoi(str);

    QuickUnionUF UF(N);

    while(inf){
        UF.print();
        std::cout << std::endl;
        
        inf >> str;
        int i = std::stoi(str);

        inf >> str;
        int j = std::stoi(str);

        UF.Union(i,j);

    }

    return 1;
}