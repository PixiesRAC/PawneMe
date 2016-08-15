#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */


int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();
  
  /* Les initialisation se feront dans le build */
  auto	map = factoryComponent->buildComponent<componentMap>();
  auto	map2 = factoryComponent->buildComponent<componentMap>();
  auto	son = factoryComponent->buildComponent<componentSound>();
  auto	son2 = factoryComponent->buildComponent<componentSound>();

  
  CpnmtMSystem->fillVectorComponent(map);
  CpnmtMSystem->fillVectorComponent(map2);
  CpnmtMSystem->fillVectorComponent(son);
  CpnmtMSystem->fillVectorComponent(son2);
  CpnmtMSystem->fillVectorComponent(son);
  CpnmtMSystem->fillVectorComponent(son2);
  CpnmtMSystem->fillVectorComponent(son);


  CpnmtMSystem->updateComponent();

  /* Voir quand delete les composants */
  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager();
  return (0);
}
