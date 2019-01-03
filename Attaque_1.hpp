//
//  Attaque_1.hpp
//  ProjetIng2sem1
//
//  Created by Partouche on 28/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#ifndef Attaque_1_hpp
#define Attaque_1_hpp

#include <stdio.h>
#include <iostream>
#include <map>


class Attaque_1
{
    private :
    int m_puissance;    //Valeur puissance de l'Attaque_1
    std::string m_name_attaque;     //Nom attaque utilisée
    std::map<std::string, int> map_domaine;     //Conteneur Domaine requis pour utiliser l'attaque
    
public:
    Attaque_1();    //CTOR 
    Attaque_1(std::string nom_dattaque); //CTOR Surchargé
    std::string getm_name_attaque(){return m_name_attaque;};      //Getter nom de l'attaque
    void affichagenomdattaque();        //Affichage infos
    int getm_puissance(){return m_puissance;}       //Getter Puissance de l'attaque
    void affichagedomaine();    
    std::map<std::string, int> getmap_domaine(){return map_domaine;};   //Getter conteneur domaine requis pour utiliser l'attaque
    void setpuissance (int _puissance){m_puissance=m_puissance+_puissance;};    //Setter de la puissance de l'attaque

};
#endif /* Attaque_1_hpp */
