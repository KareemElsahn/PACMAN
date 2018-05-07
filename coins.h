//
//  coins.h
//  PAC-MAN
//
//  Created by Kareem El-Sahn on 5/5/18.
//  Copyright © 2018 Kareem El-Sahn. All rights reserved.
//

#ifndef coins_h
#define coins_h
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class coins
{
private:
    sf::CircleShape c[20][20];
    bool vc[20][20];
    
public:
    coins(string map);
    coins(string map, int size);
    void drawcoins(sf::RenderWindow& window);
    bool noteaten(int x, int y);
    void eat(int x, int y);
};

#endif /* coins_h */
