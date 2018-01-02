/* 
 * File:   Bird.cpp
 * Author: omar
 * 
 * Created on 30 December 2017, 17:09
 */


#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bird.h"
#include "variables.h"

using namespace std;

//getters et setters de x
float Bird::getX(){
    return this->x;
}

void Bird::setX(float x){
    this->x = x;
}

//getters et setters de y
float Bird::getY(){
    return this->y;
}

void Bird::setY(float y){
    this->y = y;
}

void Bird::reInit(sf::Sprite &img)
{
    setX(X_POSITION);
    setY(HEIGHT/2 + ECART_HAUT_BAS);
    this->velocityY = 0.0f;
    

    //l'image est decale
    img.setPosition(this->x - 16.0f, this->y - 15.0f);
    
}

//fait sauter en appliquant la force de monter
void Bird::sauter(){
    this->velocityY += UPFORCE;
}

void Bird::move(sf::Sprite & img){
    this->velocityY += GRAVITY;
    this->velocityY *= AIR_RESISTANCE;
    this->y += velocityY;
    img.move(velocityX, velocityY);
}


Bird::Bird(sf::Sprite &img)
{
    //on change la taille de l'image
    img.scale(0.5f, 0.5f);
    this->reInit(img);

}




