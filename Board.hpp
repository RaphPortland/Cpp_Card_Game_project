//
//  Board.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 10/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include "Player.hpp"


// class board qui va gerer le jeu;
class Board
{
	private:
		// Attribus de la classe board en prive 
		int m_howmanyplayers;  //nombre de joueurs;
		int m_howmanycardineachdeck;  //nombre de carte voulu par deck;
		int m_nbrsdecarteagagner;  //nombre de carte a gagner;
		int m_nrdsdepointdevieparjoueuraudepart; // nombre de vie que le joueur aura au début de la partie;
    
	public:
		// Constructeur par defaut de la classe board;
		Board();
		// Méthodes de la classe board;
		int menuprincipale(); // fonction pour le menu principal;
		void option(); //procedure pour les options;
		void option_affichage(); //procedure pour l’affichage des options;
		void jeu(std::map<int, Player> &map_player, Board plateau,int fullrobot); // procedure pour la gestion du jeu;

        void remplissagejoueur(std::map<int, Player> &map_player, Board plateau,int fullrobot); // procedure pour l’initialisation des joueurs
    
        void fctremplissageenjeu();
		int getm_nrdsdepointdevieparjoueuraudepart() {return m_nrdsdepointdevieparjoueuraudepart;}
		int getm_howmanycardineachdeck(){return m_howmanycardineachdeck;}
		int getm_howmanyplayers(){return m_howmanyplayers;}
		int getm_nbrsdecarteagagner(){return m_nbrsdecarteagagner;}
};
#endif /* Board_hpp */
