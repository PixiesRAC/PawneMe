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
  /* test  */
  /* LA CREATION DE LA FENETRE DOIT ETRE FAIT DANS LE THREAD PRINCIPAL */
  this->_window.create(sf::VideoMode(componentMenu::_Hwindows, componentMenu::_Lwindows), "PawneMe");
  this->_window.setActive(false);
}

void componentMenu::init()
{
  if ((this->_texture.loadFromFile(componentMenu::_fileTextureMenu)) == true) {
    this->_sprite.setTexture(this->_texture);
  }
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
      //      this->_window.clear(sf::Color::Black);
      this->_window.draw(this->_sprite);
      this->_window.display();
      /* evite la charge CPU */
      std::this_thread::sleep_for(std::chrono::nanoseconds(60));
    }
}

void	componentMenu::update()
{
  while (1) {
    std::cout << "Je suis dans le component MENU" << std::endl;
  }
}
