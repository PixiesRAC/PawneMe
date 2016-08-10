#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */


int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  /* Les initialisation se feront dans le build */
  auto	map = factoryComponent->buildComponent<componentMap>();

  CpnmtMSystem->fillVectorComponent(map);

  CpnmtMSystem->updateComponent(t_Entity::MAP);


  delete map;
  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager();
  return (0);
}
