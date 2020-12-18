#pragma once

#include <string>
using namespace std;

class myVector
{
    private:
        int size;
        int capacity;
        string* array;
        void alloc_new();
    
    public:

        myVector();
        ~myVector();
        myVector(int);//maximuin size to allocate
        myVector(const myVector&); //copy constructor
        void push_back(string);
        int Size();
        string operator[](int);
        void print();
        void set_index_value(int,string);

};

