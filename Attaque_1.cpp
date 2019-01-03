//
//  Attaque_1.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 28/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "Attaque_1.hpp"

Attaque_1::Attaque_1()
{
    
}
Attaque_1::Attaque_1(std::string nom_dattaque)
{
    //COMPTEURS POINTS ENERGIE
    map_domaine["Politique"]=0;     
    map_domaine["Economie"]=0;
    map_domaine["Militaire"]=0;
    map_domaine["Urbanisme"]=0;
    m_name_attaque=nom_dattaque;
    
    for(int i=0;i<2;i++)// INITIALISATION DES ATTAQUES : en fct du nom de l'attaque passer en parametre On parcours tous les noms des attaques du jeu et on determine les points energy necessaires pour chaque attaque
    {
        
        if (nom_dattaque=="Deadlight") 
        {
            map_domaine["Economie"]=1;
            m_puissance=50;
        }
        if (nom_dattaque=="EagleClaw")
        {
            map_domaine["Politique"]=1;
            map_domaine["Militaire"]=1;
            m_puissance=150;
        }
        if (nom_dattaque=="Hama")
        {
            map_domaine["Politique"]=1;
            m_puissance=75;
        }
        if (nom_dattaque=="ASL")
        {
            map_domaine["Economie"]=1;
            map_domaine["Militaire"]=1;
            m_puissance=200;
        }
        if (nom_dattaque=="Changsha")
        {
            map_domaine["Urbanisme"]=1;
            m_puissance=60;
        }
        if (nom_dattaque=="Kuningtou")
        {
            map_domaine["Economie"]=1;
            map_domaine["Militaire"]=1;
            m_puissance=175;
        }
        if (nom_dattaque=="Monmouth")
        {
            map_domaine["Urbanisme"]=1;
            m_puissance=75;
        }
        if (nom_dattaque=="Clifton")
        {
            map_domaine["Politique"]=1;
            map_domaine["Economie"]=1;
            m_puissance=180;
        }
        if (nom_dattaque=="Heracles")
        {
            map_domaine["Economie"]=1;
            m_puissance=30;
        }
        if (nom_dattaque=="Providence")
        {
            map_domaine["Urbanisme"]=1;
            map_domaine["Economie"]=1;
            m_puissance=220;
        }
        if (nom_dattaque=="Trente")
        {
            map_domaine["Politique"]=1;
            m_puissance=50;
        }
        if (nom_dattaque=="Anton")
        {
            map_domaine["Urbanisme"]=1;
            map_domaine["Militaire"]=1;
            m_puissance=160;
        }
    }
    
}
void Attaque_1::affichagenomdattaque()  // Affichage des infos de l'attaque
{
    std::cout << m_name_attaque << " ";
    std::cout << m_puissance << std::endl;
    affichagedomaine();
}
void Attaque_1::affichagedomaine()   // Affichage des cartes energies requise pour attaquer 
{
    for (auto elem : map_domaine){
        std::cout << elem.first << " : " << elem.second << std::endl;
    }
}
