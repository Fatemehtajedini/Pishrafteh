#include<iostream>
#include"../include/Part.hpp"

using namespace std;

Part::Part(string name, int size){
    this->name = name;
    this->size = size;
    this->capacity = 0;
    if (name == "Flu"){
        i = 50;
        j = 50;
    }
    else if(name == "HIV"){
        i = 250;
        j = 50;
    }
    else if(name == "Eczema"){
        i = 450;
        j = 50;
    }
    else if(name == "Corona"){
        i = 650;
        j = 50;
    }
    else if(name == "Cancer"){
        i = 50;
        j = 275;
    }
    else if(name == "Heart Disease"){
        i = 650;
        j = 275;
    }
    else if(name == "Color blind"){
        i = 50;
        j = 500;
    }
    else if(name == "Hepatitis"){
        i = 250;
        j = 500;
    }
    else if(name == "Ebola"){
        i = 450;
        j = 500;
    }
    else{
        i = 650;
        j = 500;
    }
    
}

void Part::reduce_size(int value){
    size -= value;
}

void Part::increase_size(int value){
    size += value;
    
}

int Part::increase_capacity(int value){
    if (capacity + value <= size){
        capacity += value;
        return 0;
    }
    else{
        int temp = value - (size - capacity);
        capacity = size;
        return temp;
    }
}

int Part::get_size(){
    return size;
}

int Part::get_capacity(){
    return capacity;
}

string Part::get_name(){
    return name;
}

int Part::get_i(){
    return i;
}

int Part::get_j(){
    return j;
}