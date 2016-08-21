#include <iostream>
#include <chrono>
#include <thread>
#include "../../include/component/componentMenu.hpp"
#include <iomanip> /* setPrecision */

componentMenu::componentMenu() : _Cwindow(componentWindow::getWindow())
{
  /* Permet d'adapter (mettre à l'echelles) la taille du sprites à l'ecran */
  
  this->_spriteMenu.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / componentMenu::_LwindowsMenu, sf::VideoMode::getDesktopMode().height / componentMenu::_HwindowsMenu));

  /* Scale du button, prendra 15% du menu, le calcul c'est juste un pourcentage et ensuite une mise a l'echelle suite au resultat trouver via le pourcentage */
  
  this->_spriteButtonPlay.setScale(sf::Vector2f((sf::VideoMode::getDesktopMode().width - (sf::VideoMode::getDesktopMode().width * componentMenu::_PourcentageButton / 100)) / componentMenu::_LwindowsMenuPlay,
						(sf::VideoMode::getDesktopMode().height - (sf::VideoMode::getDesktopMode().height * componentMenu::_PourcentageButton / 100)) / componentMenu::_HwindowsMenuPlay));

  this->_spriteButtonPlay.setPosition((sf::VideoMode::getDesktopMode().width - (sf::VideoMode::getDesktopMode().width * 75 / 100))
				      , 0);

  //  this->_buttonArea(this->_spriteButtonPlay.getPosition(), size);
}

void		 componentMenu::createSprites()
{
  if ((this->_textureMenu.loadFromFile(componentMenu::_fileTextureMenu)) == true) {
    this->_spriteMenu.setTexture(this->_textureMenu);
  }
  if ((this->_imgButtonPlay.loadFromFile(componentMenu::_fileTextureMenuPlay)) == true) {
    this->_imgButtonPlay.createMaskFromColor(sf::Color::Black);
    this->_textureButtonPlay.loadFromImage(this->_imgButtonPlay);
    this->_spriteButtonPlay.setTexture(this->_textureButtonPlay);
  }
  //  sf::IntRect lol(this->_spriteButtonPlay.getPosition(), sf::Vector2i(200,200));
  this->_sprites.push_back(this->_spriteMenu);
  this->_sprites.push_back(this->_spriteButtonPlay);
}

void		 componentMenu::drawSprites()
{
  for (auto &sprite : this->_sprites) {
    this->_Cwindow.draw(sprite);
  }
}

bool		componentMenu::isContainsMySprites(int x, int y) {
  
  const short		xStart = this->_spriteButtonPlay.getPosition().x;
  const short		xEnd = this->_spriteButtonPlay.getPosition().x + (componentMenu::_LwindowsMenuPlay * this->_spriteButtonPlay.getScale().x);
  const short		yStart = this->_spriteButtonPlay.getPosition().y;
  const short		yEnd = this->_spriteButtonPlay.getPosition().y + (componentMenu::_HwindowsMenuPlay * this->_spriteButtonPlay.getScale().y);
  
  if (x >= xStart && x <= xEnd && y >= yStart && y <= yEnd) {
    return (true);
  }
  return (false);
}

void             componentMenu::keyboardMouseMenu()
{
  //  static int x = 0;
  //  static int y = 0;
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if (this->isContainsMySprites(sf::Mouse::getPosition(this->_Cwindow).x, sf::Mouse::getPosition(this->_Cwindow).y)) {
	std::cout << "Dans le mille" << std::endl;
      }
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    std::cout << "Left" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    std::cout << "Right" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    std::cout << "Up" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    std::cout << "Down" << std::endl;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    std::cout << "Quit" << std::endl;
  }
}

void componentMenu::init()
{
  
  // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
  this->createSprites();
  this->drawSprites();
  while (this->_Cwindow.isOpen())
    {
      // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
      while (this->_Cwindow.pollEvent(this->_event))
	{
	  this->keyboardMouseMenu();	  
	  // évènement "fermeture demandée" : on ferme la fenêtre
	  if (this->_event.type == sf::Event::Closed) {
	    this->_Cwindow.close();
	  }
	}
      this->_Cwindow.display();
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
