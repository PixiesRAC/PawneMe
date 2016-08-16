#include <iostream>

#include <thread> /* for this_thread pour le chrono */
#include<chrono>

#include "../../include/component/componentSound.hpp"

componentSound::componentSound()
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
  while (1) {
    std::cout << "Je suis dans le component thread du  SON" << std::endl;
    std::cout << "lancement du son" << std::endl;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("./son/cartoon001.wav");
    std::cout << buffer.getSampleCount() << std::endl;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
