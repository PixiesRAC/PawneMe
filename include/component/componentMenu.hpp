#ifndef COMPONENTMENU_HPP_
# define COMPONENTMENU_HPP_

#include "../engine/engine_component.hpp"
#include "../component/componentWindow.hpp"


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

  virtual void init(); /* A reflechir pour la signature */
  
private :

  void		createSprites();
  void		drawSprites();
  void		keyboardMouseMenu();
  bool		isContainsMySprites(int, int);

  /* Get window from componentWindow STATIC */
  
  sf::RenderWindow&	_Cwindow;

  /* Event */
  
  sf::Event			_event;

  std::vector<sf::Sprite>	_sprites;
  
  sf::Texture			_textureMenu;
  sf::Sprite			_spriteMenu;

  /* A voir si on garde cette methode pour les texture */

  /* Necessaire pour avoir la transparence PUTIN DE SFML*/
  
  sf::Image			_imgButtonPlay;

  /* http://www.sfml-dev.org/tutorials/2.4/graphics-sprite-fr.php le moin de texture possible A VOIR */
  /* http://www.sfml-dev.org/documentation/2.4.0-fr/classsf_1_1Texture.php */
  sf::Texture			_textureButtonPlay;
  sf::Sprite			_spriteButtonPlay;

  sf::IntRect			_buttonArea;

  /* Le button prendra 15% de la taille de l'ecran */
  
  static constexpr float _PourcentageButton = 85.0;
  
  /* INFO/SIZE DU MENU */
  
  static constexpr const auto& _fileTextureMenu = "./texture/menuStart/Hacker-silhouette.jpg";
  static constexpr float _LwindowsMenu = 1000.0;
  static constexpr float _HwindowsMenu = 664.0;

  /* INFO/SIZE DES BOUTONS DU MENU */

  static constexpr const auto& _fileTextureMenuPlay = "./texture/menuStart/playMenu.png";
  static constexpr float _LwindowsMenuPlay = 67.0;
  static constexpr float _HwindowsMenuPlay = 43.0;
  
};

#endif /* !COMPONENTMENU_HPP */
