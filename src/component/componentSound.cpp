#include <iostream>
#include "../../include/component/componentSound.hpp"

void	componentSound::update()
{
  std::cout << "Update de componentSound" << std::endl;
  //  this->specificFunction();
}

void	componentSound::specificFunction()
{
  std::cout << _specificValue << std::endl;
};
