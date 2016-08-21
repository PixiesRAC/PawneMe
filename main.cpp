#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */


int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  auto	window = factoryComponent->buildComponent<componentWindow>();
  auto	menuStart = factoryComponent->buildComponent<componentMenu>();
  auto	menuSound = factoryComponent->buildComponent<componentSound>();
  


  CpnmtMSystem->fillVectorComponent(window);
  CpnmtMSystem->fillVectorComponent(menuSound);
  CpnmtMSystem->fillVectorComponent(menuStart);

  /* soit on thread l'init ou l'update, l'update sera dans la boucle de jeux */  
  CpnmtMSystem->updateComponent(t_Entity::ALL, t_stateComponent::INIT); /* INIT */

  /* boucle de jeux */
  while(1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  /* Voir quand delete les composants */
  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager();
  return (0);
}
