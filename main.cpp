#include "./include/engine/engine_factory_component.hpp"
#include "./include/engine/engine_component_manager_system.hpp"

#include <typeinfo> /* test */

int					main()
{
  engineComponentManagerSystem		CpnmtMSystem;
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  auto	MenuSound = factoryComponent->buildComponent<componentSound>();
  auto	GameSound = factoryComponent->buildComponent<componentSound>();

  std::cout << typeid(MenuSound).name() << std::endl;
  std::cout << typeid(GameSound).name() << std::endl;
  /* INIT, VIA UNE FONCTION NORMALEMENT et surement par le CpnmtMSysteme */
  MenuSound->_specificValue = 42;
  GameSound->_specificValue = 12;
  
  CpnmtMSystem.fillVectorComponent(MenuSound);
  CpnmtMSystem.fillVectorComponent(GameSound);
  //CpnmtMSystem.updateComponent(t_Entity::RAC);
  CpnmtMSystem.updateComponent(t_Entity::SON); /* update juste le son */
  //CpnmtMSystem.updateComponent(); /* update tout */

  delete MenuSound;
  delete GameSound;
  engineFactoryComponent::kill();
  return (0);
}
