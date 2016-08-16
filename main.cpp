#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */


int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();
  
  auto	menuStart = factoryComponent->buildComponent<componentMenu>();
  auto	sonStart = factoryComponent->buildComponent<componentSound>();
  auto	map = factoryComponent->buildComponent<componentMap>();
  


  CpnmtMSystem->fillVectorComponent(sonStart);
  CpnmtMSystem->fillVectorComponent(menuStart);
  CpnmtMSystem->fillVectorComponent(map);

  /* soit on thread l'init ou l'update, l'update sera dans la boucle de jeux */  
  CpnmtMSystem->updateComponent(t_Entity::ALL, t_stateComponent::INIT);
  CpnmtMSystem->updateComponent();

  /* Voir quand delete les composants */
  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager();
  return (0);
}
