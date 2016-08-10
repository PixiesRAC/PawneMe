#ifndef COMPONENTSOUND_HPP_
# define COMPONENTSOUND_HPP_

#include "../engine/engine_component.hpp"

/** 
 * \class componentSound
 * \brief Class component du son
 * \author pixies
 */

class   componentSound : public engineComponent
{
public :
  /* les default surement a modifier */
  componentSound() = default;
  ~componentSound() = default;
  componentSound(componentSound&) = default;
  componentSound& operator=(componentSound&) = default;

  virtual void update();

  /* test */
  void	specificFunction();
  
  /* test */
  int	_specificValue;
};

#endif /* !COMPONENTSOUND_HPP */
