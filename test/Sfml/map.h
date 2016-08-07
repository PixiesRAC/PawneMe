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
#define SIZE_TILE 500

//!
//! Classe SFML dedie a l'affichage du jeu
//!


class Map
{
 private:    
  int				Map_[LARGEUR_TILE][HAUTEUR_TILE];
   sf::Event			Event_;

  std::map<int, sf::Texture>	Texture_list_;
  std::map<int, sf::Sprite>	Sprite_list_;
  std::map<int, sf::Image>	Image_list_;

  std::map<int, sf::VertexArray>	Vertex_list_;
  


  bool                          First_draw_ = true;
 
 public:
  Map(std::string const & tileCharge);
  ~Map();

  
  /**
   * Mise en marche de la boucle principale (Fenetre, Affichage, etc.)
   */
  int		run();

  /**
   * Chargement de tout les fichiers de textures a partir d' un fichier lu contenant le path de tout ces fichiers
   */
  int		loadTexture(std::string file);

  /**
   * Sers a set notre Map (A remplacer : tableau d'int -> double vector ?)
   */
  int		loadNewMapFromTab(int map[LARGEUR_TILE][HAUTEUR_TILE]);

  /**
   * Chargement de la map a partir d'un fichier (A mettre en relation avec la serialisation dans le futur)
   */
     
  int		loadMapFromFile(std::string const &);

  /**
   * Obtenir un affichage graphique de la map
   */
  void		getMap();

  /**
   * Affichage de la Map dans la fenetre
   */
  void		drawMap(sf::RenderWindow & window, int map[LARGEUR_TILE][HAUTEUR_TILE]);

  /**
   * Recuperation des events du clavier
   */ 
  int		getKeyboard();
};

#endif		/* MAP_H_ */ 
