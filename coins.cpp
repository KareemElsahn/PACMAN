#include "coins.h"
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

coins::coins(string map)
{
    char k; ifstream f;
    f.open(map);
    if (f.is_open()) {
        cout << "loading coin's map" << endl;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                f >> k;
                if (k == '#') {
                    c[i][j].setRadius(10);
                    c[i][j].setPosition(j * 60+20, i * 60+20);
                    c[i][j].setFillColor(sf::Color::Yellow);
                    vc[j][i] = false;
                }
                else {
                    c[i][j].setRadius(10);
                    c[i][j].setPosition(j * 60+20, i * 60+20);
                    c[i][j].setFillColor(sf::Color::Yellow);
                    vc[j][i] = true;
                }
                
            }
        }
    }
    f.close();
    cout << "coins Loaded" << endl;
}
coins::coins(string map, int size)
{
    char k; ifstream f;
    f.open(map);
    if (f.is_open()) {
        cout << "loading coin's map" << endl;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                f >> k;
                if (k == '#') {
                    c[i][j].setRadius(size);
                    c[i][j].setPosition(j * 60+20, i * 60+20);
                    c[i][j].setFillColor(sf::Color::Yellow);
                    vc[j][i] = false;
                }
                else {
                    c[i][j].setRadius(size);
                    c[i][j].setPosition(j * 60+20, i * 60+20);
                    c[i][j].setFillColor(sf::Color::Yellow);
                    vc[j][i] = true;
                }
                
            }
        }
    }
    f.close();
    cout << "coins Loaded" << endl;
    
}

void coins::drawcoins(sf::RenderWindow& window) {
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            
            if (vc[j][i]) {
                window.draw(c[i][j]);
            }
            
        }
    }
}

bool coins::noteaten(int x, int y) {
    return (vc[x][y]);
}

void  coins::eat(int x, int y) {
    vc[x][y] = false;
}
