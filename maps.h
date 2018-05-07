//
//  map.h
//  PAC-MAN
//
//  Created by Kareem El-Sahn on 5/2/18.
//  Copyright © 2018 Kareem El-Sahn. All rights reserved.
//

#ifndef maps_h
#define maps_h
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class maps{
    
private:
    
    sf::RectangleShape m[20][20];
    bool vm[20][20];
   
    
public:
    //constructor
    maps(string);
    
    //setters
    void drawMap(sf::RenderWindow&);
    
    
    //getters
    bool isAvailable(int, int);

};
#endif /* map_h */
