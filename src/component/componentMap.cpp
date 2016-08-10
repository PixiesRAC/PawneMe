#include <iostream>
#include "../../include/component/componentMap.hpp"

componentMap::componentMap()
{
  std::cout << "Initialisation de la map" << std::endl;
  deserialisationMapFile();
  //Va contenir la deserialisation du fichier contenant la map
  // La serialisation se fera via un fichier a part
  system("echo '01010100\n01010101\n20210101' > texture/map/MAP");
}

componentMap::~componentMap()
{

}


void	componentMap::update()
{
  std::cout << "Update de componentMap" << std::endl;
}

void	componentMap::deserialisationMapFile()
{
}
