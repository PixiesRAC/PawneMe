#ifndef COMPONENTMENU_HPP_
# define COMPONENTMENU_HPP_

#include "../engine/engine_component.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/** 
 * \class componentMenu
 * \brief Class component du menu
 * \author pixies
 */

class   componentMenu : public engineComponent
{
public :
  /* les default surement a modifier */
  componentMenu();
  ~componentMenu() = default;
  componentMenu(componentMenu&) = default;
  componentMenu& operator=(componentMenu&) = default;

  virtual void update();

  virtual void		init(); /* A reflechir pour la signature */
  
private :
  
  void		keyboardMenu();
  
  /* Faire vector de sprite */
  
  sf::RenderWindow	_window;
  sf::Event		_event;
  
  sf::Texture		_texture[2];
  sf::Sprite		_sprite[2];
  
  sf::Image		_img;

  static constexpr auto	_fileTextureMenu = "./texture/menuStart/Hacker-silhouette.jpg";
  static constexpr float _Lwindows = 1000.0;
  static constexpr float _Hwindows = 664.0;
};

#endif /* !COMPONENTMENU_HPP */
