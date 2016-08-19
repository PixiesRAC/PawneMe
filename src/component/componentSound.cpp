#include <iostream>

#include <thread> /* for this_thread pour le chrono */
#include<chrono>

#include "../../include/component/componentSound.hpp"

componentSound::componentSound() : _soundType(t_SoundType::MENU)
{
}

void	componentSound::update()
{
  while (1) {
    std::cout << "Je suis dans le component SON" << std::endl;
  }
}

void componentSound::init()
{
  /* test */
  std::cout << "Init de son" << std::endl;
  if (this->_soundType == t_SoundType::MENU) {
    if ((this->_music.openFromFile(componentSound::_fileSoundMenu)) != false) {
      this->_music.setLoop(true);
      this->_music.play();
    }
  }
}
