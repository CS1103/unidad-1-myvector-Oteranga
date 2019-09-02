#include <iostream>
#include <cassert>
#include "vector.h"

using namespace std;

    int main() {
        UTEC::MyVector v1;

        assert(v1.size() == 0);
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);

        assert(v1.size() == 3);

        UTEC::MyVector v2;
        UTEC::MyVector v3 = v1 + v2;

        assert(v3.size() == 3);
        int total = 0;
        for (int i = 0; i < v1.size(); ++i)
            total += v1[i];
        assert(total == 60);
        string resultado;
        try {
            v1.insert(10, 10);
        }
        catch (const runtime_error &e) {
            resultado = e.what();
        }
        assert(resultado == "Fuera de límite");

        return 0;
    }
