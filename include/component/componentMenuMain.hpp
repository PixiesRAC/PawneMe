#ifndef COMPONENTMENUMAIN_HPP_
# define COMPONENTMENUMAIN_HPP_

#include "./componentMenu.hpp"
#include "../engine/engine_component.hpp"
#include "../bridge/bridgeToMenuSelection.hpp"

/* Obliger de le faire sois meme ... fucking sfml */

/** 
 * \class componentMenuMain
 * \brief Class component du menu
 * \author pixies
 */

class   componentMenuMain : public engineComponent, protected componentMenu
{
public :
  /* les default surement a modifier */
  componentMenuMain();
  virtual ~componentMenuMain() {
    std::cout << "-DESTRUCTEUR de ComponentMenuMain" << std::endl;
    printf("%p\n", this);
  }
  componentMenuMain(componentMenuMain&) = delete;
  componentMenuMain& operator=(componentMenuMain&) = delete;

  virtual void update();

  virtual void init(); /* A reflechir pour la signature */
  
private :

    /** 
   * \fn virtual function createSprites
   * \brief Crée les sprites et les push dans le vector de sprites
   * \author pixies
   */

  virtual void		createSprites();

  
  /** 
 * \fn virtual function fillRect
 * \brief Remplie le vecteur de structure e_RectCoorSprite avec tout les sprites ajouté
 * \author pixies
 */

virtual   void		fillRect();

  /** 
 * \fn virtual function drawSprites
 * \brief affiche les sprites du vecteur
 * \author pixies
 */
  
virtual   void		drawSprites();


  /** 
 * \fn virtual function keyboardMouseMenu
 * \brief event clavier ou souris
 * \author pixies
 */
  
virtual  void		keyboardMouseMenu();
  
  /** 
 * \fn virtual function isContainMySprites
 * \brief Fait une rectangulation des coordonée fournis avec les coordoné situé dans le vector de e_RectCoorSprite (recode de la fonction contain de la sfml)
 * \param int x coordonnée X pointé par la souris int y coordonnéé y pointé par la souris
 * \return true si un poin a été trouver, false sinon
 * \author pixies
 */

virtual  bool		isContainsMySprites(int x , int y);



    /* Get window from componentWindow STATIC */
  
  sf::RenderWindow&		_Cwindow;

  sf::Texture			_textureMenu;
  t_InfSprite			_spriteMenu;

  /* A voir si on garde cette methode pour les texture */

  /* Necessaire pour avoir la transparence PUTIN DE SFML*/
  
  sf::Image			_imgButtonPlay;

  /* http://www.sfml-dev.org/tutorials/2.4/graphics-sprite-fr.php le moin de texture possible A VOIR */
  /* http://www.sfml-dev.org/documentation/2.4.0-fr/classsf_1_1Texture.php */
  sf::Texture			_textureButtonPlay;
  t_InfSprite			_spriteButtonPlay;

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

#endif /* !COMPONENTMENUMAIN_HPP */
