//
//  ghost.h
//  PAC-MAN
//
//  Created by Kareem El-Sahn on 4/30/18.
//  Copyright © 2018 Kareem El-Sahn. All rights reserved.
//

#ifndef ghost_h
#define ghost_h
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include "maps.h"
#include "player.h"
using namespace std;

class ghost{
    
private:
    sf::RectangleShape g;
    int x, y;
    string direction;
    
public:
    //constructor
    ghost(string); // default size 30, 30;
    ghost(int, int, string); // setting position;
    
    
    
    //setters
    void setGhostPosition(int, int);
    void setGhostColor(string);
    void setGhostSize(int, int);
    void changeDirection(string);
    void setDirection(string);
    void moveGhost(maps, player);
    void drawGhost(sf::RenderWindow&);
    //getters
    bool nextMoveAvailable(string, maps);
    int getYposition();
    int getXposition();
    bool movePossible(string, maps);
    bool checkPlayer(player);

    
    
    
    
};

#endif /* ghost_h */
