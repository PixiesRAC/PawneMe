#ifndef ENGINE_FACTORY_COMPONENT_HPP_
# define ENGINE_FACTORY_COMPONENT_HPP_

#include <iostream> /* mettre les instruction dans un .cpp */
#include "./engine_component.hpp"
#include "../component/componentSound.hpp"
#include "../component/componentMap.hpp"
#include "../component/componentMenu.hpp"
#include "../component/componentWindow.hpp"

/** 
 * \namespace nmBuildComponent
 * \brief namespace contenant les specialisation de templates pour chaque entity (Il y en aura beaucoup)
 * \author pixies
 */

/* WARNING mettre tout les templates dans un .cpp ???? WARNING */

namespace nmBuildComponent /* Necessite un namespace pour pouvoir templater et specialiser ses functions  ref => http://stackoverflow.com/questions/3052579/explicit-specialization-in-non-namespace-scope*/
{

  /**
   * \fn  buildComponentNm() fonction membre template pour crée 
   *	un component (specialisation de template pour chaque entity)
   * \return return le component instancié
   */
  template <typename T>
  T * buildComponentNm()
  {
    T *entite = new T;
    entite->setTypeEntity(t_Entity::OTHER);
    std::cout << "New component banale : " << std::endl;
    /* GO INIT */
    return (entite);
  }

    /* specialisation de template pour le composant menu */
  template <>
  componentMenu *buildComponentNm<componentMenu>()
  {
    componentMenu *entite = new componentMenu;
    entite->setTypeEntity(t_Entity::SON);
    std::cout << "New component de Menu : " << std::endl;
    /* GO INIT */
    return (entite);
  }
  
  /* specialisation de template pour le composant son */
  template <>
  componentSound *buildComponentNm<componentSound>()
  {
    componentSound *entite = new componentSound;
    entite->setTypeEntity(t_Entity::SON);
    std::cout << "New component de SON : " << std::endl;
    /* GO INIT */
    return (entite);
  }

    /* specialisation de template pour le composant map */
  template <>
  componentMap *buildComponentNm<componentMap>()
  {
    componentMap *entite = new componentMap;
    entite->setTypeEntity(t_Entity::MAP);
    std::cout << "New component de MAP : " << std::endl;
    /* GO INIT */
    return (entite);
  }

      /* specialisation de template pour le composant window */
  template <>
  componentWindow *buildComponentNm<componentWindow>()
  {
    componentWindow *entite = new componentWindow;
    entite->setTypeEntity(t_Entity::WINDOW);
    std::cout << "New component de Window : " << std::endl;
    /* GO INIT */
    return (entite);
  }
};

/** 
 * \class engineFactoryComponent (SINGLETON)
 * \brief Class instancie les components
 * \author pixies
 */

class   engineFactoryComponent
{
  engineFactoryComponent() = default;
  ~engineFactoryComponent() = default;
  engineFactoryComponent(const engineFactoryComponent &) = delete;
  engineFactoryComponent& operator=(const engineFactoryComponent&) = delete;

public :

  /**
   * \fn createFactory fonction membre instanciant le singleton engineFactoryComponent
   *
   */
  static engineFactoryComponent       *createFactory() {

    if (IsInstanciate == nullptr) {
      /* MODIF TEST LE NEW ! */
      IsInstanciate = new engineFactoryComponent;
      std::cout << "Create factory" << std::endl;
    }
    else
      std::cout << "factory already create" << std::endl;
    return (IsInstanciate);
  };

  /**
   * \fn createFactory fonction membre delete le singleton engineFactoryComponent
   *
   */
  static void           kill()
  {
    if (IsInstanciate != nullptr) {
      delete IsInstanciate;
      IsInstanciate = nullptr;
    }
  }

  /**
   * \fn buildComponent fonction membre template instanciant le composant    * \return return le component instancié 
   *
   */
  template <typename T>
  T *  buildComponent() const
  {
    return (nmBuildComponent::buildComponentNm<T>()); /* appel du namespace */
  }
private :

  static engineFactoryComponent       *IsInstanciate;

};

engineFactoryComponent *engineFactoryComponent::IsInstanciate = nullptr; 

# endif /* !ENGINE_FACTORY_COMPONENT_HPP_*/
