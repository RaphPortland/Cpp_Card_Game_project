//
//  Player.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <fstream>
#include <set>
#include "Card.hpp"
#include "Energycard.hpp"
#include "Wickedcard.hpp"
#include "Specialcard.hpp"
#include <vector>

// class player qui va gerer ce qui le joueur;
class Player
{
    private :
// Attribus de la classe player en prive ; 
        std::string m_player_name; // Nom du joueur;
        std::string m_collection; // Player1 Player2 Player3 Player4;
        int m_sous; //argent;
        int m_lifepointplayer; //Point de vie du joueur;

        std::map <int, Card*> map_collection; //carte de la collection;
        std::map <int, Card*> carte_pour_deck; // carte du deck;
        std::deque <Card*> deque_pioche_deck; //pioche;
        std::vector <Card*> cimetiere; //cimetiere;
        std::map <int, Card*> m_carteagagner;// Carte mise en jeu qui seront gagnees par le gagnant;
        std::vector <Card*> tab_creatureenattente; // creatures mises en attente par les joueurs;
        std::map <int, Card*> tab_special; // cartes speciales;

        Card *inaction; //creature presentes sur le plateau;
        std::map <std::string, int> tabcarteenergieposer; //cartes energies presentes sur le plateau;
    
        Player *ptssurennemi; //pointeur sur l’ennemi;
    
    public:
        Player(int pointdevieparjoueur, std::string name); //Constructeur surcharge de la classe player;
        Player(); //Constructeur par defaut de la classe player;
    
    //Methode qui initialise le joueur;
        void initplayer(int cbdecartepardeck, int pointdevieparjoueur, int nbrsdecarteagagner, int modebot); 

        //Methode de chargement, selection des cartes au demarage: initialisation des collections;
        void chargementdelamapcollection(int dejainscritounon, int modebot); // On charge depuis un fichier toute les cartes de la collection;
        void determinationdudeck(int nbrsdecartepardeck, int modebot); // Remplissage de la map carte pour le deck;
        void startgameplayer(int nbrsdecartepardeck); // on passe de la MAP deck a une deque DECK en melangeant au passage;
        void preinscritounon(int &choix, int &chargement); // on voit si le joueur est inscrit ou non;
        void newplayercollectiondejacree(int b); // si le joueur est un nouveau joueur prend un collection deja creee pour sa collection;
        void newplayerSANScollectiondejacree(int b, int a); // si le joueur est un nouveau joueur on cree sa collection;
        void Generalechargementdepuisfichier(std::string quelfichier, std::map<int,Card*> &map_collec, int dejainscritounon); // chargement depuis un fichier;
        void determinationdescartesagagner(int nb_de_cartes_misees, int modebot);//determination des cartes a gagner;
    
        // Methode d'affichage;
        void affichagenombredecarteenergy(); // affichage du nombre de carte energy;
        void affichagedudeckdeque(int nbrsdecartepardeck);//affichage du deque DECK;
        void infoplayer_affichage(); //affichage des informations du joueur;

        // Boucle de jeu;
        void premiertiragepioche(); // 1 tour boucle de jeu;
        void generalisation(int _robotcontrerobot);      // Boucle de jeu pour le reste des tours;
    
        int onattaque(Player *Ennemi, int _robotcontrerobot); //boucle pour attaquer;
        void ondefend(int _robotcontrerobot); //boucle pour se defendre;
        int mortplayer(); // boucle pour la mort d’un joueur, game over;
        void mortcreatureactive(int _robotcontrerobot); // boucle pour la mort d’une creature en action;
        void ongerecartespecialplayer(); //boucle pour la gestion des cartes speciales;
    
        void ecrituredansfichieralafin(std::map <int, Card*> addalacollection);
        
    // Acesseurs:
        Card* getsurinaction(){return inaction;}; //getter pour les cartes en action;
        std::string getm_player_name(){return m_player_name;}; //getter pour le nom du joueur;
        std::map <int, Card*> getenjeu(){return m_carteagagner;}; //getter pour les cartes a gagner;
        int getm_lifepointplayer(){return m_lifepointplayer;}; //getter pour les points de vie du joueur;
        void setm_lifepointplayer(int newptsdevie){m_lifepointplayer=newptsdevie;}; //setter pour les points de vie du joueur;
        std::map <std::string, int> get_tabcarteenergieposer(){return tabcarteenergieposer;}; //getter pour les cartes energies sur la table de jeu;
    void set_tabcarteenergieposer(int a, int b, int c, int d); //setter pour les cartes energies sur la table de jeu;

};
#endif /* Player_hpp */
