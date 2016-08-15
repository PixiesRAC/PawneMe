#include "./include/engine/engine_component_manager_system.hpp"
#include "./include/engine/engine_factory_component.hpp"

#include <typeinfo> /* test */


int					main()
{
  engineComponentManagerSystem		*CpnmtMSystem = engineComponentManagerSystem::createManager();
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();
  
  /*auto	menuStart = */
  factoryComponent->buildComponent<componentMenu>();
  auto	sonStart = factoryComponent->buildComponent<componentSound>();
  

  

  CpnmtMSystem->fillVectorComponent(sonStart);

  /* les updates se feront une fois qu'on aura choisis un mode dans le menu principal (A VOIR PAS SUR)*/
  
  CpnmtMSystem->updateComponent(t_Entity::ALL, t_stateComponent::INIT);

  /* Voir quand delete les composants */
  engineFactoryComponent::kill();
  engineComponentManagerSystem::killManager();
  return (0);
}
