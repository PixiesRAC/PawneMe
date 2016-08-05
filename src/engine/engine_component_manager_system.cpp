#include <iostream>
#include <algorithm>
#include "../../include/engine/engine_component_manager_system.hpp"

void        engineComponentManagerSystem::fillVectorComponent(engineComponent* cpnmt)
{
  this->_vComponent.push_back(cpnmt);
  std::cout << this->_vComponent.size() << std::endl;
}


void        engineComponentManagerSystem::updateComponent(t_Entity type)
{
  std::for_each(_vComponent.begin(), _vComponent.end(), [type](engineComponent *elem){  /* LAMBDA */
      if (type == t_Entity::ALL)
	{
	  std::cout << "Loop sur tout les entity" << std::endl;
	}
      else if (elem->getTypeEntity() == type) {
	std::cout << static_cast<int>(elem->getTypeEntity()) << std::endl;
      }
    });
}