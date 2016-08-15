#include <iostream>
#include <chrono>
#include <thread>
#include "../../include/component/componentMenu.hpp"

void             componentMenu::keyboardMenu()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    std::cout << "Left" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    std::cout << "Right" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    std::cout << "Up" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    std::cout << "Down" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    std::cout << "Quit" << std::endl;
  }
}

componentMenu::componentMenu()
{
  this->init();
}

void componentMenu::init()
{
  this->_window.create(sf::VideoMode(800, 600), "PawneMe");
  this->_window.setVerticalSyncEnabled(true);
  // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
  while (this->_window.isOpen())
    {
      // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
      while (this->_window.pollEvent(this->_event))
	{
	  this->keyboardMenu();
	  
	  // évènement "fermeture demandée" : on ferme la fenêtre
	  if (this->_event.type == sf::Event::Closed) {
	    this->_window.close();
	  }
	}
      /* evite la charge CPU */
      std::this_thread::sleep_for(std::chrono::nanoseconds(60));
    }
}

void	componentMenu::update()
{
  std::cout << "update de menu" << std::endl;
}
