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
	window.draw(this->Sprite_list_[this->Map_[x][y]]);
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
  int		x = 0;
  std::string	str;

  std::ifstream myReadFile;
  myReadFile.open(file);

  if (myReadFile.is_open()) {
    while (!myReadFile.eof()) {
      
      
      myReadFile >> str;
      if (!this->Texture_list_[x].loadFromFile(str)) {
	std::cout << "SFML : Texture.loadFromFile failed" << std::endl;
	return -1;
      }
	
      if (!this->Image_list_[x].loadFromFile(str)) {
	std::cout << "SFML : Image.loadFromFile failed" << std::endl;
	return -1;
      }

      this->Sprite_list_[x].setTexture(this->Texture_list_[x]);
      
      std::cout << str << std::endl;

      x++;
    }
  }

  myReadFile.close();
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

  this->loadTexture("Texture_list");

  this->getMap();


  sf::Texture t;
  sf::Sprite s;
  
  t.loadFromFile("./texture/texture1.jpg");
  s.setTexture(t);
  
    

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

      if (this->getKeyboard() == -1)
	return -1;


      

      window.clear();
      this->drawMap(window, this->Map_);
      //window.draw(this->Sprite_list_[0]);


      window.display();
    }

  return 1;
}
