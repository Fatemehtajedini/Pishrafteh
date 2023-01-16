#ifndef _PLAYER
#define _PLAYER

#include<iostream>

class Player{
    private:
        std::string name;
        int score;
        int i;
        int j;
    public:
        Player(std::string);
        void increase_score(int);
        void decrease_score(int);
        void operator++(); 
        void operator--(); 
        int get_score()const;
        void operator+(int);
        std::string get_name()const;
        int get_i()const;
        int get_j()const;
        void move();
        void reset();
};



#endif