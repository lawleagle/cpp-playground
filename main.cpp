#include <iostream>
#include <fstream>

void interclasare()
{
    std::ifstream f1("file1.txt"); // "cin" but from file1.txt instead of the console
    std::ifstream f2("file2.txt"); // "cin" but from file2.txt instead of the console
    std::ofstream f("file.out"); // "cout" but to file.txt instead of the console


    int an; // number of elements from f1
    f1 >> an;

    // read first element from array in f1
    int a; // number from f1
    f1 >> a;


    int bn; // number of elements from f2
    f2 >> bn;

    // read first element from array in f2
    int b; // number from f2
    f2 >> b;


    // interclasare
    int ai = 0; // index in a
    int bi = 0; // index in b
    while (ai < an && bi < bn) {
        if (a < b) {
            f << a << ' ';
            f1 >> a;
            ai++;
        } else {
            f << b << ' ';
            f2 >> b;
            bi++;
        }
    }
    while (ai < an) {
        f << a << ' ';
        f1 >> a;
        ai++;
    }
    while (bi < bn) {
        f << b << ' ';
        f2 >> b;
        bi++;
    }

    f << std::endl;
}

int main() {
    interclasare();
    return 0;
}