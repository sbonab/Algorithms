#include <fstream>
#include <string>
#include "QuickFindUF.h"

using std::cout;
using std::endl;

int main(){
    
    std::ifstream inf{ "tinyUF.txt"};

    if (!inf){
        std::cout << "File could not opened for reading!" << std::endl;
        return 0;
    }
    std::string str;
    inf >> str;
    int N = std::stoi(str);

    QuickFindUF UF(N);

    while(inf){
        inf >> str;
        int i = std::stoi(str);

        inf >> str;
        int j = std::stoi(str);

        UF.Union(i,j);
    }

    UF.print();

    return 1;
}