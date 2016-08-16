#include <iostream>
#include "../../include/component/componentSound.hpp"

componentSound::componentSound()
{
}

void	componentSound::update()
{
  std::cout << "Update de componentSound" << std::endl;
}

void componentSound::init()
{
  std::cout << "lancement du son" << std::endl;
  sf::SoundBuffer buffer;
  buffer.loadFromFile("./son/cartoon001.wav");
  std::cout << buffer.getSampleCount() << std::endl;
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
}
