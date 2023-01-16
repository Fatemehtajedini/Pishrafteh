#include"../include/Extra_func.hpp"
#include<iostream>
#include<vector>
#include"../include/Player.hpp"
#include"../include/Part.hpp"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void draw_parts(const vector<Part> &parts, RenderWindow &window){
    RectangleShape temp(Vector2f(140,140));
    Font font;
    font.loadFromFile("Fonts/arial.ttf");
    Text name;
    Text size;
    for (auto part:parts){
        string temp_string = to_string(part.get_capacity()) + " of " + to_string(part.get_size());
        temp.setFillColor(Color::Red);
        temp.setPosition(part.get_i(), part.get_j());
        name.setFillColor(Color::White);
        name.setFont(font);
        name.setPosition(part.get_i() +10, part.get_j() + 10);
        name.setString(part.get_name());
        name.setCharacterSize(20);
        size.setFillColor(Color::White);
        size.setFont(font);
        size.setPosition(part.get_i() + 10, part.get_j() + 50);
        size.setString(temp_string);
        size.setCharacterSize(20);
        window.draw(temp);
        window.draw(name);
        window.draw(size);
    }
    
}

void draw_player(const Player &player, sf::RenderWindow &window, int num,bool color){
    Text number;
    CircleShape shape(20);
    Font font;
    font.loadFromFile("Fonts/arial.ttf");
    shape.setPosition(player.get_i(), player.get_j());
    number.setFillColor(Color::White);
    number.setFont(font);
    number.setPosition(player.get_i()+10, player.get_j()+10);
    number.setString(to_string(num));
    number.setCharacterSize(20);
    if (color){
        shape.setFillColor(Color::Blue);
    }
    else{
        shape.setFillColor(Color::Red);
    }
    
    window.draw(shape);
    window.draw(number);
}

void draw_socre(const Player&player, RenderWindow &window){
    Font font;
    font.loadFromFile("Fonts/arial.ttf");
    Text score;
    score.setFillColor(Color::White);
    score.setFont(font);
    score.setPosition(10,10);
    score.setCharacterSize(20);
    score.setString(player.get_name() + " : " +  to_string(player.get_score()));
    window.draw(score);
}

bool full(const vector<Part> &Parts){
    for(Part part: Parts){
        if (part.get_capacity() != part.get_size()){
            return false;
        }
    }
    return true;
}

int collision(vector<Part> &parts, Player &player){
    int i = 0;
    for (auto part : parts){
        if (player.get_i() >part.get_i()+20 && player.get_i() < part.get_i() + 120){
            if (player.get_j() >part.get_j()+20 && player.get_j() < part.get_j() + 120){
                return i;
            }
        }
        i++;
    }
    return -1;
}

int swapping(Part&first_part, Part&second_part, int value, Player & player){
    if (second_part.get_capacity() == second_part.get_size()){
        --player;
        return value;
    }
    else if(second_part.get_size() - second_part.get_capacity() >= value){
        second_part.reduce_size(value);
        first_part.increase_size(value);
        first_part.increase_capacity(value);
        player + value;
        return 0;
    }
    else{
        int temp = second_part.get_size() - second_part.get_capacity();
        first_part.increase_size(temp);
        first_part.increase_capacity(temp);
        second_part.reduce_size(temp);
        player + temp;
        return value - temp;
    }
}