#include <algorithm>
#include <typeinfo> /* for typeid */
#include "../../include/engine/engine_component_manager_system.hpp"
#include "../../include/component/componentSound.hpp"

void        engineComponentManagerSystem::fillVectorComponent(engineComponent* cpnmt)
{
    this->_vComponent.push_back(cpnmt);
}

void        engineComponentManagerSystem::updateComponent(t_Entity type)
{
  std::for_each(_vComponent.begin(), _vComponent.end(), [type](engineComponent *elem){  /* LAMBDA */
      
      /* Utilisé un thread pour chaque type d'update, Si il y a plusieur type similaire les mettre dans une queue et attendre la fin du thread (idle) du type voulu */
      if (type == t_Entity::ALL)
	{
	  elem->update();
	  /* UPDATE ALL */
	}
      if (elem->getTypeEntity() == type) {
	elem->update();
      }
    });
}

engineComponentManagerSystem	*engineComponentManagerSystem::_IsManagerCreate = nullptr;
