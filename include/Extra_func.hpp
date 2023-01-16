#ifndef _EXTRA_FUNC
#define _EXTRA_FUNC

#include<iostream>
#include<vector>
#include"../include/Player.hpp"
#include"../include/Part.hpp"
#include <SFML/Graphics.hpp>

void draw_parts(const std::vector<Part> &, sf::RenderWindow &);

void draw_player(const Player &, sf::RenderWindow &, int, bool);

void draw_socre(const Player&, sf::RenderWindow &);

bool full(const std::vector<Part> &);

int collision(std::vector<Part> &,Player &);

int swapping(Part&, Part&, int , Player &);

#endif