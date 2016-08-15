#include <algorithm>
#include <typeinfo> /* for typeid */
#include <memory>
#include "../../include/engine/engine_component_manager_system.hpp"
#include "../../include/component/componentSound.hpp"
#include "../../include/component/componentMap.hpp"

void        engineComponentManagerSystem::fillVectorComponent(engineComponent* cpnmt)
{
    this->_vComponent.push_back(cpnmt);
}

void 	engineComponentManagerSystem::launch_update(engineComponent *elem)
{
  elem->update();
}

void        engineComponentManagerSystem::updateComponent(t_Entity type)
{
  std::for_each(_vComponent.begin(), _vComponent.end(), [this, type](engineComponent *elem){  /* LAMBDA */
      
      /* Utilisé un thread pour chaque type d'update, Si il y a plusieur type similaire les mettre dans une queue et attendre la fin du thread (idle) du type voulu */
      auto fct = std::make_shared<std::function<void()>>(std::bind(&engineComponentManagerSystem::launch_update, this, elem));
      if (type == t_Entity::ALL)
	{
	  this->_ThPool.taskLaunch(*fct.get());
	}
      if (elem->getTypeEntity() == type) {
	this->_ThPool.taskLaunch(*fct.get());
      }
    });
}

    engineComponentManagerSystem	*engineComponentManagerSystem::_IsManagerCreate = nullptr;
