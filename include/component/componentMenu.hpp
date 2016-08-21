#ifndef COMPONENTMENU_HPP_
# define COMPONENTMENU_HPP_

#include "../engine/engine_component.hpp"
#include "../component/componentWindow.hpp"

/* Obliger de le faire sois meme ... fucking sfml */

/** 
 * \enum e_infoSprite
 * \brief enum contenant le type de sprite (Utile pour savoir si le jouer choisis de jouer ou de load ou de quitter ou n'importe quoi)
 * \author pixies
 */

typedef enum class e_infoSprite {
  USELESS,
    PLAY,
    STOP

    }		t_infoSprite;


/** 
 * \struct e_RectCoorSprite
 * \brief struct recode de sf::Rect pour les int (à refaire vite fait avec les templates) de la sfml avec une information suplementaire sur le sprites en question 
 * \author pixies
 */

typedef struct	s_RectCoorSprite {
  int		rectLeft; /* Left coordinate of the rectangle */
  int		rectTop; /* Top coordinate of the rectangle */
  int		rectWidth; /* Width of the rectangle */
  int		rectHeight; /* Height of the rectangle */
  t_infoSprite	who; /* Valeur du sprite */
}		e_RectCoorSprite;

/** 
 * \class t_InfSprite
 * \brief struct  Permet d'avoir une information suplementaire par rapport au sprite mit
 * \author pixies
 */

typedef struct	s_InfSprite
{
  sf::Sprite	sprite;
  t_infoSprite	who;
}		t_InfSprite;

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

  /** 
 * \fn createSprites
 * \brief Crée les sprites et les push dans le vector de sprites
 * \author pixies
 */

  void		createSprites();

  
  /** 
 * \fn fillRect
 * \brief Remplie le vecteur de structure e_RectCoorSprite avec tout les sprites ajouté
 * \author pixies
 */

  void		fillRect();

  /** 
 * \fn drawSprites
 * \brief affiche les sprites du vecteur
 * \author pixies
 */
  
  void		drawSprites();


  /** 
 * \fn keyboardMouseMenu
 * \brief event clavier ou souris
 * \author pixies
 */
  
  void		keyboardMouseMenu();

  /** 
 * \fn isContainMySprites
 * \brief Fait une rectangulation des coordonée fournis avec les coordoné situé dans le vector de e_RectCoorSprite (recode de la fonction contain de la sfml)
 * \param int x coordonnée X pointé par la souris int y coordonnéé y pointé par la souris
 * \return true si un poin a été trouver, false sinon
 * \author pixies
 */

  bool		isContainsMySprites(int x , int y);

  /* Get window from componentWindow STATIC */
  
  sf::RenderWindow&		_Cwindow;

  /* Event */
  
  sf::Event			_event;

  /* vector de sprite */
  std::vector<t_InfSprite>	_sprites;

  /* vector de rectangle de sprite */
  std::vector<e_RectCoorSprite>	_vCoorSprites;
  
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

#endif /* !COMPONENTMENU_HPP */
