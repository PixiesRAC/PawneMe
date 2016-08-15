#ifndef ENGINE_COMPONENT_HPP_
# define ENGINE_COMPONENT_HPP_ 

#include "./engine_entity.hpp"

/** 
 * \class engineComponent
 * \brief Class contenant divers methodes/fonctions membre
 *        et attributs ayant pour utilité de pouvoir connaitre
 *	  l'entity utilisé et de definir un patron pour les components
 *	  un composant c'est juste une data correspondant a une entity
 * \author pixies
 */

#include <iostream>
class   engineComponent /* class absraite */
{
public :
  
  virtual ~engineComponent() {
    std::cout << "Destruction de engineComponent" << std::endl;
    printf("%p\n", this);
  }

  /**
   * \fn update() methode update permettant d'updaté les composant
   *     associé à une entité
   */
  virtual void update() = 0;

    /**
   * \fn init() methode qui initialise les composants
   *     associé à une entité
   */
  virtual void	init() = 0;
  
  /**
   * \fn getTypeEntity fonction membre const renvoyant le type d'entité
   *     
   */

  t_Entity getTypeEntity() const;
  
  /**
   * \fn setTypeEntity fonction membre initialisant le type d'entité
   * \param type enum de l'entité
   * \return return l'entity correspondant

   */
  void  setTypeEntity(const t_Entity type);

protected :
  t_Entity _type;
};

#endif /* !ENGINE_COMPONENT_HPP_*/
