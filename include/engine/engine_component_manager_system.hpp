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

class   engineComponentManagerSystem /* class qui va gerer les entité et call les fonction necessaires SINGLETON*/
{
  engineComponentManagerSystem() = default;
  engineComponentManagerSystem(engineComponentManagerSystem&) = delete;
  ~engineComponentManagerSystem() = default;
  engineComponentManagerSystem& operator=(engineComponentManagerSystem&) = delete;
  
public :

    
  /**
   * \fn createManager fonction static permettant d'instancier la classe 
   * engineComponentManagerSystem
   */
  
  static engineComponentManagerSystem*		createManager()
  {
    if (_IsManagerCreate == nullptr)
      _IsManagerCreate = new engineComponentManagerSystem;
    return (_IsManagerCreate);
  }

    /**
     * \fn killManager fonction static permettant de delete l'instance de  la classe engineComponentManagerSystem
   */

    static void	killManager()
  {
    if (_IsManagerCreate != nullptr) {
      delete(_IsManagerCreate);
      _IsManagerCreate = nullptr;
    }
  }

    static engineComponentManagerSystem	*_IsManagerCreate;
  
  /**
   * \fn fillVectorComponent methode permettant de remplir un vector de
   *	components
   *  \param cpnmt pointeur sur un components pour l'ajouter au vector	
   */
  void        fillVectorComponent(engineComponent* cpnmt);
  
  /**
   * \fn updateComponent methode permettant d'update un type ou 
   *	tout les components
   *  \param type enum de l'entity voulant etre update, Utile car
   * on ne voudra pas toujours vouloir update tout les composants, mais
   * par exemple juste le son ou juste un personnage en fonction de 
   * l'evenement recus !
   */
  void        updateComponent(t_Entity type = t_Entity::ALL);
  
private :
  std::vector<engineComponent*>     _vComponent; /* Liste de  composant */
};

#endif /* !ENGINE_COMPONENT_MANAGER_SYSTEM_HPP_*/
