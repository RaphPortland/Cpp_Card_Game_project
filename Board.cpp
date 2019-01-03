//
//  Board.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 10/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "Board.hpp"

// Implementation du constructeur de la classe board;
Board::Board() : m_howmanyplayers(2), m_howmanycardineachdeck(13), m_nbrsdecarteagagner(1), m_nrdsdepointdevieparjoueuraudepart(50)
{

}

// Implementation de la fonction qui gere le menu principal;
int Board::menuprincipale()
{
    int choix=3;
// Boucle pour le choix voulu dans le menu;
    do {
        std::cout << "Menu Principal :" << std::endl; // Menu principal;
        std::cout << "1. Jouer" << std::endl; // Choix jouer;
        std::cout << "2. Option" << std::endl; //Choix pour aller dans les options;
        std::cout << "3. Quitter le jeu" << std::endl; //Choix pour quitter le jeu;

        std::cin >> choix;  // A l'utilisateur d'inserer un numero en fonction du choix qu’il veut faire;
        if (choix!=1 && choix!=2 && choix!=3) // Blindage;
        {
            std::cout << "Veuillez inserer un numero valable" << std::endl;
        }
    } while (choix!=1 && choix!=2 && choix!=3);
    return choix; // On retourne le choix de l’utilisateur;
}

// Implementation de la procedure qui affiche les differentes options;
void Board::option_affichage(){        
           std::cout << "Nombre de joueurs : " << m_howmanyplayers << "." << std::endl;
           std::cout << "Nombre de cartes par deck : " << m_howmanycardineachdeck << "." << std::endl;
            std::cout << "Nombre de cartes mises en jeu (Combien de cartes gagnera le gagnant) : " << m_nbrsdecarteagagner << "." << std::endl;
            std::cout << "Nombre de points de vie au depart : " << m_nrdsdepointdevieparjoueuraudepart << "." << std::endl;
}

// Implementation de la procedure qui propose les differentes options possibles;
void Board::option()
{
    int option=4; // variable boucle pour le menu avec choix affichage, personnalisation ou sortir du menu;
    int choix=4; // variable boucle pour le changement d'option;
    do { // Boucle pour le menu avec choix affichage, personnalisation ou sortir du menu;
        std::cout << "1. Afficher les parametres/options : 1" << std::endl;
        std::cout << "2. Personaliser les parametres/options : 2" << std::endl;
        std::cout << "3. Sortir du menu Option : 3" << std::endl;
        std::cin >> option;
        if (option!=1 && option!=2 && option!=3) // Blindage;
        {
            std::cout << "Veuillez inserer un numero valable" << std::endl;
        }
        
        if (option==1) // Afficher option en appelant la fonction qui permet leur affichage;
        {
           option_affichage();
        }
        if (option==2) // Parametrer notre jeu; 
        {
            do {        //boucle pour le changement d'option;
                std::cout << "Veuillez choisir quelle option voulez vous parametrer " << std::endl;
                std::cout << "1. Nombre de joueur " << std::endl;
                std::cout << "2. Nombre de cartes par deck " << std::endl;
                std::cout << "3. Nombre de cartes mises en jeu" << std::endl;
                std::cout << "4. Nombre de points de vie par joueur" << std::endl;
                std::cout << "5. Sortir du menu de parametrages : 5" << std::endl;

                std::cin >> choix;  // A l'utilisateur d'inserer un numero en fct du choix qu’il veut faire;
                if (choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5) // Blindage;
                {
                    std::cout << "Veuillez inserer un numero valable" << std::endl;
                }
                if (choix==1) // Parametrage du nombre de joueurs durant la partie;
                {
                    do {
                        std::cout << "Nombre de joueur : 1, 2, 3 ou 4" << std::endl;
                        std::cin >> m_howmanyplayers; // On entre le nombre de joueur voulu;
                        if (m_howmanyplayers!=1 && m_howmanyplayers!=2 && m_howmanyplayers!=3 &&m_howmanyplayers!=4) // if pour le blindage;
                        {
                            std::cout << "Veuillez entrer un nombre compris entre 1 et 4" << std::endl;
                        }
                    } while (m_howmanyplayers!=1 && m_howmanyplayers!=2 && m_howmanyplayers!=3 &&m_howmanyplayers!=4); // do...while pour le blindage;
                }
                if (choix==2) //Parametrage du nombre de carte voulu dans le deck;
                {
                    do {
                        std::cout << "Nombre de carte dans le deck : 15, 20, 30 ou 45" << std::endl;
                        std::cin >> m_howmanycardineachdeck; // Nombre de carte dans le deck voulu;
                        if (m_howmanycardineachdeck!=15 && m_howmanycardineachdeck!=20 && m_howmanycardineachdeck!=30 &&m_howmanycardineachdeck!=45)
                        {
                            std::cout << "Veuillez entrer un nombre egal a 15, 20, 30 ou 45" << std::endl;
                        }
                    } while (m_howmanycardineachdeck!=15 && m_howmanycardineachdeck!=20 && m_howmanycardineachdeck!=30 &&m_howmanycardineachdeck!=45);
                    //do...while pour le blindage;
                }
                if (choix==3) // Parametrage du nombre de carte mise en jeu, c’est a dire du nombre de carte que le gagnant remportera a la fin de la partie;
                {
                    do {
                        std::cout << "Nombre de cartes mises en jeu : 1, 2, 3 ou 4" << std::endl;
                        std::cin >> m_nbrsdecarteagagner; // On entre le nombre de joueur voulu pendant la partie;
                        if (m_nbrsdecarteagagner!=1 && m_nbrsdecarteagagner!=2 && m_nbrsdecarteagagner!=3 && m_nbrsdecarteagagner!=4) // if pour le blindage;
                        {
                            std::cout << "Veuillez entrer un nombre compris entre 1 et 4" << std::endl;
                        }
                    } while (m_nbrsdecarteagagner!=1 && m_nbrsdecarteagagner!=2 && m_nbrsdecarteagagner!=3 && m_nbrsdecarteagagner!=4); // do...while pour le blindage;
                }
                if (choix==4) // Parametrage du nombre de carte mise en jeu, c’est a dire du nombre de cartes que le gagnant remportera a la fin de la partie;
                {
                    do {
                        std::cout << "Nombre de points de vie par joueur" << std::endl;
                        std::cin >> m_nrdsdepointdevieparjoueuraudepart; // On entre le nombre de vie par joueur voulu au début de la partie;
                        if (m_nrdsdepointdevieparjoueuraudepart<=0) // if pour le blindage,
                        {
                            std::cout << "Veuillez entrer un nombre positif" << std::endl;
                        }
                    } while (m_nrdsdepointdevieparjoueuraudepart<=0); // do...while pour le blindage;
                }
            } while (choix!=5);
        }
    } while (option!=3);
    
}

// Implementation de la procedure qui va « initialiser » chaque joueur;
void Board::remplissagejoueur(std::map<int, Player> &map_player, Board plateau, int fullrobot){
    int modebot=0;
    do{ //Boucle pour choisir le mode d’initialisation des cartes du joueur (manuel ou automatique);
        if (fullrobot!=1)
        {
            std::cout << "Voulez-vous activer un mode <bot> qui se desacativera au debut du jeu (Toute la phase d'innitialisation des decks se fera automatiquement)\n1. OUI \n2. NON" << std::endl;
            std::cin >> modebot;
        }
        else {
            modebot=1;
        }

        if (modebot!=1 && modebot!=2){
            std::cout << "Erreur, veuillez entrer un numero compris 1 et 2" << std::endl;
        }
    } while(modebot!=1 && modebot!=2); // Blindage;
    
    for (int i=0; i<plateau.getm_howmanyplayers();i++){
        Player joueurX;
        std::cout << "Pour le joueur " << i+1 << std::endl;
        joueurX.initplayer(plateau.getm_howmanycardineachdeck(), plateau.getm_nrdsdepointdevieparjoueuraudepart(), plateau.getm_nbrsdecarteagagner(), modebot);
        map_player[i]=joueurX;
    }

}

// Implementation de la fonction qui gere le jeu;
void Board::jeu(std::map<int, Player> &map_player, Board plateau, int fullrobot) // Si full robot =1 alors un robot joue contre un autre
{
    int salut=0;
    int j=0;
    int compteurdetour=0;
    int robotcontrerobot=0;
    
    do{ //Boucle pour choisir le mode d’initialisation des cartes du joueur (manuel ou automatique);
        if (fullrobot!=1)
        {
            //std::cout << "Voulez-vous activer voir une partie robot contre robot :\n1. OUI \n2. NON" << std::endl;
            
           // std::cin >> robotcontrerobot;
            robotcontrerobot=2;
        }
        else
        {
            robotcontrerobot=1;
        }

        if (robotcontrerobot!=1 && robotcontrerobot!=2){ // Si robot contre robot = 1 alors ça joue tout seul
            std::cout << "Erreur, veuillez entrer un numero compris 1 et 2" << std::endl;
        }
    } while(robotcontrerobot!=1 && robotcontrerobot!=2); // Blindage;
    
    for (int i=0; i<plateau.getm_howmanyplayers();i++){ // Debut du jeu; 
        std::cout << "Bon jeu ! au joueur " << i+1 <<"(" << map_player[i].getm_player_name() << ")" <<   std::endl;
        std::cout << "A " << map_player[i].getm_player_name() <<" de jouer :"<<  std::endl; // Indique quel joueur doit commencer a jouer;
        map_player[i].premiertiragepioche();    // Premier tirage, on tire une carte jusqu'a que ca soit une carte Creature;
        //map_player[i].affichagenombredecarteenergy(); // Affichage du nombre de carte energie apres avoir recu sa carte creature;
    }
    std::cout << "\n\n\n........... DEBUT DU JEU ..........." << std::endl;
    int b=2, onestla=0;
// Boucle pour la gestion du jeu d’un joueur apres que tous les joueurs aient chacun joue une fois et tire une carte creature;
    do {
        for (int i=0; i<plateau.getm_howmanyplayers();i++){
            if (onestla!=1)
            {
                std::cout <<std::endl << "------------CHANGEMENT DE JOUEUR------------" << std::endl << std::endl;
            }
            onestla=0;
            std::cout << "A " << map_player[i].getm_player_name() <<" de jouer :"<<  std::endl << "Carte en action : " ; // Indique quel joueur doit jouer et indique les cartes en action;
            map_player[i].getsurinaction()->descriptiondelacarte(); 
            map_player[i].generalisation(robotcontrerobot);
            if (robotcontrerobot!=1) // Car si = 1 alors l'ordi joue seul
            {
                map_player[i].ongerecartespecialplayer();
            }
            
            auto it=map_player.find(i+1);
            j=i+1;
            if (i+1>=plateau.getm_howmanyplayers())
            {
                it=map_player.find(0);
                j=0;
            }
            b= map_player[i].onattaque(&(it->second), robotcontrerobot); // Attaque du joueur qui joue son tour contre un autre joueur de la partie;
            if (b==1)
            {
                map_player[j].ondefend(robotcontrerobot); // Défense du joueur qui se fait attaquer par le joueur qui joue son tour;
                onestla=1;
            }
            for  (int i=0; i<map_player.size();i++){
                map_player[i].mortcreatureactive(robotcontrerobot); // On verifie l’état de la creature qui vient de se faire attaquer;
            }

            for (int j=0;j<plateau.getm_howmanyplayers();j++) // On verifie que personne ne soit mort;
            {
                if(map_player[j].mortplayer()==1) // On sort de la boucle for si il y a pas de mort et s’il y a un mort le mort cede ses carte au gagnant;
                {
                    std::cout << "Le joueur " << i+1 << " / " << map_player[j].getm_player_name() << " a perdu " << std::endl<< std::endl;
                    std::cout << "......Attribution des cartes mises en jeu au gagnant......" << std::endl;
                    map_player[i].ecrituredansfichieralafin(map_player[j].getenjeu());

                    salut=36;
                    i=plateau.getm_howmanyplayers()+1;
                    /*for (auto elem : map_player[i].getenjeu())
                    {
                        std::cout << "Voici la carte " << elem.first << "Que le gagnant a gagner"<< std::endl;
                        elem.second->descriptiondelacarte();
                    }*/
                }
            }
        }
        compteurdetour++; // on passe au tour suivant et on change de joueur;
        if (compteurdetour>=300)
        {
            std::cout << "***************** MATCH NUL *****************" << std::endl;
            salut=36;
        }

    } while (salut!=36);
}
