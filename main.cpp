#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */

/* static FACTORY INIT */
engineFactoryComponent *engineFactoryComponent::IsInstanciate = nullptr;

/* EN ATTENDANT */
bool	g_menuSelection = false;
bool	g_threadPoolExit = false;

/* test */
void					ItemCheck(void)
{
  while (g_threadPoolExit != true) {
    std::cout << "attente fermture de la threadPool" << std::endl;
  }
  std::cout << "FERMETURE" << std::endl;
}


int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  auto	window = factoryComponent->buildComponent<componentWindow>();
  auto	mainMenu = factoryComponent->buildComponent<componentMenuMain>();
  auto	backgroundSound = factoryComponent->buildComponent<componentSound>();
  


  CpnmtMSystem->fillVectorComponent(window);
  CpnmtMSystem->fillVectorComponent(backgroundSound);
  CpnmtMSystem->fillVectorComponent(mainMenu);

  /* soit on thread l'init et/ou l'update, l'update sera dans la boucle de jeux */
  std::thread	t1(ItemCheck);
  CpnmtMSystem->updateComponent(t_Entity::ALL, t_stateComponent::INIT); /* INIT */

  /* EN ATTENDANT */
  std::cout << "Waiting player (menu)" << std::endl;
  while (g_menuSelection != true) {
  }
  /* Efface les data/composants du menu pour maintenant crée les data/composant du jeux */
  engineComponentManagerSystem::killManager(); /* stop aussi la threadPool */
  std::cout << "CHOISIS" << std::endl;
  /* Changement de music d'ambiance */
  backgroundSound->_soundType = t_SoundType::GAME;

  /* boucle de jeux */
  while(1) {
    //    CpnmtMSystem->updateComponent(t_Entity::ALL); /* UPDATE */
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  /* Voir quand delete les composants */
  /* POUR POUVOIR DELETE TOUT LES OBJET, EN PREMIER LIEU ON ARRETE LA THREAD POOL ET DONC CA STOP TOUT LES THREAD EN ROUTE, PUIS ON RECRÉE UN AUTRE THREAD (ON VERRA OU) QUI LUI VA DELETE LES OBJETS, SI ON FAIT PAS CA ET QUE L'ON DELETE LES OBJET AVANT LA FIN DE LA THREADPOOL CA VA SEGFAULT CAR LE THREAD NE POURRA PLUS ACCERDER A L'OBJET VOULU */
  t1.join();
  engineFactoryComponent::kill();
  return (0);
}
