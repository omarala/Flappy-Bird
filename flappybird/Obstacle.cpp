
/* 
 * File:   Obstacle.cpp
 * Author: omar
 * 
 * Created on 30 December 2017, 16:01
 */


#include <iostream>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <vector>
#include "Obstacle.h"
#include "variables.h"


using namespace std;

//getters et setters de height
float Obstacle::getHeight(){
    return this->height;
}

void Obstacle::setHeight(){
    //genere un float aleatoire entre 100 et 400
    float h = ECART_HAUT_BAS + static_cast <float> (rand()) /
    ( static_cast <float> (RAND_MAX/(400 - ECART_HAUT_BAS)));
    this->height = h;
}

//getter de x (pour la stalactite)
float Obstacle::getX(){
    return this->x;
}

//getter et setter de y (pour la stalactite)
float Obstacle::getY(){
    return this->y;
}

//met y a 0 
void Obstacle::setY(){
    this->y = 0;
}

//renvoie le rectangle du haut
sf::RectangleShape Obstacle::getStalagmite(){
    return this->stalagmite;
}

//renvoie le rectangle du bas
sf::RectangleShape Obstacle::getStalactite(){
    return this->stalactite;
}

//bouge d'une etape
void Obstacle::move(){
    this->x += velocityX;
    this->y += velocityY;
    stalagmite.move(velocityX, velocityY);
    stalactite.move(velocityX, velocityY);
    
}

Obstacle::Obstacle() {
    //init
    this->setHeight();
    this->setY();
    //au depart l'obstacle se trouve à la limite droite
    this->x = WIDTH;
    //parametrage stalagmite
    stalactite.setPosition(this->x, this->y);
    stalactite.setSize(sf::Vector2f(this->width, this->height));
    stalactite.setFillColor(sf::Color::Green);
    
    stalagmite.setPosition(this->x,  this->height + ECART_HAUT_BAS );
    stalagmite.setSize(sf::Vector2f(this->width, HEIGHT - this->height ));
    stalagmite.setFillColor(sf::Color::Green);


}

/*Obstacle::Obstacle(const Obstacle& orig) {
}

Obstacle::~Obstacle() {
}*/

