/* 
 * File:   variables.h
 * Author: omar
 *
 * Created on 01 January 2018, 22:12
 */

#ifndef VARIABLES_H
#define VARIABLES_H

#include<string.h>

using namespace std;
//screen width
static const int WIDTH = 800;
//screen height
static const int HEIGHT = 600;

//ecart entre la stalactite et la stalagmite
static const float ECART_HAUT_BAS = 120.0f;

static const float GRAVITY = 0.09f;
static const float UPFORCE = -5.0f;
static const float AIR_RESISTANCE = 0.9f;

//rayon de l'oiseau a peu pres
static const float RAYON = 17.0f;

//float a partir duquel on supprime l'obstacle de la liste
static const float SCREEN_LIMIT = 20.0f;

//score string
static const string SCORE = "SCORE = ";

//bird x_position
static const float X_POSITION = 100.0f;
#endif /* VARIABLES_H */

