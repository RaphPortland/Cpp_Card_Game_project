//
//  Wickedcard.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Wickedcard_hpp
#define Wickedcard_hpp

#include <stdio.h>
#include <iostream>
#include "Attaque_1.hpp"
#include <map>
#include <vector>
#include "Card.hpp"
#include "Player.hpp"

class Wickedcard : public Card
{
    private : 
        int m_life_point;  //Vie créature
        std::vector<Attaque_1> tab_attaque;  //Tableau des attaques de la créature en question

    public:
        Wickedcard();
        Wickedcard(int _lifepoint);
        Wickedcard(int _lifepoint, std::string _cardname, int prix, std::string attaque1, std::string attaque2);

        void descriptiondelacarte();  //Presentation de la carte  
        int attaquer(Player *Ennemi, std::map <std::string, int> carte_energie_que_le_joueur_a, int _robotcontrerobot);
    
        //Poubelle :
        std::string getm_energy(){std::string coucou;return coucou;};   //Getter sur energie
        void setptsdeviecreature(int ptsdeviecarte){m_life_point=ptsdeviecarte;};       //Setter points de vie de la créature active
        int getm_life_point(){return m_life_point;};        //Getter points de vie de la créature active
        int getuniqueoupersistant(){return 0;};              //Getter pour savoir si la carte spéciale a un usage unique ou persistant -> Pas utilisé dans cette classe 
        int getrecycleble(){return 0;};     //Getter pour savoir si la carte spéciale est recyclable -> Pas utilisé dans cette classe 
        void action(Player &parametre){};
        void changementpuissanceattaque(int attou);     
        int getattou(){return 0;};   //Getter valeur atout carte spéciale
        std::vector<Attaque_1> gettab_attaque(){return tab_attaque;};    //Getter tableau des attaques disponibles
};
#endif /* Wickedcard_hpp */
