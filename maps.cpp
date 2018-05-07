#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "maps.h"

using namespace std;

//constructor

maps::maps(string name){
    char c; ifstream f;
    f.open(name);
    if(f.is_open()){
        cout << "loading map" << endl;
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 20; j++){
                f >> c;
                if(c == '#'){
                    m[i][j].setSize(sf::Vector2f(60,60));
                    m[i][j].setPosition(j *60, i*60);
                    m[i][j].setFillColor(sf::Color::Blue);
                    vm[j][i] = false;
                }
                else {
                    m[i][j].setSize(sf::Vector2f(60,60));
                    m[i][j].setPosition(j *60, i*60);
                    m[i][j].setFillColor(sf::Color::Black);
                    vm[j][i] = true;
                }
                
    }
          
    
}
        
    
}
    f.close();
    cout << "Map Loaded" << endl;
}

void maps::drawMap(sf::RenderWindow& window){
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            window.draw(m[i][j]);
        }
    }
        }

bool maps::isAvailable(int x, int y){
    return (vm[x][y]);
}


        

