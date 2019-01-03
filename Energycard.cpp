//
//  Energycard.cpp
//  ProjetIng2sem1
//
//  Created by Partouche on 12/11/2017.
//  Copyright © 2017 Partouche. All rights reserved.
//

#include "Energycard.hpp"

Energycard::Energycard()
{
    m_energy="Null";
    m_card_name="Null";
    m_prix=50;
    m_type="EnergyCard";
}

Energycard::Energycard(std::string domaine, std::string card_name, int prix)
{
    m_card_name=card_name;
    m_energy=domaine;
    m_prix=prix;
    m_type="EnergyCard";

}

void Energycard::descriptiondelacarte()
{
	//std::cout << "Descrition de la carte :";

	std::cout << "Nom de la carte : " << m_card_name;
	std::cout << " Type d'energie : " << m_energy << ".";
    std::cout << " Prix : " << m_prix << "." << std::endl;
}
