#include <iostream>
#include "../../include/component/componentMap.hpp"

const std::string componentMap::fileTileset = "./texture/magecity.png";

componentMap::componentMap() : quad(sf::Quads, 4), _Cwindow(componentWindow::getWindow())
{
  std::cout << "Initialisation de la map" << std::endl;
  this->init();
  //Va contenir la deserialisation du fichier contenant la map
  // La serialisation se fera via un fichier a part
}

componentMap::~componentMap()
{

}

void	componentMap::update()
{
  std::cout << "Update de componentMap" << std::endl;
}

void	componentMap::init() {
  
  if ((this->loadTileset(std::move(componentMap::fileTileset))) == false) {
    /* utilisé logforcpp */
    std::cerr << "Error load tileset" << std::endl;
  }
  else {
    this->_Cwindow.clear();
    this->createMap();
    this->generateMap(sf::Vector2u(64, 64));
  }
}

bool componentMap::loadTileset(const std::string &&file) {
  if ((this->m_tileset.loadFromFile(file)) == false)
    return false;
  /* IMPORTANT ############################################################ IMPORTANT @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ IMPORTANT */
  /* C'est ici qu'il permet de savoir quel tileset on utilise, on envoie states a window.draw, il doit y avoir une liaison entre states et le vertexArray, mais OSEF */
  this->states.texture = &(this->m_tileset);
  return true;
}

void  componentMap::createMap() {
  
  this->x_size_map = 7;
  this->y_size_map = 8; /* bien evidement lorsque l'on multiplie les deux nombre(+1 a chaque nombre, psk on commence a compter a 0 sur la map et non à 1) on obtient la taille de la map */
                        // 1   2     3       4      5       6     7       8
  this->arrayMap = { {BRICK, GRASS, BRICK, GRASS, BRICK, GRASS, BRICK, GRASS, //1
		      BRICK, GRASS, BRICK, GRASS, BRICK, GRASS, BRICK, GRASS,// 2
  		      BRICK, GRASS, BRICK, GRASS, BRICK, GRASS, BRICK, GRASS,// 3
  		      BRICK, GRASS, BRICK, GRASS, BRICK, GRASS, BRICK, GRASS,// 4
		      BRICK, GRASS, BRICK, GRASS, BRICK, GRASS, BRICK, GRASS,// 5
      		      BRICK, GRASS, GRASS, BRICK, BRICK, GRASS, BRICK, GRASS,// 6
		      BRICK, GRASS, GRASS, BRICK, BRICK, GRASS, BRICK, GRASS,// 7
		      BRICK, GRASS, GRASS, BRICK, BRICK, GRASS, BRICK, GRASS,// 8
		      BRICK, GRASS, GRASS, BRICK, BRICK, GRASS, BRICK, GRASS   } }; // 9


  /* POSITION DE LHERBE DANS LE TILESET */
  
  quad[0].texCoords = sf::Vector2f(0, 0);
  quad[1].texCoords = sf::Vector2f(32, 0);
  quad[2].texCoords = sf::Vector2f(32, 32);
  quad[3].texCoords = sf::Vector2f(0, 32);
  mapVertex[GRASS] = quad;
  
  /* POSITION DE LA BRIQUE  DANS LE TILESET */
  
  quad[0].texCoords = sf::Vector2f(32, 32);
  quad[1].texCoords = sf::Vector2f(64, 32);
  quad[2].texCoords = sf::Vector2f(64, 64);
  quad[3].texCoords = sf::Vector2f(32, 64);
  mapVertex[BRICK] = quad;
}

void  componentMap::generateMap(const sf::Vector2u &vSizeTile) {
  // SINON AU LIEU DE FAIRE UN X_SIZE_MAP ET UN Y_SIZE_MAP, GO FAIRE UN DOUBLE ARRAY DIRECTEMENT 

  unsigned int	pos_map = 0; /* compteur pour l'indexation de la map */ // USELESS YA MIEU ENFAIT GO DOUBLE ARRAY
  
  for (int y = 0; y <= y_size_map; ++y) { /* LARGEUR */
    for (int x = 0; x <= x_size_map; ++x) { /* LONGUEUR */
      //      quad[0].position = sf::Vector2f(0, 0);
      //      quad[1].position = sf::Vector2f(64, 0);
      //      quad[2].position = sf::Vector2f(64, 64);
      //      quad[3].position = sf::Vector2f(0, 64);

      /* POUR TROUVER LES FORMULES, j'ai d'abord essayer les valeurs en dur pour tatonner le terrain, comme afficher ci-dessus et dessous et puis j'ai poser
       * sur papier pour voir les liaision, c'est a partir de la que j'ai trouver les formules */
      
      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML*/
      quad[0].position = sf::Vector2f((vSizeTile.x * x),
				      (vSizeTile.y * y));


      std::cout << "COORDONNEE 1"
		<< " X : "
		<< vSizeTile.x * x
		<< " Y : "
		<< vSizeTile.y * y
		<< std::endl;;

      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML */
      quad[1].position = sf::Vector2f(vSizeTile.x + (vSizeTile.x * x),
				      (vSizeTile.y * y));


      std::cout << "COORDONNEE 2"
		<< " X : "
		<< vSizeTile.x + (vSizeTile.x * x)
		<< " Y : "
		<< vSizeTile.y * y
		<< std::endl;;

      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML */
      quad[2].position = sf::Vector2f(vSizeTile.x + (vSizeTile.x * x),
				      vSizeTile.y + (vSizeTile.y * y));

      std::cout << "COORDONNEE 3"
		<< " X : "
		<< vSizeTile.x + (vSizeTile.x * x)
		<< " Y : "
		<< vSizeTile.y + (vSizeTile.y * y)
		<< std::endl;;


      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML */
      quad[3].position = sf::Vector2f((vSizeTile.x * x),
				      (vSizeTile.y * (y + 1)));


      std::cout << "COORDONNEE 4"
		<< " X : "
		<< (vSizeTile.x * x)
		<< " Y : "
		<< (vSizeTile.y * (y + 1))
		<< std::endl;

      /* POSITION LE VERTEX SUR LE TILSET ET ACCEDE DIRECTEMENT AU SPRITE VOULUE, grace a this->arrayMap[pos_map] (oublie pas qu'un enum c'est aussi un int, exepter pour les enum class ou la faut static_cast mais ca c'est autre chose*/
      
      quad[0].texCoords = mapVertex[this->arrayMap[pos_map]][0].texCoords;
      quad[1].texCoords = mapVertex[this->arrayMap[pos_map]][1].texCoords;
      quad[2].texCoords = mapVertex[this->arrayMap[pos_map]][2].texCoords;
      quad[3].texCoords = mapVertex[this->arrayMap[pos_map]][3].texCoords;

      if (++pos_map > this->arrayMap.size()) {
	break;
      }

      //      quad[0].texCoords = sf::Vector2f(0, 0);
      //      quad[1].texCoords = sf::Vector2f(32, 0);
      //      quad[2].texCoords = sf::Vector2f(32, 32);
      //      quad[3].texCoords = sf::Vector2f(0, 32);

      /* Draw chaque vertexArray */
      _Cwindow.draw(quad, states);
      std::cout << std::endl;
    }
    std::cout << "NEW Y" << std::endl;
  }

  //  quad[0].position = sf::Vector2f(64, 0);
  //  quad[1].position = sf::Vector2f(128, 0);
  //  quad[2].position = sf::Vector2f(128, 64);
  //  quad[3].position = sf::Vector2f(64, 64);


  //  quad[0].texCoords = mapVertex[BRICK][0].texCoords;
  //  quad[1].texCoords = mapVertex[BRICK][1].texCoords;
  //  quad[2].texCoords = mapVertex[BRICK][2].texCoords;
  //  quad[3].texCoords = mapVertex[BRICK][3].texCoords;
}



/*
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if (this->isContainsMySprites(sf::Mouse::getPosition(this->_Cwindow).x, sf::Mouse::getPosition(this->_Cwindow).y)) {
      }
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    std::cout << "Left" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    std::cout << "Right" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    std::cout << "Up" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    std::cout << "Down" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    std::cout << "Quit" << std::endl;
    this->_Cwindow.close();
  }*/
