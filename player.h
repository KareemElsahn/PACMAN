//
//  player.h
//  PAC-MAN
//
//  Created by Kareem El-Sahn on 5/5/18.
//  Copyright © 2018 Kareem El-Sahn. All rights reserved.
//

#ifndef player_h
#define player_h

#include "maps.h"
#include "coins.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class player
{
    
private:
    CircleShape body;
    int x;
    int y;
    string direction;
    
public:
    player();
    void drawplayer(sf::RenderWindow&);
    void move(maps, coins&, Clock&);
    void getPosition(int&, int&);
    string playerDirection();
    int getX();
    int getY();
    
};

#endif /* player_h */
