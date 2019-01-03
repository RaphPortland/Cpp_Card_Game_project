
//
//  Player.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "Player.hpp"

// Implementation du constructeur par defaut de la classe player;
Player::Player() : m_player_name("Salut"), m_sous(1000),m_lifepointplayer(100),m_collection("player1")
{
    tabcarteenergieposer["Militaire"]=0; //Militaire, Politique, Economique ou Culturelle;
    tabcarteenergieposer["Politique"]=0;
    tabcarteenergieposer["Economie"]=0;
    tabcarteenergieposer["Urbanisme"]=0;
    
}

// Implementation du constructeur surcharge de la classe player;
Player::Player(int pointdevieparjoueur, std::string name)   // On enverra en parametre plateau.getm_nrdsdepointdevieparjoueuraudepart(); + Le nom du joueur voulu
{
    m_player_name=name;
    m_sous=1000;
    m_lifepointplayer=pointdevieparjoueur;
    tabcarteenergieposer["Militaire"]=0; //Militaire, Politique, Economique ou Culturelle;
    tabcarteenergieposer["Politique"]=0;
    tabcarteenergieposer["Economie"]=0;
    tabcarteenergieposer["Urbanisme"]=0;
}

// Implementation de la procédure qui ecrit toutes les informations dans le fichier a la fin d’une partie ;
void Player::ecrituredansfichieralafin(std::map <int, Card*> addalacollection){  // On ajoute au gagnant les cartes du perdant dans sa collection (en effet il vient de les gagner);
    
    std::ofstream fichier("/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player3.txt", std::ios::app);  // on ouvre le fichier en lecture
    
    if(fichier)  // si l'ouverture a reussi;
    {
        for (auto elem : addalacollection){ // ajout a la collection;
            std::string TYPE = addalacollection[elem.first]->getm_type();

            if (TYPE == "WickedCard"){ //si la carte est une carte creature on lit le nom, les points de vies de la creature, les attaques de la creature;
                int pointsdevie= addalacollection[elem.first]->getm_life_point();
                std::string nom = addalacollection[elem.first]->getm_nom();
                int prix= addalacollection[elem.first]->getm_prix();
                std::string attaque1= addalacollection[elem.first]->gettab_attaque()[0].getm_name_attaque();
                std::string attaque2= addalacollection[elem.first]->gettab_attaque()[1].getm_name_attaque();
                
                fichier << std::endl;
                fichier << TYPE <<" "<<  pointsdevie <<" "<<  nom <<" "<<  prix <<" "<<  attaque1 <<" "<<  attaque2;
            }
            
            if (TYPE == "EnergyCard"){ //Si la carte est une carte energie on lit le nom, le prix et le dommaine;
                std::string nom = addalacollection[elem.first]->getm_nom();
                int prix= addalacollection[elem.first]->getm_prix();
                std::string domaine = addalacollection[elem.first]->getm_energy();
                
                fichier << std::endl;
                fichier << TYPE <<" " << nom << " "<< domaine <<" "<<  prix ;
            }
            if (TYPE == "SpecialCard") // si la carte est une carte spéciale on lit le nom, si elle est persistante ou non, si elle est recyclable ou non, la puissance de la carte;
            {
                int prix= addalacollection[elem.first]->getm_prix();
                std::string nom = addalacollection[elem.first]->getm_nom();
                int persistente= addalacollection[elem.first]->getuniqueoupersistant();
                int recyclable= addalacollection[elem.first]->getrecycleble();
                int puissance=addalacollection[elem.first]->getattou();
                fichier << std::endl;
                fichier << TYPE <<" " << nom <<" " << persistente<<" " <<  recyclable <<" " <<  puissance <<" " << prix ;
            }
            
        }
        // instructions;
        fichier.close();  // on ferme le fichier;
    }
    else  // sinon on dit au joueur qu’il est impossible d’ouvrir le fichier;
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
    
}

// Implementation du setter (accesseur lecture) pour les cartes energies sur la table de jeu;
void Player::set_tabcarteenergieposer(int a, int b, int c, int d){
    tabcarteenergieposer["Militaire"]=a; //Militaire, Politique, economique ou culturelle;
    tabcarteenergieposer["Politique"]=b;
    tabcarteenergieposer["Economie"]=c;
    tabcarteenergieposer["Urbanisme"]=d;
};

// Implementation de la procedure qui gere les cartes speciales du joueur;
void Player::ongerecartespecialplayer(){
    if (tab_special.size()>0)
    {
        for (int i=0; i<tab_special.size();i++)
        {
            tab_special[i]->action(*this);
            std::cout << "On a passe l'action speciale " << std::endl;
            /*if (tab_special[i]->getuniqueoupersistant()==1)
             {
             std::cout << "C'est persistentente on le laisse dans le tableau des carte special" << std::endl;
             }
             else
             {
             std::cout << "Carte non persistente" << std::endl;
             cimetiere.push_back(tab_special[i]);
             tab_special.erase(i);
             
             }       */
            /* if (tab_special[i]->getrecyclable()==1)
             {
             std::cout << "Carte recyclable" << std::endl;
             
             deque_pioche_deck.push_back(tab_special[i]);
             tab_special.erase(i);
             }
             else
             {
             std::cout << "Carte non recyclable" << std::endl;
             
             cimetiere.push_back(tab_special[i]);
             tab_special.erase(i);
             
             }   */
        }
        
    }
}

// Implementation de la procedure qui gere la mort des cartes creatures;
void Player::mortcreatureactive(int _robotcontrerobot)
{
    int choix=1, salut=1;
    if (inaction->getm_life_point()<=0) // si les points de vies de la creature active sont nuls ou negatifs;
    {
        std::cout << "La carte de " << m_player_name << "inaction est morte.. Il perd donc 10 PV player" << std::endl;
        m_lifepointplayer=m_lifepointplayer-10;
        std::cout << "Il vous faut cependant une carte en action. Selectioner en une au choix presente dans vos cartes en attente " << std::endl;
        if (tab_creatureenattente.size()>0) // on regarde s’il y a des cartes creatures en attentes;
        {
            do{
                for (int i=0; i<tab_creatureenattente.size();i++)
                {
                    std::cout << "Carte en attente " << i << ". ";
                    tab_creatureenattente[i]->descriptiondelacarte();
                }
                if (_robotcontrerobot!=1)
                {
                    std::cin >> choix;
                }
                else
                {
                    choix=tab_creatureenattente.size()-1;
                }

                if (choix <0 || choix >= tab_creatureenattente.size())
                {
                    std::cout << "Veuillez rentrer un nombre compris en 0 et " << tab_creatureenattente.size()-1 << std::endl;
                    salut=1; // le joueur qui a perdu sa carte creature active recupere une carte creature en attente;
                }
                else
                {
                    salut=0;
                }
            } while (salut==1);
        }
        else { // si le joueur n’a plus de cartes creatures il meurt;
            std::cout << "Vous n'avez plus de cartes en attente, et votre perso est mort " << std::endl;
            m_lifepointplayer=0;
        }
        
        if (salut==0)
        {
            cimetiere.push_back(inaction);
            std::cout << "inaction=tab_creatureenattente[choix]" << std::endl;
            std::cout << "Description avant : " << std::endl;
            inaction->descriptiondelacarte();
            inaction=tab_creatureenattente[choix];
            tab_creatureenattente.pop_back();
            std::cout << "Description apres : " << std::endl;
            
            inaction->descriptiondelacarte();
        }
    }
}

// Implementation de la procedure qui permet au joueur attaque de se défendre;
void Player::ondefend(int _robotcontrerobot)
{
    int somme =0, choix = 0;
    for (auto elem : tabcarteenergieposer)// on parcourt les cartes energies posees;
    {
        somme=somme+elem.second;
    }
    if (somme>1) //si les cartes energies necessaires son disponibles alors le joueur peut se defendre contre l’attaque;
    {
        std::cout << "------------CHANGEMENT DE JOUEUR------------" << std::endl;
        std::cout << "Passer la main au joueur " << m_player_name << std::endl;

        do {
            if (_robotcontrerobot!=1)
            {
                std::cout << "Vous disposez de "<< somme << " cartes energie vous avez le droit de vous defendre: \nVoulez-vous vous defendre \n1. Oui \n2. Non " <<std::endl;
                std::cin >> choix;
            }
            else
            {
                choix=2;
            }

            if (choix==1)
            {
                choix=2;
                std::cout << "Votre defense sera de puissance " << somme << " x 5" << std::endl;
                inaction->setptsdeviecreature(inaction->getm_life_point()+somme*5);
            }
        } while (choix!=2);
        
    }
}

// Implementation de la procedure qui permet au joueur qui joue d’attaquer son ennemi;
int Player::onattaque(Player *Ennemi,int _robotcontrerobot){
    std::cout << "------Attaque------" << std::endl;
    ptssurennemi=Ennemi; // on trouve l’ennemi a attaquer;
    std::cout << "Le joueur " << m_player_name << " Attaque le joueur " << Ennemi->getm_player_name() << std::endl; //on annonce quel joueur attaque quel joueur;
    int a =inaction->attaquer(ptssurennemi,tabcarteenergieposer, _robotcontrerobot); // le joueur attaque l’ennemi;
    return  a;
}

// Implementation de la fonction gameover pour le joueur qui perd ses points de vie;
int Player::mortplayer() // Gameover player;
{
    int playermort=0;
    
    if (m_lifepointplayer<=0) // Si le joueur n’a plus de vie il meurt et game over;
    {
        playermort=1;// Retourne true si le joueur mort;
    }
    
    return playermort;  // Retourne 0 si le joueur est vivant, et 1 sinon;
}

// Implementation de la procedure de generalisation;
void Player::generalisation(int _robotcontrerobot){ // Si robot contre robot =1 alors l'ordi joue seul
    // gestion de la pioche;
    std::cout << "taille pioche" <<  deque_pioche_deck.size() << std::endl;
    if (deque_pioche_deck.size()>0)
    {
        std::string type=deque_pioche_deck.front()->getm_type();;
        int choix;
        if (type=="EnergyCard") //gestion de la pioche si la carte est une EnergyCard;
        {
            std::string energy= deque_pioche_deck.front()->getm_energy();
            tabcarteenergieposer[energy]=tabcarteenergieposer[energy]+1;
            std::cout << m_player_name <<" ON PIOCHE"<<  std::endl;
            deque_pioche_deck.front()->descriptiondelacarte();
            deque_pioche_deck.pop_front();
        }
        if (type=="WickedCard") //gestion de la pioche si la carte est une WickedCard;
        {
            std::cout << m_player_name <<" PIOCHAGE  :";
            deque_pioche_deck.front()->descriptiondelacarte();
            if (_robotcontrerobot!=1)
            {
                std::cout << "Voulez vous \n1. Mettre en action cette carte \n2. Laisser la carte en attente \n3. jeter la carte directement au cimetiére" << std::endl;
                std::cin >> choix;
            }
            else
            {
                choix=2;
            }

            if (choix==1)
            {
                cimetiere.push_back(inaction); // On met au cimetiere
                inaction=deque_pioche_deck.front();
                
            }
            if (choix==2)
            {
                tab_creatureenattente.push_back(deque_pioche_deck.front());
            }
            if (choix==3)
            {
                cimetiere.push_back(deque_pioche_deck.front());
            }
            
            deque_pioche_deck.pop_front();
        }
        if (type=="SpecialCard") //gestion de la pioche si la carte est une SpecialCard;
        {
            std::cout << m_player_name <<" PIOCHAGE  :";
            deque_pioche_deck.front()->descriptiondelacarte();
            if (_robotcontrerobot!=1)
            {
                std::cout << "1. On l'utilise \n2. On la met au cimetiere\n";
                std::cin >> choix;
            }
            else
            {
                choix=2;
            }

            if (choix==1)
            {
                int a =tab_special.size();
                tab_special[a]=deque_pioche_deck.front();
                
            }
            
            if (choix==2)
            {
                
                cimetiere.push_back(deque_pioche_deck.front());
            }
            deque_pioche_deck.pop_front();
            
        }
    }
    else //la pioche est ecoulee;
    {
        std::cout << "Plus de pioche dispo" << std::endl;
    }
}

// Implementation de la procedure pour le premier tirage de la pioche;
void Player::premiertiragepioche (){ 
    //std::cout << "on arrive ici" << std::endl;
    std::string type ;
    std::cout << "Taille deck : " << deque_pioche_deck.size() <<  std::endl;
    
    int cestbononaunecreature=0;
    // boucle qui indique ce que l’on pioche;
    do {
        type= deque_pioche_deck.front()->getm_type();
        std::cout << m_player_name << " ON PIOCHE :  " << std::endl;
        deque_pioche_deck.front()->descriptiondelacarte();
        if (type=="EnergyCard") // si on pioche une carte energie on la garde ou on la met au cimetière et on repioche;
        {
            std::string energy= deque_pioche_deck.front()->getm_energy();
            tabcarteenergieposer[energy]=tabcarteenergieposer[energy]+1;
            cimetiere.push_back(deque_pioche_deck.front()); // On envoi dans le cimetiere;
        }
        if (type=="WickedCard") // Si on pioche une carte energy c’est bon on arrete de piocher et c’est au joueur suivant;
        {
            cestbononaunecreature=1;
            inaction=deque_pioche_deck.front();
        }
        if (type=="SpecialCard") // si on pioche une carte speciale on la garde ou on la met au cimetière et on repioche;
        {
            deque_pioche_deck.push_back(deque_pioche_deck.front());
        }

        deque_pioche_deck.pop_front();    
    } while (cestbononaunecreature!=1 && deque_pioche_deck.size()>0); // tant que l’on a pas de carte creature on continue la boucle, c’est a dire que l’on continue de piocher;
}
            
// Implementation de la procedure pour l’affichage du nombre de carte energie;
void Player::affichagenombredecarteenergy(){
    std::cout << "affichage des cartes energy de " << m_player_name <<  " : "<< std::endl;
    for (auto elem : tabcarteenergieposer){
        std::cout << elem.first << "  " << elem.second << std::endl;
    }
                
}    
            // Implementation de la procedure pour le chargement de la map collection pour un joueur deja existant;
void Player::chargementdelamapcollection(int dejainscritounon, int modebot)// On charge depuis un fichier toutes les cartes;
        { //		std::map <int, Card*> map_collection;
            std::string quelfichier;
            std::string choix="ahah";
            if (modebot!=1){
                if (dejainscritounon==1)
                {
                    do {
                        std::cout << "Quelle est la collection associee a votre joueur : " << std::endl;
                        std::cout << "player1 ou player2 ou player3 ou player4 " << std::endl;
                        std::cin >> choix;
                    } while (choix!="player1" && choix!="player2" && choix!="player3" && choix!="player4");
                }
                if (dejainscritounon==2)
                {
                    choix=m_collection;
                }
            }
            if (modebot==1)
            {
                int a=rand()%2;
                //std::cout << "Fonction Player::chargementdelamapcollection deteremination de quel fichier : " << a << std::endl;
                if (a==0)
                {
                    choix="player5";
                }
                if (a==1)
                {
                    choix="player6";
                }
                std::cout << "Choix fichier : " << choix << std::endl;
            }
            
            if (choix=="player1"){quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player1.txt";}
            if (choix=="player2"){quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player2.txt";}
            if (choix=="player3"){quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player3.txt";}
            if (choix=="player4"){quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player4.txt";}
            if (choix=="player5"){quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player5.txt";}
            if (choix=="player6"){quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/player6.txt";}
                        
            Generalechargementdepuisfichier(quelfichier, map_collection, dejainscritounon);
            
            if (dejainscritounon==1)
            {
                std::cout << "Welcome back " << m_player_name << std::endl;
            }
        }
            
            // Implementation de la procedure pour la map collection deja creee d’un nouveau joueur;
            void Player::newplayercollectiondejacree(int b)
        {
            int choix=0;
            std::string quelfichier;
            std::cout << "Création d'un nouveau joueur :  " << std::endl;
            //std::cout << "AVEC COLLECTION PRE FAITE " << std::endl;
            
            std::cout << "Votre Surnom : ";
            std::cin >> m_player_name;
            do {
                std::cout << "Numero de la collection associée :\n1. player1 : 1\n2. player2 : 2\n3. player3 : 3\n4. player4 : 4" << std::endl;
                std::cin >> choix;
                if (choix!=1 && choix!=2 && choix!=3 && choix!=4)
                {
                    std::cout << "Erreur, un nombre compris entre 1 et 4 est attendu" << std::endl;
                }
            } while(choix!=1 && choix!=2 && choix!=3 && choix!=4);
            switch (choix) {
                case 1:
                    m_collection="player1";
                    break;
                case 2:
                    m_collection="player2";
                    break;
                case 3:
                    m_collection="player3";
                    break;
                case 4:
                    m_collection="player4";
                    break;
            }
            std::cout << "Bienvenu " << m_player_name << std::endl;
            m_sous=1000;
            m_lifepointplayer=b;
            
            chargementdelamapcollection(2,2);
            
        }
            
            // Implementation de la procedure pour charger depuis les fichiers;
            void Player::Generalechargementdepuisfichier(std::string quelfichier, std::map <int, Card*> &map_collec, int dejainscritounon)
        {
            int i=0;
            std::string un_string,deux_string,trois_string,quatre_string,ligne,poubelle, attaque1, attaque2;
            int combien=0;
            int un_int,prix = 0, deux_int, trois_int;
            std::ifstream fichier(quelfichier, std::ios::in);  // on ouvre le fichier en lecture
            std::string name_of_player;
            if(fichier)  // si l'ouverture a réussi
            {
                
                // instructions
                if (dejainscritounon==1)
                {
                    fichier >> m_player_name;
                }
                if (dejainscritounon==2)
                {
                    fichier >> poubelle;
                    
                }
                while (getline(fichier, ligne)){
                    //std::cout << "on passe par la" << std::endl;
                    
                    fichier >> un_string ;
                    if (un_string=="EnergyCard")
                    {
                        fichier >> deux_string >> trois_string >> prix;
                        map_collec[i]= new Energycard(trois_string, deux_string,prix);
                    }
                    if (un_string=="WickedCard")
                    {
                        fichier >> un_int >> quatre_string >> prix >> attaque1 >> attaque2;
                        map_collec[i]= new Wickedcard(un_int,quatre_string,prix,attaque1,attaque2);
                    }
                    if (un_string=="SpecialCard")
                    {
                        fichier >> deux_string >> un_int >> deux_int >> trois_int;
                        map_collec[i]= new Specialcard(deux_string,un_int,deux_int, trois_int,prix);
                        combien ++;
                    }
                    i++;
                }
                
                fichier.close();  // on ferme le fichier
            }
            else  // sinon
                std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
            
        }
            
            // Implementation de la procedure pour la map collection non creee d’un nouveau joueur;
            void Player::newplayerSANScollectiondejacree(int b, int a){
                std::map<int, Card*> pourchargerlescartes;
                std::string quelfichier="/Users/partoucheraph/Documents/GitHub/Ing2sem1projet2017/touteslescartes.txt";
                
                std::cout << "Creation d'un nouveau joueur " << std::endl;
                std::cout << "SANS COLLECTION PRE FAITE " << std::endl;
                std::cout << "Nom : ";
                std::cin >> m_player_name;
                
                m_sous=7000;
                m_lifepointplayer=b;
                int i=0,j=0;
                int quitter;
                int cartevoulu;
                
                Generalechargementdepuisfichier(quelfichier, pourchargerlescartes,2);
                
                std::cout << "On a bien chargé le fichier <Toutes les cartes>" << std::endl;
                for (auto elem : pourchargerlescartes)
                {
                    std::cout << elem.first <<".";
                    elem.second->descriptiondelacarte();
                    j++;
                }
                std::cout << "Veuillez inserer le numero des cartes qui vous interesse" << std::endl;
                do {
                    std::cout << "Argent : " << m_sous <<std::endl;
                    std::cout << "1. Ajouter une carte a la collection : 1" << std::endl;
                    std::cout << "2. Quitter (Seulement si vous avez assez de carte pour remplir un deck): 2" << std::endl;
                    std::cin >> quitter;
                    if (quitter==1)
                    {
                        do{
                            std::cout << "Numero de carte voulu : " << std::endl;
                            std::cin >> cartevoulu;
                            if (cartevoulu>j || cartevoulu<0)
                            {
                                std::cout << "Inserer un nombre compris entre 0 et " << j-1 << std::endl;
                            }
                            else
                            {
                                //pourchargerlescartes[cartevoulu].
                                map_collection[i]=pourchargerlescartes[cartevoulu];
                                m_sous=m_sous-pourchargerlescartes[cartevoulu]->getm_prix();
                                i++;
                            }
                        } while(cartevoulu<a && cartevoulu<0);
                        
                    }
                    /*    if(quitter==2)
                     {
                     
                     }   */
                } while (quitter!=2);
            }
            
            // Implementation de la procedure qui permet le remplissage de la map carte pour le deck;;
            void Player::determinationdudeck(int nbrsdecartepardeck, int modebot) // On enverra en argument plateau.m_howmanycardineachdeck(); remplissage de la map carte_pour_deck;
        {
            int i=0,j;
            int choix;
            int nbrsdekey=0;
            int nombredecartetotal=0;
            if (modebot!=1){
                
                std::cout << "Voici la liste de vos cartes, merci d'en choisir " << nbrsdecartepardeck << std::endl;
                //std::cout << "map collection size" << map_collection.size() << std::endl;
                do {
                    j=0;
                    choix = -1;
                    for (auto elem : map_collection)
                    {
                        std::cout << elem.first <<".";
                        elem.second->descriptiondelacarte();
                        j++;
                        if (i==0){
                            nbrsdekey=j;
                            nombredecartetotal=nbrsdekey;
                        }
                    }
                    
                    while (choix>nbrsdekey || choix<0)
                    {
                        std::cout << "Veuillez inserer un nombre entre 0 et " << nombredecartetotal << std::endl;
                        std::cin >> choix;
                    }
                    
                    carte_pour_deck[i]=map_collection[choix];
                    map_collection.erase(choix);
                    i++;
                } while (i<nbrsdecartepardeck);
                std::cout << "Vous avez bien rempli votre deck de façon complete." << std::endl;
            }
            else {
                int size=map_collection.size();
                std::cout << "taille map collection chargé grace a BOT" << size <<std::endl;
                for (int i=0;i<nbrsdecartepardeck;i++)
                {
                    choix= rand()%size;
                    std::cout << "Remplissage du deck : " << choix << std::endl;
                    
                    carte_pour_deck[i]=map_collection[choix];
                    map_collection.erase(choix);
                }
                
            }
        }
            
            // Implementation de la procedure qui initialise le joueur;
            void Player::initplayer(int cbdecartepardeck, int pointdevieparjoueur, int nbrsdecarteagagner, int modebot)
        {
            int choix=1;
            int chargement = 0;
            if(modebot!=1){
                preinscritounon(choix, chargement);
            }
            if (choix==2)
            {
                if (chargement==1)
                {
                    newplayercollectiondejacree(pointdevieparjoueur);
                }
                if (chargement==2)
                {
                    newplayerSANScollectiondejacree(pointdevieparjoueur, cbdecartepardeck);
                }
            }
            if (choix==1)
            {
                chargementdelamapcollection(choix,modebot); // On charge toutes les données
            }
            determinationdescartesagagner(nbrsdecarteagagner,modebot);
            determinationdudeck(cbdecartepardeck, modebot); //On choisi les cartes que l'ont veut dans le deck
            startgameplayer(cbdecartepardeck); //Pioche prete
            affichagedudeckdeque(cbdecartepardeck);
            //joueur.infoplayer_affichage();
            
        }
            
            // Implementation de la procedure qui permet de voir si le joueur est inscrit ou non dans le jeu;
            void Player::preinscritounon(int &choix, int &chargement)
        {
            do{
                std::cout << "Voulez vous :\n1. Charger un joueur existant : 1\n2. Créer un nouveau joueur : 2 " << std::endl;
                std::cin >> choix;
                if (choix!=1 && choix!=2)
                {
                    std::cout << "Erreur, Un 1 ou un 2 est attendu" << std::endl;
                }
            }
            while(choix!=1 && choix!=2);
            if (choix==2){
                do {
                    std::cout << "Voulez vous :\n1. Nouveau joueur avec collection existante : 1\n2. Nouveau joueur avec création d'une collection : 2 " << std::endl;
                    std::cin >> chargement;
                    if (chargement!=1 && chargement!=2)
                    {
                        std::cout << "Erreur, Un 1 ou un 2 est attendu" << std::endl;
                    }
                    
                } while (chargement!=1 && chargement!=2);
            }
        }
            
            // Implementation de la procedure qui permet de passer de la MAP deck a une deque DECK en melangeant au passage;
            void Player::startgameplayer(int nbrsdecartepardeck)  // On passe de la map du deck a la deque (pile+file) de deck, en passant de carte_pour_deck a deque_pioche_deck on melange
        {   //      std::map <int, Card*> carte_pour_deck;
            //      std::deque <Card*> deque_pioche_deck;
            
            for (auto elem : carte_pour_deck){
                if (rand()%2==0){
                    deque_pioche_deck.push_back(elem.second);
                }
                else{
                    deque_pioche_deck.push_front(elem.second);
                }
            }
        }
            
            // Implementation de la procedure qui permet l’affichage du deque DECK;
            void Player::affichagedudeckdeque(int nbrsdecartepardeck){
                std::cout << "Voici votre Deck : " << std::endl;
                for (int i=0;i<nbrsdecartepardeck;i++){
                    deque_pioche_deck[i]->descriptiondelacarte();
                }
            }
            
            // Implementation de la procedure qui affiche toutes les informations du joueur;
            void Player::infoplayer_affichage()
        {
            std::cout << "Name " << m_player_name << std::endl;
            std::cout << "Sous " << m_sous << std::endl;
            std::cout << "life point " << m_lifepointplayer << std::endl;
            
        }
            
            // Implementation de la procedure qui determine les cartes misees et donc les cartes a gagner a la fin de la partie;
            void Player::determinationdescartesagagner(int nb_de_cartes_misees, int modebot){
                int iunombre;
                
                if (modebot!=1){
                    std::cout << "Veuillez indiquer les cartes que vous souhaiter mettre en jeu !" << std::endl;
                    
                    std::cout << "Voici les cartes de votre collection: " << std::endl;
                    for (auto elem : map_collection)
                    {
                        std::cout << elem.first <<".";
                        elem.second->descriptiondelacarte();
                    }
                    std::cout << "Saisissez le numéro de chacune des " << nb_de_cartes_misees << " cartes que vous voulez parier: ";
                    
                    for(int g=0; g<nb_de_cartes_misees; g++){
                        
                        std::cin >> iunombre;
                        auto it = map_collection.find(iunombre);
                        m_carteagagner[g]=it->second;
                        map_collection.erase(iunombre);
                    }
                }
                else {
                    for(int g=0; g<nb_de_cartes_misees; g++){
                        
                        iunombre=rand()%map_collection.size()-1;
                        std::cout << "Carte mise en jeu : " << iunombre << std::endl; 
                        
                        auto it = map_collection.find(iunombre);
                        m_carteagagner[g]=it->second;
                        map_collection.erase(iunombre);
                    }
                }
                //on va chercher dans la map collection des toutes les cartes le numero de celles que le joueur veut mettre en jeu en respectant le nb passe en parametre
                //on stockera ensuite ces cartes dans une seconde map
                
            }
