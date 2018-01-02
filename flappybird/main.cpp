#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include "Bird.h"
#include "Obstacle.h"
#include "variables.h"

using namespace std;

bool collision(Bird bird, Obstacle& obs);
string append(string const &a, int b);

int main()
{
    //load img
    sf::Texture textureImg;
    textureImg.loadFromFile("bird.bmp");
    
    //la cree un drawable
    sf::Sprite image(textureImg);
    
    //init window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Flappy bird");
    
    //init la liste des obstacles
    list<Obstacle> listObstacle;
    
    // init du bird
    Bird bird(image);

    //booleen  = true si y a eu collision
    bool collided = false;
    
    //loading font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout<<"erreure du chargement de la font"<<endl;
        return 1;
    }
    
    //score
    int score = 0;
    sf::Text scoreText(append(SCORE , score), font, 20);
    scoreText.setColor(sf::Color::Black);
    
    //game over
    sf::Text gameOver("GAME OVER", font, 100);
    gameOver.setColor(sf::Color::Red);
    gameOver.setPosition(100.0f, 200.0f);
    gameOver.setStyle(sf::Text::Bold);
    
    //instruction pause
    sf::Text pause("PAUSE : P", font, 20);
    pause.setPosition(700.0f, 0.0f);
    pause.setColor(sf::Color::Black);
    
    //en pause
    sf::Text enPause("EN PAUSE", font, 100);
    enPause.setColor(sf::Color::Red);
    enPause.setPosition(150.0f, 200.0f);
    enPause.setStyle(sf::Text::Bold);
    
    //replay instruction
    sf::Text replay("Replay : R", font);
    replay.setPosition(300.0f, 300.0f);
    replay.setStyle(sf::Text::Bold);
    replay.setColor(sf::Color::Black);           
    
    //continue instruction
    sf::Text continueInst("CONTINUE : SPACE", font);
    continueInst.setPosition(270.0f, 300.0f);
    continueInst.setColor(sf::Color::Black);
    
    //init instruction
    sf::Text init("JUMP : SPACE \n     QUIT : Q", font, 30);
    init.setPosition(300.0f, 200.0f);
    init.setStyle(sf::Text::Bold);
    init.setColor(sf::Color::Black);
    
    int i = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        //tant qu'on a de nouvel evenement
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Q)
                window.close();
            
            //met le jeu en pause
            if( event.key.code == sf::Keyboard::P){
                window.draw(enPause);
                window.draw(continueInst);
                window.display();
                while(event.key.code != sf::Keyboard::Space ){
                    window.pollEvent(event);
                }
            }
            
            if (event.key.code == sf::Keyboard::Space){
                bird.sauter();
            }
  
            
        }
        
        window.clear(sf::Color::Cyan);
        
        //draw the bird
        window.draw(image);
        
        //on cree un nouvel obstacle
        if(i%300 == 0){
            listObstacle.push_back(*(new Obstacle()));
        }
        

        
        //je boucle sur tout les elements de la liste
        for( list<Obstacle>::iterator it = listObstacle.begin(); it != listObstacle.end(); it++ ){
            Obstacle obs = *it;
            window.draw(obs.getStalagmite());
            window.draw(obs.getStalactite());
            (*it).move();
            
        }
        
        bird.move(image);
        
        //si le premier de la liste atteint la limite gauche de l'ecran on le retire
        if(listObstacle.front().getX() < SCREEN_LIMIT){
            listObstacle.pop_front();
            score ++;
            scoreText.setString(append(SCORE ,score));
        }
        
        //draw score
        window.draw(scoreText);
        
        //draw pause instruction
        window.draw(pause);
        
        //test la collision est arrete le jeu
        collided = collision(bird, listObstacle.front());
        if(collided){
            window.draw(gameOver);
            window.draw(scoreText);
            window.draw(replay);
            window.display();
            while(event.key.code != sf::Keyboard::R){
                window.pollEvent(event);         
            }
            bird.reInit(image);
            i = -1;
            score = 0;
            scoreText.setString(append(SCORE ,score));
            listObstacle.clear();
            window.clear(sf::Color::Cyan);
        }
        
        if(i<300){
            window.draw(init);
        }
        
        window.display();

        i+=1;

    }
    
    return 0;
}

bool collision(Bird bird, Obstacle &obs){
    if((obs.getX()<bird.getX()+2*RAYON )&&
            (bird.getY()<obs.getHeight() || 
            bird.getY() + 2*RAYON > obs.getHeight() + ECART_HAUT_BAS)){
        return true;
    }
    return false;
}

string append(string const &a, int b) {
  ostringstream oss;
  oss << a << b;
  return oss.str();
}