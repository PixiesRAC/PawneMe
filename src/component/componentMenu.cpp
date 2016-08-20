#include <iostream>
#include <chrono>
#include <thread>
#include "../../include/component/componentMenu.hpp"
#include <iomanip> /* setPrecision */

void             componentMenu::keyboardMenu()
{
  static int x = 0;
  static int y = 0;

  /* test */
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //    this->_sprite[1].setPosition(sf::Vector2f(x -= 100, y));
    std::cout << "Left" << std::endl;
    //    std::cout << this->_window.getSize().x << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //    this->_sprite[1].setPosition(sf::Vector2f(x += 100, y));
    std::cout << "Right" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    //    this->_sprite[1].setPosition(sf::Vector2f(x, y -= 100));
    std::cout << "Up" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    //    this->_sprite[1].setPosition(sf::Vector2f(x, y += 100));
    std::cout << "Down" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    std::cout << "Quit" << std::endl;
  }
  this->_window.draw(this->_sprite[1]);
}

componentMenu::componentMenu()
{
  /* test   FAIRE UN COMPOSANT WINDOWS SERAIT MIEUX  ET ENSUITE ENVOYER LE COMPOSANT WINDOW EN TANT QU'ATTRIBUT AU OBJET UTILISANT LA FENETRE*/
  /* LA CREATION DE LA FENETRE DOIT ETRE FAIT DANS LE THREAD PRINCIPAL */
  // std::cout << sf::VideoMode::getDesktopMode().width << std::endl;
  // std::cout << sf::VideoMode::getDesktopMode().height << std::endl;
  this->_window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "PawneMe", sf::Style::Close);
  


  this->_sprite[0].setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / componentMenu::_Lwindows, sf::VideoMode::getDesktopMode().height / componentMenu::_Hwindows));
  
  //    / sf::VideoMode::getDesktopMode().height * 100;

  this->_window.setFramerateLimit(60);
  //  this->_window.setActive(false);
}

void componentMenu::init()
{
  /* TEST */
  if ((this->_texture[0].loadFromFile(componentMenu::_fileTextureMenu)) == true) {
    sf::IntRect r1(0, 0, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);    
  this->_sprite[0].setTexture(this->_texture[0]);
  }
  //  if ((this->_img.loadFromFile(componentMenu::_fileTextureMenuSelect)) == true) {
  //    this->_texture[1].loadFromImage(this->_img);
  //    this->_img.createMaskFromColor(sf::Color::Black);
  //    this->_texture[1].create(150, 100);
  //    this->_texture[1].update(this->_img);
  //    this->_sprite[1].setTexture(this->_texture[1]);
  //  }
  this->_window.draw(this->_sprite[0]);
  // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
  while (this->_window.isOpen())
    {
      // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
      while (this->_window.pollEvent(this->_event))
  	{
	  this->_window.clear();
	  this->_window.draw(this->_sprite[0]);
	  this->keyboardMenu();	  
	  // évènement "fermeture demandée" : on ferme la fenêtre
  	  if (this->_event.type == sf::Event::Closed) {
  	    this->_window.close();
  	  }
  	}
      this->_window.display();
      /* evite la charge CPU */
      std::this_thread::sleep_for(std::chrono::microseconds(60));
    }
}

void	componentMenu::update()
{
  while (1) {
    std::cout << "Je suis dans le component MENU" << std::endl;
  }
}
