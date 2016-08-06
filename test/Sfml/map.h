#ifndef		MAP_H_
# define	MAP_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>
#include <fstream>
#include <array>
#include <map>

#define LARGEUR_WINDOW 800
#define HAUTEUR_WINDOW 600

#define LARGEUR_TILE 5
#define HAUTEUR_TILE 5

class Map
{
 private:    
  int				Map_[LARGEUR_TILE][HAUTEUR_TILE];
   sf::Event			Event_;

  std::map<int, sf::Texture>	Texture_list_;
  std::map<int, sf::Sprite>	Sprite_list_;
  std::map<int, sf::Image>	Image_list_;
 
 public:
  Map(std::string const & tileCharge);
  ~Map();

  int		run();
  int		loadTexture(std::string file);
  int		loadNewMapFromTab(int map[LARGEUR_TILE][HAUTEUR_TILE]);
  int		loadMapFromFile(std::string const &);
  void		getMap();
  void		drawMap(sf::RenderWindow & window, int map[LARGEUR_TILE][HAUTEUR_TILE]);
  int		getKeyboard();
};

#endif		/* MAP_H_ */ 
