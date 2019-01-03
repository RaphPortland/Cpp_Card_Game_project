//
//  Card.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Attaque_1.hpp"

class Player;
class Card
{
        protected : 
        std::string m_card_name;      //Nom de la carte
        int m_prix;                   //Prix de la carte dans la boutique
        std::string m_type;           //Type de carte

        public:
        Card();

        std::string getm_type(){return m_type;}         //Retourne le type de la carte
        std::string getm_nom(){return m_card_name;}     //Retourne le nom
        int getm_prix(){return m_prix;}                 //Retourne le prix
        

        /// METHODES VIRTUELLES


        virtual void descriptiondelacarte()=0;          //Presentation de la carte      
        virtual std::string getm_energy()=0;            //Getter sur energie -> Utlisé dans la classe EnergyCard
        virtual int attaquer(Player*,std::map <std::string, int>, int _robotcontrerobot)=0;       //Attaquer avec en paramètre le joueur attaqué -> Utlisé dans la classe WickedCard
        virtual void setptsdeviecreature(int ptsdeviecarte)=0;              //Setter points de vie de la créature -> Utlisé dans la classe EnergyCard
        virtual int getm_life_point()=0;                                    //Getter points de vie de la créature -> Utlisé dans la classe EnergyCard
    
        virtual int getuniqueoupersistant()=0;          //Getter pour savoir si la carte spéciale a un usage unique ou persistant -> Utlisé dans la classe SpecialCard
        virtual int getrecycleble()=0;                  //Getter pour savoir si la carte spéciale est recyclable -> Utlisé dans la classe SpecialCard
        virtual void action(Player &parametre)=0;       //CHOIX action
        virtual void changementpuissanceattaque(int attou)=0;           //setter qui modifie la puissance d'attaque de la créature en fonction de la carte spéciale en jeu
        virtual std::vector<Attaque_1> gettab_attaque()=0;              //Getter qui lit dans un tableau les attaques disponibles
        virtual int getattou()=0;             //Getter valeur atout carte spéciale
};


#endif /* Card_hpp */
