#ifndef COMPONENTSOUND_HPP_
# define COMPONENTSOUND_HPP_

#include <SFML/Audio.hpp>
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
  componentSound();
  ~componentSound() = default;
  componentSound(componentSound&) = default;
  componentSound& operator=(componentSound&) = default;

  virtual void update();

  virtual void init();

};

#endif /* !COMPONENTSOUND_HPP */
