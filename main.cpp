#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */

/* static FACTORY INIT */
engineFactoryComponent *engineFactoryComponent::IsInstanciate = nullptr;
bool			g_menuSelection = false;

int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  auto	window = factoryComponent->buildComponent<componentWindow>();
  auto	mainMenu = factoryComponent->buildComponent<componentMenuMain>();

  window->init();
  mainMenu->init(); /* Init du son dedans via la factory, le delete se fait grace à un unique_ptr */
  
  //  CpnmtMSystem->updateComponent(t_Entity::ALL, t_stateComponent::INIT); /* INIT */

  /* @@@@@@@@ WAIT SELECTION UTILISATEUR @@@@@@@ */
  std::cout << "Waiting player (menu)" << std::endl;
  while (g_menuSelection != true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  
  /* Efface les data/composants du menu pour maintenant crée les data/composant du jeux */
  delete(window);
  delete(mainMenu);
  std::cout << "L'utilisateur vient de choisir PLAY" << std::endl;


  /* boucle de jeux */
  while(1) {
    std::cout << "Boucle de jeux" << std::endl;
    //    CpnmtMSystem->updateComponent(t_Entity::ALL); /* UPDATE */
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  
  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager(); /* stop aussi la threadPool */
  return (0);
}
