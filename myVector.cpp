
#include "myVector.hpp"
#include <iostream>

myVector::myVector()
    :size(0),capacity(3),array(new string[capacity])
{}

myVector::myVector(int elements)
    :size(0),capacity(elements),array(new string[capacity])
{}

myVector::myVector(const myVector& o)
    :size(o.size),capacity(o.capacity),array(new string[capacity])
{}

myVector::~myVector()
{
    delete[] array;
}

void myVector::alloc_new()   
{
    capacity = size*2;
    string* newArray = new string[capacity];
    for(int i=0;i<size;++i)
        newArray[i]=array[i];
    
    delete[] array;
    array = newArray;
}

void myVector::push_back(std::string value)
{
    if(size+1 > capacity) alloc_new();
    array[size] = value;
    size++;
}

string myVector::operator[](int i)
{
    return array[i];
}

void myVector::print()
{

    for(int i=0;i<size;++i){
        cout<<array[i]<<"  ";
    }

}

int myVector::Size()
{
    return size;
}

void myVector::set_index_value(int i ,string value)
{
    array[i]=value;
}
 




