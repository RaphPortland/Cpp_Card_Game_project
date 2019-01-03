//
//  Specialcard.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 03/12/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "Specialcard.hpp"

Specialcard::Specialcard()
{
    m_prix=100;
    recyclable=0;
    m_prix=100;
    uniqueoupersistant=1;
    m_type="SpecialCard";
}
//                         	int uniqueoupersistant; // 1 -> persistant, 0 -> unique
//int recyclable; // 1 ->Oui, 0 -> Non
// int attou;
Specialcard::Specialcard(std::string _name,int _recyclable, int Persistent, int _puissance, int prix)
{
    recyclable=_recyclable;
    uniqueoupersistant=Persistent;
    attou=_puissance;
    m_card_name=_name;
    m_prix=prix;
    m_type="SpecialCard";
}

void Specialcard::action(Player &parametre)
{
	if (m_card_name=="LoiMacron") // On add des points au PERSO avec cette carte
	{
       
        parametre.setm_lifepointplayer(getm_life_point()+attou);
        std::cout << "On add " << attou << " Point de vie au joueur" << std::endl;
	}
    if (m_card_name=="SacrificeMilitaire")    // On add des points d'attaque a toutles attaque du joueur SEULMENT SI ON ENLEVE 1 CARTE Militaire CHEZ LUI
    {
        std::map <std::string, int > tab_carteposer= parametre.get_tabcarteenergieposer();
        auto it = tab_carteposer.find("Militaire");
        if (it->second>=1){
            parametre.getsurinaction()->changementpuissanceattaque(attou);
            parametre.set_tabcarteenergieposer(tab_carteposer["Militaire"]-1,tab_carteposer["Politique"] , tab_carteposer["Economie"], tab_carteposer["Urbanisme"]);
            std::cout << "On add " << attou << " Points d'attaque a la carte en action du joueur en perdant une carte Militaire " << std::endl;
        }
    }
    if (m_card_name=="AttaqueMilitaire") // Juste on ajoute un nombre x aux attaques de la carte en action du joueur
    {
        parametre.getsurinaction()->changementpuissanceattaque(attou);
    }
    if (m_card_name=="MaisonBlanche") // On enleve des points au joueur -> Mauvaise carte
    {
        parametre.setm_lifepointplayer(getm_life_point()-attou);
        std::cout << "On enleve " << attou << " Point de vie au joueur" << std::endl;
    }
    if (m_card_name=="CarteMao") // On add des 2 fois plus de points au PERSO avec cette carte
    {
       
        parametre.setm_lifepointplayer(getm_life_point()+2*attou);
        std::cout << "On add " << attou << " Point de vie au joueur" << std::endl;
    }
    if (m_card_name=="Chancelier")    // On add des points d'attaque a toutles attaque du joueur SEULMENT SI ON ENLEVE 1 CARTE ENERGIE CHEZ LUI
    {
        std::map <std::string, int > tab_carteposer= parametre.get_tabcarteenergieposer();
        auto it = tab_carteposer.find("Economie");
        if (it->second>=1){
            parametre.getsurinaction()->changementpuissanceattaque(attou);
            parametre.set_tabcarteenergieposer(tab_carteposer["Militaire"],tab_carteposer["Politique"] , tab_carteposer["Economie"]-1, tab_carteposer["Urbanisme"]);
            std::cout << "On add " << attou << " Points d'attaque a la carte en action du joueur en perdant une carte Economie" << std::endl;
        }
    }
    
}

void Specialcard::descriptiondelacarte(){
    std::cout << "Nom de la carte : " << m_card_name << " Puissance: " << attou << " Prix : " << m_prix;
    if (recyclable==0){
        std::cout << " Recyclable : NON";
    }
    else{std::cout << " Recyclable : OUI";}
    if (uniqueoupersistant==0){
        std::cout << " Persistant : NON"<< std::endl;
    }
    else{std::cout << " Persistant : OUI"<< std::endl;}
}
