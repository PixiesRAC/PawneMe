#ifndef ENGINE_COMPONENT_MANAGER_SYSTEM_HPP_
# define ENGINE_COMPONENT_MANAGER_SYSTEM_HPP_

#include <vector>
#include "./engine_component.hpp"


/** 
 * \class engineComponentManagerSystem
 * \brief Class contenant divers methodes/fonctions membre
 *        et attributs ayant pour utilité de pouvoir utilisé
 *	  les methodes/fonction membres des components tel que l'update
 * \author pixies
 */

class   engineComponentManagerSystem /* class qui va gerer les entité et call les fonction necessaires Faire un singleton*/
{
public :

  /**
   * \fn fillVectorComponent methode permettant de remplir un vector de
   *	components
   *  \param cpnmt pointeur sur un components pour l'ajouter au vector	
   */
  void        fillVectorComponent(engineComponent* cpnmt);
  
  /**
   * \fn updateComponent methode permettant d'update un type ou 
   *	tout les components
   *  \param type enum de l'entity voulant etre update
   */
  void        updateComponent(t_Entity type);
  
private :
  std::vector<engineComponent*>     _vComponent; /* Liste de  composant */
};

#endif /* !ENGINE_COMPONENT_MANAGER_SYSTEM_HPP_*/
