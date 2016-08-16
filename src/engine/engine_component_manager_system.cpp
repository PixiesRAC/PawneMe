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

void 	engineComponentManagerSystem::launch_component(engineComponent *elem)
{
  std::this_thread::sleep_for(std::chrono::seconds(1));
  if (this->_state == t_stateComponent::UPDATE) {
    std::cout << "voici un update" << std::endl;
    elem->update();
  }
  else if (this->_state == t_stateComponent::INIT) {
    std::cout << "voici un init" << std::endl;
    elem->init();
  }
}

void        engineComponentManagerSystem::updateComponent(t_Entity type, t_stateComponent state)
{
  this->_state = state;
  std::for_each(_vComponent.begin(), _vComponent.end(), [this, type](engineComponent *elem){  /* LAMBDA */

      if (elem != nullptr) {
	auto fct = std::make_shared<std::function<void()>>(std::bind(&engineComponentManagerSystem::launch_component, this, elem));
	if (type == t_Entity::ALL)
	  {
	    if ((this->_ThPool.taskLaunch(*fct.get())) == false) {
	      this->_ThPool.reload(8);
	    }
	  }
	if (elem->getTypeEntity() == type) {
	  if ((this->_ThPool.taskLaunch(*fct.get())) == false) {
	    this->_ThPool.reload(8);
	  }
	}
      }});
}

engineComponentManagerSystem	*engineComponentManagerSystem::_IsManagerCreate = nullptr;
