#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip> /* setPrecision */
#include "../../include/component/componentMenuMain.hpp"
#include "../../include/engine/engine_factory_component.hpp"

componentMenuMain::componentMenuMain() : _Cwindow(componentWindow::getWindow())
{
  std::cout << "-CONSTRUCTEUR DE componentMenuMain" << std::endl;
  /* Permet d'adapter (mettre à l'echelles) la taille du sprites à l'ecran */
  
  this->_spriteMenu.sprite.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / componentMenuMain::_LwindowsMenu, sf::VideoMode::getDesktopMode().height / componentMenuMain::_HwindowsMenu));

  /* Scale du button, prendra 15% du menu, le calcul c'est juste un pourcentage et ensuite une mise a l'echelle suite au resultat trouver via le pourcentage */
  
  this->_spriteButtonPlay.sprite.setScale(sf::Vector2f((sf::VideoMode::getDesktopMode().width - (sf::VideoMode::getDesktopMode().width * componentMenuMain::_PourcentageButton / 100)) / componentMenuMain::_LwindowsMenuPlay,
						(sf::VideoMode::getDesktopMode().height - (sf::VideoMode::getDesktopMode().height * componentMenuMain::_PourcentageButton / 100)) / componentMenuMain::_HwindowsMenuPlay));

  this->_spriteButtonPlay.sprite.setPosition((sf::VideoMode::getDesktopMode().width - (sf::VideoMode::getDesktopMode().width * 75 / 100))
				      , 0);
}

void		 componentMenuMain::createSprites()
{
  /* MENU */
  if ((this->_textureMenu.loadFromFile(componentMenuMain::_fileTextureMenu)) == true) {
    this->_spriteMenu.sprite.setTexture(this->_textureMenu);
    this->_spriteMenu.who = t_infoSprite::USELESS;
  }
  /* PLAY */
  if ((this->_imgButtonPlay.loadFromFile(componentMenuMain::_fileTextureMenuPlay)) == true) {
    this->_imgButtonPlay.createMaskFromColor(sf::Color::Black);
    this->_textureButtonPlay.loadFromImage(this->_imgButtonPlay);
    this->_spriteButtonPlay.sprite.setTexture(this->_textureButtonPlay);
    this->_spriteButtonPlay.who = t_infoSprite::PLAY;
  }


  this->_sprites.push_back(this->_spriteMenu);
  this->_sprites.push_back(this->_spriteButtonPlay);
  this->fillRect();
}

void		componentMenuMain::fillRect() {
  for (auto &sprite : this->_sprites) {

    if (sprite.who != t_infoSprite::USELESS) {
      e_RectCoorSprite RectCoorSprite;
    
      RectCoorSprite.rectLeft = sprite.sprite.getPosition().x;
      RectCoorSprite.rectTop = sprite.sprite.getPosition().y;
      RectCoorSprite.rectWidth = sprite.sprite.getPosition().x + (componentMenuMain::_LwindowsMenuPlay * sprite.sprite.getScale().x);
      RectCoorSprite.rectHeight = sprite.sprite.getPosition().y + (componentMenuMain::_HwindowsMenuPlay * sprite.sprite.getScale().y);
      RectCoorSprite.who = sprite.who;
      this->_vCoorSprites.push_back(RectCoorSprite);
    }
  }
}
  
void		 componentMenuMain::drawSprites()
{
  for (auto &sprite : this->_sprites) {
    this->_Cwindow.draw(sprite.sprite);
  }
}

bool		componentMenuMain::isContainsMySprites(int x, int y) {

  for (auto &rect : this->_vCoorSprites) {
    if (x >= rect.rectLeft && x <= rect.rectWidth && y >= rect.rectTop && y <= rect.rectHeight) {
      bridgeToMenuSelection bridgeSelectition(rect.who);
      return (true);
    }
  }
  return (false);
}

void             componentMenuMain::keyboardMouseMenu()
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      if (this->isContainsMySprites(sf::Mouse::getPosition(this->_Cwindow).x, sf::Mouse::getPosition(this->_Cwindow).y)) {
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
    this->_Cwindow.close();
  }
}

void componentMenuMain::init()
{
  
  // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
  engineFactoryComponent		*factoryComponent = engineFactoryComponent::createFactory();

  /* REF smart_ptr */
  auto	backgroundSound = std::unique_ptr<componentSound>(factoryComponent->buildComponent<componentSound>());
  
  backgroundSound.get()->init();
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

void	componentMenuMain::update()
{
  while (1) {
    std::cout << "Je suis dans le component MENU" << std::endl;
  }
}
