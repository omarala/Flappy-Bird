/* 
 * File:   Bird.h
 * Author: omar
 *
 * Created on 30 December 2017, 17:09
 */

#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
class Bird {
public:
    static const float velocityX = 0.00f;
    
    //constructeur
    Bird(sf::Sprite &);

    //reinitialise le bird a l'etat initial
    void reInit(sf::Sprite &);
    
    //getters and setters for position
    //getters et setters de x
    float getX();
    void setX(float);
    //getters et setters de y
    float getY();
    void setY(float);

    //sauter
    void sauter();
    
    //bouger
    void move(sf::Sprite &);
    
private:
    float x;
    float y;
    float velocityY;
    
    

};

#endif /* BIRD_H */

