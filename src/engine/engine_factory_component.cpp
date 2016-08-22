#include "../../include/engine/engine_factory_component.hpp"

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
  componentMenuMain *buildComponentNm<componentMenuMain>()
  {
    componentMenuMain *entite = new componentMenuMain;
    entite->setTypeEntity(t_Entity::MENU);
    std::cout << "New component de menuMain : " << std::endl;
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
