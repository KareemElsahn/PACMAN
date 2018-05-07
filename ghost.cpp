#include "ghost.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include "time.h"
#include "maps.h"
using namespace std;

//constructors

ghost::ghost(string c){
    g.setSize(sf::Vector2f(60,60));
    g.setPosition(0, 0);
    if(c == "Blue")
        g.setFillColor(sf::Color::Blue);
    else if (c == "Red")
        g.setFillColor(sf::Color::Red);
    else if( c == "Green")
        g.setFillColor(sf::Color::Green);
    else
        g.setFillColor(sf::Color::Yellow);
    x = 0; y = 0;
    direction = "up";
   
    
}
ghost::ghost(int i, int j, string c){
    cout << "Loading Ghost" << endl;
    g.setSize(sf::Vector2f(60,60));
    g.setPosition(i*60, j*60);
    if(c == "Blue")
        g.setFillColor(sf::Color::Blue);
    else if (c == "Red")
        g.setFillColor(sf::Color::Red);
    else if( c == "Green")
        g.setFillColor(sf::Color::Green);
    else
        g.setFillColor(sf::Color::Yellow);
    
    x = i; y = j;
    direction = "up";
    cout << "Ghosts Loaded " << c << endl;
}

//setters

void ghost::setGhostPosition(int i, int j){
    x = i; y = j;
    g.setPosition(x,y);
    
}
void ghost::setGhostColor(string c){
    if (c == "Red")
    g.setFillColor(sf::Color::Red);
    else if (c == "Blue")
        g.setFillColor(sf::Color::Blue);
    else if( c == "Green")
        g.setFillColor(sf::Color::Green);
    else
        g.setFillColor(sf::Color::Yellow);
    
}

void ghost::setGhostSize(int x, int y){
    g.setSize(sf::Vector2f(x,y));
}
void ghost::setDirection(string d){
    direction = d;
}
void ghost::changeDirection(string d){
    int r = rand()%4;
    if(r == 0 && d!="up")
        direction = "up";
    else if(r == 1 && d != "down")
        direction = "down";
    else if(r == 2 && d != "left")
        direction = "left";
    else if(r == 3 && d != "right")
        direction = "right";
}


void ghost::moveGhost(maps m, player pac){
    bool flag = false;
    if(pac.playerDirection() == "up" && pac.getY() < y){
        if(m.isAvailable(x, y-1)){
            g.move(0, -60);
            y--;
            flag = true;
            direction = "up";
        }
    }
    else if(pac.playerDirection() == "down" && pac.getY() > y){
        if(m.isAvailable(x, y+1)){
            g.move(0, 60);
            y++;
            flag = true;
            direction = "down";
        }
    }
    else if(pac.playerDirection() == "left" && pac.getX() < x){
        if(m.isAvailable(x-1, y)){
            g.move(-60, 0);
            x--;
            flag = true;
            direction = "left";
        }
    }
    else if(pac.playerDirection() == "right" && pac.getX() > x){
        if(m.isAvailable(x+1, y)){
            g.move(60,0);
            x++;
            flag = true;
            direction = "right";
        }
        
    }
    
    while(!flag){
  if(direction == "up"){
        if(m.isAvailable(x, y-1)){
            g.move(0, -60);
            y--; flag = true;
        }
        else changeDirection(direction);
    }else if(direction == "down"){
        if(m.isAvailable(x, y+1)){
            g.move(0, 60);
            y++;
            flag = true;
        }else changeDirection(direction);
    }else if(direction == "left"){
        if(m.isAvailable(x-1, y)){
            g.move(-60, 0);
            x--;
            flag = true;
        }else changeDirection(direction);
    }else {
        if(m.isAvailable(x+1, y)){
            g.move(60,0);
            x++;
            flag = true;
        }else changeDirection(direction);
    }
    }
    }
    
    
    
    
        
    
    

void ghost::drawGhost(sf::RenderWindow& window){
    window.draw(g);
}


//getters
int ghost::getXposition(){
    
    return x*60;
}

int ghost::getYposition(){
    return y*60;;
}
bool ghost::nextMoveAvailable(string d, maps m){
    if(d == "up")
     return   m.isAvailable(x, y-1);
    else if(d == "down")
      return   m.isAvailable(x, y+1);
    else if(d == "left")
     return   m.isAvailable(x-1, y);
    else
    return m.isAvailable(x+1, y);
}

bool ghost::checkPlayer(player p){
    int i,j;
    p.getPosition(i, j);
    if(x == i && y == j)
        return true;
    else return false;
    
}



