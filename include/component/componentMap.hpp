#ifndef COMPONENTMAP_HPP_
# define COMPONENTMAP_HPP_

#include "../engine/engine_component.hpp"

/** 
 * \class componentMap
 * \brief Class component de la map
 * \author pixies
 */

class   componentMap : public engineComponent
{
public :
  /* les default surement a modifier */
  componentMap();
  ~componentMap();
  componentMap(componentMap&) = default;
  componentMap& operator=(componentMap&) = default;

  virtual void update();

  /* Signature de fonction a changer surement
   Possibilité de faire la deserialisation dans un template pour 
  réduire le temps que ca prendra au runtime*/
  void	deserialisationMapFile();
  
  /* test */
  int	_specificValue;
};

#endif /* !COMPONENTMAP_HPP_ */
