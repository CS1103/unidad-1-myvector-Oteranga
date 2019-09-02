//
// Created by Alejandro  Otero on 2019-08-27.
//
#include "vector.h"
#include <stdexcept>
#include <string>
using namespace std;

UTEC::MyVector::MyVector():data{nullptr},nelem{0} {}


UTEC::MyVector::MyVector(int n):nelem{n} {
    data=new int[nelem];
}

UTEC::MyVector::~MyVector(){
    delete [] data;
}

int UTEC::MyVector::size() {
    return nelem;
}

void UTEC::MyVector::push_back(int n) {
    int* temp;
    temp=new int [nelem+1];
    for (int i=0; i<nelem; ++i){
        temp[i]=data[i];
    }

    delete [] data;

    data=temp;

    data[nelem]=n;

    nelem++;
}

void UTEC::MyVector::insert(int pos, int elem) {
    int* temp;
    temp=new int [nelem+1];
    for (int i=0;i<pos-1;i++){
        temp[i]=data[i];
        for (int j=nelem;j>pos-1;j--)
            temp[i]=data[i];
    }
    temp[pos-1]=elem;
    delete [] data;
    data=temp;
}

void UTEC::MyVector::pop_back() {
    int* temp;
    temp=new int [nelem-1];
    for (int i=0; i<nelem-1;i++){
        temp[i]=data[i];
    }
    delete [] data;
    data=temp;

}

int UTEC::MyVector::operator[](int index) {
    if(index<0 || index>=nelem) {
        throw runtime_error("Fuera de rango");
    }
    return data[index];

}

void UTEC::MyVector::erase(int pos) {
    int* temp=new int [nelem-1];
    for (int i=0;i<pos-1;i++){
        temp[i]=data[i];
        for(int j=nelem-1;j>pos-1;j-- ){
            temp[i]=data[i];
        }
    }
    delete [] data;
    data=temp;
}

int UTEC::MyVector::operator+(const int& vec1) {
    return data+vec1;
}