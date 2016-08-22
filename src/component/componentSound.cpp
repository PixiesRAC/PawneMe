#include <iostream>

#include <thread> /* for this_thread pour le chrono */
#include<chrono>

#include "../../include/component/componentSound.hpp"

componentSound::componentSound() : _soundType(t_SoundType::MENU)
{
  std::cout << "-CONSTRUCTEUR de componentSound" << std::endl;
}

void	componentSound::update()
{
  while (1) {
    std::cout << "Je suis dans le component SON" << std::endl;
  }
}

void componentSound::init()
{
  /* background son */

  std::cout << "-Init de componentSound" << std::endl;
  if (this->_soundType == t_SoundType::MENU) {
    if ((this->_music.openFromFile(componentSound::_fileSoundMenu)) != false) {
      this->_music.setLoop(true);
      this->_music.play();
    }
  }
  else if (this->_soundType == t_SoundType::GAME) {
    std::cout << "SON DU JEUX" << std::endl;
  }
  //    std::this_thread::sleep_for(std::chrono::microseconds(200));
  //}
}
