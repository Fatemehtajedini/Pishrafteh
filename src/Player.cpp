#include<iostream>
#include"../include/Player.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Player::Player(string name){
    this->name = name;
    score = 0;
    i = 406;
    j = 331;
}

void Player::increase_score(int value){
    score += value;
}

void Player::decrease_score(int value){
    score -= value;
}

void Player::operator++(){
    score++;
}

void Player::operator--(){
    if (score != 0){
        score--;
    }
}

int Player::get_score()const{
    return score;
}

void Player::operator+(int value){
    score += value;
}

string Player::get_name()const{
    return name;
}

int Player::get_i()const{
    return i;
}

int Player::get_j()const{
    return j;
}
void Player::move(){
    if (Keyboard::isKeyPressed(Keyboard::Up)){
        if (j > 0){
            j--;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)){
        if (j < 722 - 60){
            j++;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)){
        if (i > 0){
            i--;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)){
        if (i < 872 - 60){
            i++;
        }
    }    
}

void Player::reset(){
    i = 406;
    j = 331;
}