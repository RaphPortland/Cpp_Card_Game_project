//
//  Wickedcard.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "Wickedcard.hpp"

///CONSTRUCTEURS:

Wickedcard::Wickedcard() : m_life_point(0)    //Carte vide et nulle (sans points de vie)
{
    m_card_name="NULL";
    m_prix=50;
    m_type="WickedCard";
    
}

//SURCHARGÉ
Wickedcard::Wickedcard(int _lifepoint) : m_life_point(_lifepoint)   //On initialise ici la vie de la creature en la passant en parametre
{
    m_prix=50;
    m_type="WickedCard";
    
}
Wickedcard::Wickedcard(int _lifepoint, std::string _cardname, int prix, std::string attaque1, std::string attaque2) : m_life_point(_lifepoint)
{
    m_card_name=_cardname;
    m_prix=prix;
    Attaque_1 lapremiere(attaque1);
    Attaque_1 ladeuxieme(attaque2);
    tab_attaque.push_back(lapremiere);
    tab_attaque.push_back(ladeuxieme);
    m_type="WickedCard";
}

///AUTRES METHODES

int Wickedcard::attaquer(Player* Ennemi, std::map <std::string, int> carte_energie_que_le_joueur_a, int _robotcontrerobot)
{
    int choix=0,b=0;
    int attaque1=0, attaque2=0;
    int onrentrequnefois=0;
    int oui = 0;
    std::map<std::string, int> tab;
    std::cout << "Vos cartes energie : " << std::endl;
    
    for (auto elem : carte_energie_que_le_joueur_a){
        std::cout << elem.first << " : " << elem.second << std::endl;
    }
    do {
        if(onrentrequnefois==0)
        {
        for (int i=0;i<tab_attaque.size();i++)
            {
            tab=tab_attaque[i].getmap_domaine();  // La map ayant les carte energie requise pour attaquer
                for (auto elem : tab){
                    std::string it= elem.first;
                    if (carte_energie_que_le_joueur_a[it]>=elem.second)
                    {
                        if (i==0)
                        {
                            attaque1++;
                        }
                        if (i==1)
                        {
                            attaque2++;
                        }
                    }
                }
            }
        }
        if (attaque1==4)
        {
            std::cout << "Attaque 1 disponible : " << std::endl;
            tab_attaque[0].affichagenomdattaque();
        }
        if (attaque2==4)
        {
            std::cout << "Attaque 2 disponible : " << std::endl;
            tab_attaque[1].affichagenomdattaque();
        }
        if (_robotcontrerobot!=1)
        {
            std::cout << "Toutes les attaques a disposition ont été affichees precedement, si aucunes d'entre elles n'est affichees c'est parce que vous ne disposer pas d'assez de cartes energie : \n1 vous choisissez l'attaque 1\n2. vous choisissez l'attaque 2\n3. Quitter (par exemple si vous avez aucunes attaques de disponible)" << std::endl;
            std::cin >> choix;
            
        }
        else {
            if (attaque1==4)
            {
                choix=1;
            }
            else if (attaque2==4)
            {
                choix=2;
            }
            else
            {
                choix=3;
        
            }
        }

        if (choix==1)
        {
            if (attaque1==4){
                std::cout << "Attaque acceptée 1" << std::endl;
                b=Ennemi->getsurinaction()->getm_life_point()-tab_attaque[0].getm_puissance() ;
                Ennemi->getsurinaction()->setptsdeviecreature(b);
                choix=3;
                oui=1;
            }
        }
        else if (choix==2)
        {
            if (attaque2==4){
                std::cout << "Attaque acceptée 2" << std::endl;
                b=Ennemi->getsurinaction()->getm_life_point()-tab_attaque[1].getm_puissance() ;
                Ennemi->getsurinaction()->setptsdeviecreature(b);
                choix=3;
                oui=1;
            }
        }
        onrentrequnefois++;
    } while (choix !=3);
    
    return oui;
}

void Wickedcard::descriptiondelacarte()     //Affichage infos
{
    //std::cout << "Descrition de la carte :";
    std::cout << "Nom de la carte : " << m_card_name;
    std::cout << " Vies totales de la carte : " << m_life_point;
    std::cout << " Prix de la carte : " << m_prix << "." << std::endl;
}


void Wickedcard::changementpuissanceattaque(int attou)      
{
    for (int i=0;i<tab_attaque.size();i++)      //On parcours le tableau des attaques pour y augmenté les valeurs
    {
        tab_attaque[i].setpuissance(tab_attaque[i].getm_puissance()+attou);
    }
}
/*  */

