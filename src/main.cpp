#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include"../include/Player.hpp"
#include"../include/Part.hpp"
#include"../include/Extra_func.hpp"
#include <random>
#include <ctime>
#include <fstream>

using namespace std;
using namespace sf;

int main(){
    string disease[] = {"Flu", "HIV", "Eczema", "Corona", "Cancer", "Heart Disease", "Color blind", "Hepatitis", "Ebola", "Diphtheria"};
    vector<Part> parts;
    bool win;
    unsigned int level = 1;
    string name;
    cout << "Enter your name : ";
    cin >> name;
    Player player(name);
    bool first = true;
    bool change_mode = 0;
    bool game_over = false;
    default_random_engine engine (static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int>randomInt(1,100);
    Font font;
    font.loadFromFile("Fonts/arial.ttf");
    Text hint;
    hint.setFillColor(Color::Magenta);
    hint.setCharacterSize(30);
    hint.setPosition(300,300);
    hint.setFont(font);
    Event event;
    RenderWindow window(VideoMode(1744,1444),"Hospital", Style::Close);
    window.setView(View(FloatRect(0,0,872,722)));
    while(!game_over){
        win = false;
        if (level >= 10){
            for (string dis : disease){
                parts.push_back(Part(dis,level+1));
            }    
        }
        else{
            for (size_t i = 0; i < level+1; i++){
                parts.push_back(Part(disease[i],10));
            }
        }
        unsigned int new_patient = (randomInt(engine) % 3) + 1;
        unsigned int dis = (randomInt(engine) % parts.size());    
        while (window.isOpen() && !win && !game_over){ 
            while (window.pollEvent(event)){
                if (event.type == Event::Closed){
                    exit(1);
                }
                
            }
            if (new_patient == 0 && full(parts)){
                level++;
                win = true;
                parts.clear();
                break;
            }
            else if (full(parts)){
                game_over = true;
                break;
            }
            else if (new_patient == 0){
                dis = (randomInt(engine) % parts.size());
                new_patient = (randomInt(engine) % 3) + 1;
            }
            if (change_mode){
                if (collision(parts, player) != -1){
                    new_patient = swapping(parts[dis], parts[collision(parts, player)],new_patient,player);
                    player.reset();
                }
                if (new_patient == 0){
                    change_mode = false;
                }
                hint.setString("change some room size for " + parts[dis].get_name());
            }
            else{
                hint.setString(parts[dis].get_name());
                if (collision(parts, player) == dis){
                    if (parts[dis].get_size() - parts[dis].get_capacity() >= new_patient){
                        parts[dis].increase_capacity(new_patient);
                        player + new_patient;
                        new_patient = 0;
                    }
                    else{
                        int temp = new_patient - (parts[dis].get_size() - parts[dis].get_capacity());
                        parts[dis].increase_capacity(parts[dis].get_size() - parts[dis].get_capacity());
                        player + (new_patient - temp);
                        new_patient = temp;
                        change_mode = true;
                    }
                    player.reset();
                }
                else if(collision(parts, player)==-1){
                }
                else{
                    player.reset();
                    --player;
                }
            }
            
            
            window.clear();
            player.move();
            draw_socre(player, window);
            draw_parts(parts, window);
            draw_player(player, window,new_patient,!change_mode);
            window.draw(hint);
            window.display();
        }
    }
    ofstream log_file("log.txt", ios::app);
    log_file << player.get_name() << "   Level : " << level << "   Score : " << player.get_score() << endl;
    log_file.close();
    while (window.isOpen() && !win){ 
        while (window.pollEvent(event)){
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Enter)){
                exit(1);
            }
                
        }
        hint.setString("Game over! score : " + to_string(player.get_score())); 
        window.clear();
        window.draw(hint);
        window.display();
    }
    return 0;
}