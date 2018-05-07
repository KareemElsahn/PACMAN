//#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<sstream>
#include <fstream>
#include "ghost.h"
#include "maps.h"
#include "player.h"
#include "coins.h"
using namespace sf;

void handleEvent(RenderWindow &window)
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed :
                window.close();
                break;
            case Event::KeyPressed:
                //if(event.key.code == Keyboard::Space)
                // initialize(window, island, rows, cat1, cat2, cat3, cat4, bridge, mouse);
                break;
        }
    }
}

    



int main()
{
    Clock c, pc;
    srand(time(NULL));
    ghost g(9,15,"Red"), ghost2(9,8,"Yellow"), ghost3(12,14,"Green");
    maps m("map.txt");
    player pac;
    RenderWindow window;
    coins coin("map.txt");
    
    
    
  
    
    window.create(VideoMode(1200, 1200), "PAC-man", Style::Close);
   
    
    
    while (window.isOpen())
    {
        
        window.clear(Color::White);
        handleEvent(window);
        
       
        m.drawMap(window);
        coin.drawcoins(window);
        pac.drawplayer(window);
        g.drawGhost(window);
        ghost2.drawGhost(window);
        ghost3.drawGhost(window);
        
        if(  !g.checkPlayer(pac)&&
           !ghost2.checkPlayer(pac)&&
           !ghost3.checkPlayer(pac)){
       
            if(pc.getElapsedTime().asMilliseconds() >= 230){
                pac.move(m,coin, pc);
            }
        if(c.getElapsedTime().asMilliseconds() >= 300){
        g.moveGhost(m,pac);
        ghost2.moveGhost(m,pac);
        ghost3.moveGhost(m,pac);
            c.restart();
        }
       }
       // else cout << "YOU LOSE"<< endl;
        
    
        window.display();
    }
    
    
    
}

