#ifndef COMPONENTGAMING_HPP_
# define COMPONENTGAMING_HPP_

#include "../engine/engine_component.hpp"

/** 
 * \class componentGaming
 * \brief Class component du son
 * \author pixies
 */

class   componentGaming : public engineComponent
{
public :
  /* les default surement a modifier */
  componentGaming();
  ~componentGaming() {
    std::cout << "-DESTRUCTEUR de componentGaming" << std::endl;
  };
  componentGaming(componentGaming&) = default;
  componentGaming& operator=(componentGaming&) = default;

  virtual void update() override final;

  virtual void init() override final;

};

#endif /* !COMPONENTGAMING_HPP */
