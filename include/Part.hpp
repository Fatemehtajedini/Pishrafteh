#ifndef _HOSPITAL
#define _HOSPITAL
#include <iostream>

class Part
{
private:
    int capacity;
    int size;
    int i;
    int j;
    std::string name;
public:
    Part(std::string,int);
    void reduce_size(int);
    void increase_size(int);
    int increase_capacity(int);
    int get_size();
    int get_capacity();
    std::string get_name();
    int get_i();
    int get_j();
};


#endif