#include "player.h"
#include "coins.h"
using namespace sf;

player::player()
{
    
    body.setFillColor(Color::Yellow);
    x = 18;
    y = 15;
    body.setPosition(x*60, y * 60);
    body.setRadius(30);
    direction = "up";
    
}



void player::drawplayer(RenderWindow& window) {
    
    window.draw(body);
    
}


void player::move(maps level, coins &coin, Clock& cp) {
    
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        if (level.isAvailable(x-1, y ))
        {
            body.move(-60, 0);
            x--;
            if (coin.noteaten(x, y)) {
                coin.eat(x, y);
            }
            direction = "left";
        }
        cp.restart();
    }
    
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (level.isAvailable(x+1, y ))
        {
            body.move(60, 0);
            x++;
            if (coin.noteaten(x, y)) {
                coin.eat(x, y);
            }
            direction = "right";
        }
        
        cp.restart();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (level.isAvailable(x, y-1))
        {
            body.move(0, -60);
            y--;
            if (coin.noteaten(x, y)) {
                coin.eat(x, y);
            }
            direction = "up";
        }
        cp.restart();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        if (level.isAvailable(x , y+1))
        {
            body.move(0, 60);
            y++;
            if (coin.noteaten(x, y)) {
                coin.eat(x, y);
            }
            direction = "down";
        }
        cp.restart();
    }
}
void player::getPosition(int& i, int& j){
    i = x; j = y;
}
string player::playerDirection(){
    return direction;
}
int player::getX(){
    return x;
}
int player::getY(){
    return y;
}
