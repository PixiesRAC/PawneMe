#ifndef COMPONENTMAP_HPP_
# define COMPONENTMAP_HPP_

#include "../component/componentWindow.hpp"
#include "../engine/engine_component.hpp"


/** 
 * \enum t_decor
 * \brief ENUM CORRESPONDANT AU TYPE DE SPRITE
 * \author pixies
 */

typedef enum    /*class*/       e_decor
  {
    GRASS,
    BRICK

  }                       t_decor;


/** 
 * \class componentMap
 * \brief Class component de la map
 * \author pixies
 */

class   componentMap : public engineComponent
{
public :
  /* les default surement a modifier */
  componentMap();
  ~componentMap();
  componentMap(componentMap&) = default;
  componentMap& operator=(componentMap&) = default;

  virtual void update() override final;

  virtual void init() override final;

private :

  /** 
 * \fn loadTileset
 * \brief fonction qui permet de load le tileset
 * \author pixies
 */
  
  bool loadTileset(const std::string &&file);
  
  
  /** 
 * \fn createMap
 * \brief fonction qui init le std::array et le std::map
 * \param const std::string && file correspond au fichier de la map
 * \author pixies
 */
  
  void  createMap();

    
  /** 
 * \fn generateMap
 * \brief fonction qui contient la boucle qui genere la map
 * \param const sf::Vector2u& correspond à la taille en x et y d'un sprite
 * \author pixies
 */

  void  generateMap(const sf::Vector2u&);

    /* taille de la map global (nombre de sprite), surement a changer, a voir avec js comment on va gerer les map */
  
  static constexpr  int  sizeMap = 24;

  static /* constexpr*/  const std::string fileTileset;
  /* taille de la map en x (nombre de sprite) */
  int   x_size_map;

  /* taille de la map en y (nombre de sprite) */
  int   y_size_map;

  /* texture du tileset */

  sf::Texture m_tileset;

  /* class qui permet de faire un window.draw cf sfml, j'ai pas chercher en profondeur */
  sf::RenderStates states;

  /* class qui contiendra le sprites a afficher */

  sf::VertexArray quad;

  /* Tableau qui contiendra la map */

  std::array<t_decor, sizeMap> arrayMap;

  /* map qui contient un enum correspondant au decor (sprites), et qui associera une position du tileset a l'enum correspondant */

  std::map<t_decor, sf::VertexArray> mapVertex;

public :
  
  /* Get window from componentWindow STATIC */
  
  sf::RenderWindow&		_Cwindow;
};

#endif /* !COMPONENTMAP_HPP_ */
