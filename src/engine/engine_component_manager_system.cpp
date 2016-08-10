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
      if (type == t_Entity::ALL)
	{
	  elem->update();
	  /* UPDATE ALL */
	}
      if (elem->getTypeEntity() == type) {
	//	if (elem->getTypeEntity() == t_Entity::SON) { /* Surement a stocker dans une map ou alors on fait aussi des specialisation de template pour la fonction on verra apres! */
	//	componentSound  *RealCpnmt = static_cast<componentSound*>(elem); /* Utile pour le specificFunction, à voir ensuite si on call pas specificFunction dans la methode update de la class fils en l'occurence componentSound la */
	elem->update();
	//	  RealCpnmt->specificFunction();
	//	}
      }
    });
}

engineComponentManagerSystem	*engineComponentManagerSystem::_IsManagerCreate = nullptr;
