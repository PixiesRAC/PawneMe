#ifndef ENGINE_FACTORY_COMPONENT_HPP_
# define ENGINE_FACTORY_COMPONENT_HPP_

#include "./engine_component.hpp"

/** 
 * \namespace nmBuildComponent
 * \brief namespace contenant les specialisation de templates pour chaque entity (Il y en aura beaucoup)
 * \author pixies
 */

namespace nmBuildComponent /* Necessite un namespace pour pouvoir templater et specialiser ses functions  ref => http://stackoverflow.com/questions/3052579/explicit-specialization-in-non-namespace-scope*/
{

  /**
   * \fn  buildComponentNm() fonction membre template pour crée 
   *	un component (specialisation de template pour chaque entity)
   * \return return le component instancié
   */
  template <typename T>
  T * const buildComponentNm()
  {
    T *entite = new T;
    entite->setTypeEntity(t_Entity::OTHER);
    std::cout << "New component banale : " << std::endl;
    /* GO INIT */
    return (entite);
  }

  template <>
  ComponentRAC* const buildComponentNm<ComponentRAC>()
  {
    ComponentRAC *entite = new ComponentRAC;
    entite->setTypeEntity(t_Entity::RAC);
    entite->InitValueSpecificRac(42);
    std::cout << "New component RAC : " << std::endl;
    /* GO INIT */
    return (entite);
  }

  template <>
  Son * const buildComponentNm<Son>()
  {
    Son *entite = new Son;
    entite->setTypeEntity(t_Entity::SON);
    std::cout << "New component de SON : " << std::endl;
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
  factoryComponent() = default;
  ~factoryComponent() = default;
  factoryComponent(const factoryComponent &) = delete;
  factoryComponent& operator=(const factoryComponent&) = delete;

public :

  /**
   * \fn createFactory fonction membre instanciant le singleton engineFactoryComponent
   *
   */
  static factoryComponent       *createFactory() {

    if (IsInstanciate == nullptr) {
      IsInstanciate = new factoryComponent;
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
  T * const buildComponent()
  {
    return (nmBuildComponent::buildComponentNm<T>()); /* appel du namespace */
  }
private :

  static factoryComponent       *IsInstanciate;

};

/* à mettre dans le .cpp */
//factoryComponent *factoryComponent::IsInstanciate = nullptr; 

# endif /* !ENGINE_FACTORY_COMPONENT_HPP_*/
