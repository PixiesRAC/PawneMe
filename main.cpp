#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */

/* static FACTORY INIT 
La factory ne renvoie pas de unique_ptr, elle le devrait ! */
/* Lel enfait la sfml utilise deja ses propre thread donnnc bon */

engineFactoryComponent *engineFactoryComponent::IsInstanciate = nullptr;
bool			g_menuSelection = false;

int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  auto	window = std::unique_ptr<componentWindow>(factoryComponent->buildComponent<componentWindow>());
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

  delete(mainMenu);
  std::cout << "L'utilisateur vient de choisir PLAY" << std::endl;


  /* Creation du jeux */
  window->init(); /* reforme de la fenetre */
  auto	gameMap = std::unique_ptr<componentMap>(factoryComponent->buildComponent<componentMap>());
  /* THACH_B FAIRE UNE FONCTION QUI PREND COMPONENTMAP EN PARAMETRE POUR POUVOIR LUTILISER DANS LA CLASSE, je merge la nouvelle factory plus tard */
  /* surement faire un composant game qui prend un componentMap en param de son init */
  /* boucle de jeux */
  while (gameMap.get()->_Cwindow.isOpen())
    {
      sf::Event event;
      while (gameMap.get()->_Cwindow.pollEvent(event))
	{
	  // évènement "fermeture demandée" : on ferme la fenêtre
	  if (event.type == sf::Event::Closed)
	    gameMap.get()->_Cwindow.close();
	}
      gameMap.get()->_Cwindow.display();
      std::this_thread::sleep_for (std::chrono::seconds(1));
    }

  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager(); /* stop aussi la threadPool */
  return (0);
}
