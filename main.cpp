//
//  main.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 06/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include <map>
#include <ctime>

int main(int argc, const char * argv[]) {
    // insert code here...
	int choix=0;
    int fullrobot=0;
    int Reptitiondumatch=0;
	Board plateau;
    std::map <int, Player> map_player;
    srand(time(NULL));

    while (choix!=3){
        choix=plateau.menuprincipale();
        if(choix==1)
        {
            std::cout << "1. Partie normale \n2. Partie entre 2 robots " << std::endl;
            std::cin >> fullrobot;
            if (fullrobot==2)
            {
                fullrobot=1;
                std::cout << "Combien de parties a la suite voulez-vous faire ?" << std::endl;
                std::cin >> Reptitiondumatch;
            }
            else {fullrobot=0;Reptitiondumatch=1;}
            
            for (int i=0 ; i<Reptitiondumatch; i++)
            {
                plateau.remplissagejoueur(map_player, plateau, fullrobot);
                plateau.jeu(map_player, plateau,fullrobot);

            }
            // Boucle qui permet aux joueur de jouer sachant que les joueurs sont deja crée.

        }
        if(choix==2)
        {
            plateau.option();
        }
    }
    return 0;
}
