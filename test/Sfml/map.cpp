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

      if (this->First_draw_ == true) {
        First_draw_ = false;

	std::cout << "SALUT :" << x << " " << y << std::endl;
 
	
	window.draw(this->Sprite_list_[this->Map_[x][y]]);

	
     
      if (this->Map_[x][y] != NewMap[x][y]) {
	//SI C'EST DIFFERENT ON ACTUALISE AVEC LE NOUVEAU SPRITE
	window.draw(this->Sprite_list_[this->Map_[x][y]]);
	
	std::cout << "ON FAIT DU SALE MAMENE :" << x << " " << y << std::endl;
      }
	
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
      if (!this->Texture_list_[x].loadFromFile(str, sf::IntRect(10, 10, 32, 32))) {
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
      //this->drawMap(window, this->Map_);
      //window.draw(this->Sprite_list_[1]);

      sf::VertexArray quad(sf::Quads, 4);

      quad[0].position = sf::Vector2f(10, 10);
      quad[1].position = sf::Vector2f(110, 10);
      quad[2].position = sf::Vector2f(110, 110);
      quad[3].position = sf::Vector2f(10, 110);
      
      quad[0].texCoords = sf::Vector2f(0, 0);
      quad[1].texCoords = sf::Vector2f(50, 0);
      quad[2].texCoords = sf::Vector2f(0, 50);
      quad[3].texCoords = sf::Vector2f(50, 50);
      
      
      sf::RenderStates states;
      states.texture = &this->Texture_list_[0];

		  
      sf::VertexArray quad2(sf::Quads, 4);
      
      quad2[0].position = sf::Vector2f(50, 50);
      quad2[1].position = sf::Vector2f(150, 50);
      quad2[2].position = sf::Vector2f(150, 150);
      quad2[3].position = sf::Vector2f(50, 150);
      
      quad2[0].texCoords = sf::Vector2f(0, 0);
      quad2[1].texCoords = sf::Vector2f(50, 0);
      quad2[2].texCoords = sf::Vector2f(0, 50);
      quad2[3].texCoords = sf::Vector2f(50, 50);
      
      this->Vertex_list_[0] = quad2;

      quad2[0].position = sf::Vector2f(35, 35);
      quad2[1].position = sf::Vector2f(85, 35);
      quad2[2].position = sf::Vector2f(85, 85);
      quad2[3].position = sf::Vector2f(35, 85);

      sf::VertexArray quad3(sf::Quads, 4);
      
      quad3[0].position = sf::Vector2f(85, 85);
      quad3[1].position = sf::Vector2f(135, 85);
      quad3[2].position = sf::Vector2f(135, 135);
      quad3[3].position = sf::Vector2f(85, 135);
      
      quad3[0].texCoords = sf::Vector2f(0, 0);
      quad3[1].texCoords = sf::Vector2f(50, 0);
      quad3[2].texCoords = sf::Vector2f(0, 50);
      quad3[3].texCoords = sf::Vector2f(50, 50);

      window.draw(quad, states);
      window.draw(this->Vertex_list_[0], states);
      window.draw(quad2, states);
      window.draw(quad3, states);
	  

	this->Vertex_list_[0].setPrimitiveType(sf::Quads);
	this->Vertex_list_[0].resize(SIZE_TILE);
	
	int IncrementX = (HAUTEUR_TILE * LARGEUR_TILE) + 10;	
	int IncrementY = (HAUTEUR_TILE * LARGEUR_TILE) + 10;	
		
	int f = 0;

	for (unsigned int i = 0; i < LARGEUR_WINDOW; i = i + 50) {
	  for (unsigned int j = 0; j < HAUTEUR_WINDOW; j = j + 50) {

	    quad[0].position = sf::Vector2f(i  + IncrementX, j + IncrementY);
	    quad[1].position = sf::Vector2f(i + IncrementX + i, j + IncrementY);
	    quad[2].position = sf::Vector2f(i + IncrementX + i , j + IncrementY + j);
	    quad[3].position = sf::Vector2f(i + IncrementX, j + IncrementY + j);
	    
	    quad[0].texCoords = sf::Vector2f(0, 0);
	    quad[1].texCoords = sf::Vector2f(50, 0);
	    quad[2].texCoords = sf::Vector2f(0, 50);
	    quad[3].texCoords = sf::Vector2f(50, 50);
	    
	    this->Vertex_list_[f] = quad;
	    
	    std::cout << "I : " << i << " J : " << j << std::endl; 


	    window.draw(this->Vertex_list_[f], states);
	    
	  }
	  f++;
	  
	  
	  
	  
	  
	}
		







      window.display();
    }
  
  return 1;
}
