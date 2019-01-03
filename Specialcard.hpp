//
//  Specialcard.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 03/12/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Specialcard_hpp
#define Specialcard_hpp

#include <stdio.h>
#include "Card.hpp"
#include "Player.hpp"
#include "Attaque_1.hpp"

class Specialcard : public Card {
    private :
    	int uniqueoupersistant; // 1 -> persistant, 0 -> unique
    	int recyclable; // 1 ->Oui, 0 -> Non
    	int attou;
    public :
    Specialcard();
    Specialcard(std::string _name,int _recyclable, int _uniqueoupersistant, int _puissance, int prix);

    void descriptiondelacarte();
    std::string getm_energy(){std::string coucou; return coucou;};
    int attaquer(Player*,std::map <std::string, int>, int _robotcontrerobot){return 0;};
    virtual void setptsdeviecreature(int ptsdeviecarte){};
    virtual int getm_life_point(){int a; return a;};
    int getuniqueoupersistant(){return uniqueoupersistant;};
    int getrecycleble(){return recyclable;};
    void action(Player &parametre);
    int getattou(){return attou;};
    void changementpuissanceattaque(int attou){};
    std::vector<Attaque_1> gettab_attaque(){std::vector<Attaque_1> coucou; return coucou;};
};
#endif /* Specialcard_hpp */
