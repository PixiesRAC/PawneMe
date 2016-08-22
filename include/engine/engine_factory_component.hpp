#ifndef ENGINE_FACTORY_COMPONENT_HPP_
# define ENGINE_FACTORY_COMPONENT_HPP_

#include <memory>
#include <iostream> /* mettre les instruction dans un .cpp */
#include "../component/componentMenuMain.hpp"
#include "../component/componentSound.hpp"
#include "../component/componentMap.hpp"

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
  T * buildComponentNm();

    /* specialisation de template pour le composant menu */
  template <>
  componentMenuMain *buildComponentNm<componentMenuMain>();
    
  /* specialisation de template pour le composant son */
  template <>
  componentSound *buildComponentNm<componentSound>();

    /* specialisation de template pour le composant map */
  template <>
  componentMap *buildComponentNm<componentMap>();
  
      /* specialisation de template pour le composant window */
  template <>
  componentWindow *buildComponentNm<componentWindow>();

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
  T*  buildComponent() const
  {
    return (nmBuildComponent::buildComponentNm<T>()); /* appel du namespace */
  }
private :

  static engineFactoryComponent       *IsInstanciate;

};

# endif /* !ENGINE_FACTORY_COMPONENT_HPP_*/
