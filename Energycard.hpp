//
//  Energycard.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Energycard_hpp
#define Energycard_hpp

#include <stdio.h>
#include <iostream>
#include "Card.hpp"
#include "Attaque_1.hpp"
#include <vector>

class Player;
class Energycard : public Card 
{
	private : 
		std::string m_energy; // Militaire, Politique, economique ou culturelle 
	public:
		Energycard();
		Energycard(std::string domaine, std::string card_name, int prix);
		void descriptiondelacarte();
        int attaquer(Player*, std::map <std::string, int>,int _robotcontrerobot){return 0;};

        std::string getm_energy(){return m_energy;};
        // LA SUITE EST POUBELLE
        void setptsdeviecreature(int ptsdeviecarte){};
        int getm_life_point(){int a;return a;};
        //std::vector<Attaque_1> gettab_attaque(){std::vector<Attaque_1> coucou;return coucou;};
    int getuniqueoupersistant(){return 0;};
    int getrecycleble(){return 0;};
    void action(Player &parametre){};
    void changementpuissanceattaque(int attou){};
    std::vector<Attaque_1> gettab_attaque(){std::vector<Attaque_1> coucou; return coucou;};

int getattou(){return 0;};
};
#endif /* Energycard_hpp */
