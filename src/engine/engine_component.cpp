#include "../../include/engine/engine_component.hpp"

t_Entity engineComponent::getTypeEntity() const{
  return _type;
};

void  engineComponent::setTypeEntity(const t_Entity type) {
  _type = type;
}
