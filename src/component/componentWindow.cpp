#include <iostream>
#include "../../include/component/componentWindow.hpp"

sf::RenderWindow	componentWindow::_window;

componentWindow::componentWindow()
{
  componentWindow::_window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "PawneMe", sf::Style::Close);
  componentWindow::_window.setFramerateLimit(60);
  std::cout << "Initialisation de la window" << std::endl;
}

componentWindow::~componentWindow()
{
  std::cout << "Je detruit ma window" << std::endl;
}

void	componentWindow::update()
{
  std::cout << "Update de componentWindow" << std::endl;
}


void	componentWindow::init()
{
  std::cout << "Init de componentWindow" << std::endl;
}

