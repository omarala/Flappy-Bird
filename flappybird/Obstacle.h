
/* 
 * File:   Obstacle.h
 * Author: omar
 *
 * Created on 30 December 2017, 16:01
 */

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>
class Obstacle {
public:
    static const float width = 70;
    
    //constructeur
    Obstacle();
    
    //getters et setters de height
    float getHeight();
    void setHeight();

    //getter de x
    float getX();
    
    //getter et setter de y;
    float getY();
    void setY();
    
    //getter pour stalagmite
    sf::RectangleShape getStalagmite();
    
    //getter pour stalactite
    sf::RectangleShape getStalactite();
    
    //vitesse selon x et y
    static const float velocityY = 0.0f;
    static const float velocityX = -0.7f;
    
    //bouger
    void move();
    
private:
    // hauteur de la stalagmite 
    // hauteur de la stalactite == hecran - h - 100
    // on laisse 100 pour le passage de l'oiseau
    float height;
    // position du rectangle il faudra resoudre où cette merde dessine
    float x;
    float y;
    // les 2 rectangles
    sf::RectangleShape stalactite;
    sf::RectangleShape stalagmite;

};

#endif /* OBSTACLE_H */

