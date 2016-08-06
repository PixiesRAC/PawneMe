#include "map.h"

Map::Map(std::string const & tileCharge) {
}

Map::~Map() {
}

//LOAD DE LA MAP (DOUBLE TABLEAU D'INT)
int		Map::loadNewMapFromTab(int	map[LARGEUR_TILE][HAUTEUR_TILE]) {
  int		x = 0;
  int		y = 0;

  while(x != HAUTEUR_TILE) {
    while (y != LARGEUR_TILE) {
      this->Map_[x][y] = map[x][y]; 
      y++;
    }
    y = 0;
    x++;
  }
  return 1;
}

//OBTENIR UN AFFICHAGE VISUEL DE LA MAP
void		Map::getMap() {
  int		x = 0;
  int		y = 0;

    while(x != HAUTEUR_TILE) {
    while (y != LARGEUR_TILE) {
      std::cout << this->Map_[x][y] << " ";
      y++;
    }
    std::cout << std::endl;
    y = 0;
    x++;
  }
}

//PARCOURS DE LA MAP ET UPDATE DES SPRITES
void		Map::drawMap(sf::RenderWindow & window, int NewMap[LARGEUR_TILE][HAUTEUR_TILE]) {
  int		x = 0;
  int		y = 0;

    while(x != HAUTEUR_TILE) {
    while (y != LARGEUR_TILE) {
      //LA ON CHECK SI LA VALEUR EST TOUJOURS LA MEME A LA POSTION ACTUEL
      if (this->Map_[x][y] != NewMap[x][y]) {
	//SI C'EST DIFFERENT ON ACTUALISE AVEC LE NOUVEAU SPRITE
      }
      y++;
    }
    y = 0;
    x++;
  }
}

//ICI ON VA READ UN FICHIER AVEC LE NOM DE TOUTES FICHIER A LOAD
int		Map::loadTexture(std::string file) {
  std::string	tileCharge;
  int		x;
  std::string	str;

  std::ifstream myReadFile;
  myReadFile.open(file);

  if (myReadFile.is_open()) {
    while (!myReadFile.eof()) {
      
      
      myReadFile >> str;
      this->Texture_list_[x].loadFromFile(str);


      std::cout << str << std::endl;

      x++;
    }
  }

  myReadFile.close();

  /*if(m_imageTile.loadFromFile(tileCharge)){
    m_textureTile.loadFromImage(m_imageTile);
    m_spriteTile.setTexture(m_textureTile);
    }  
    else {
    std::cout << "Erreur chargement tuiles";
    return -1;
    }*/
  return 1;
}

int		Map::getKeyboard() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    std::cout << "Left" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    std::cout << "Right" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    std::cout << "Up" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    std::cout << "Down" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    std::cout << "Quit" << std::endl;
    return -1;
  }
  return 1;
}

int		Map::run() {
  
  sf::RenderWindow window(sf::VideoMode(LARGEUR_WINDOW, HAUTEUR_WINDOW), "PAWNME WSH C CMT LA FAMILLE ?");

  Map map1("texture1.jpg");

  int           Map[LARGEUR_TILE][HAUTEUR_TILE] = {0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0,
                                                   0, 0, 0, 1, 0,
                                                   0, 0, 0, 1, 0,
                                                   1, 1, 1, 1, 1,};
  
  this->loadTexture("Texture_list");

  map1.loadNewMapFromTab(Map);
  map1.getMap();

  while(window.isOpen())
    {
      while(window.pollEvent(this->Event_))
        {
          if (this->Event_.type == sf::Event::Closed) {
	    std::cout << "Closing Window" << std::endl;
            window.close();
            return 1;
          }
        }

      if (map1.getKeyboard() == -1)
	return -1;

      window.clear();
      //map1.drawMap(window, Map);
      window.display();
    }

  return 1;
}
