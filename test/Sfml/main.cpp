//BON COURAGE
#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>

int		joystick_test() 
{
  bool		connected = sf::Joystick::isConnected(0);
  if (connected == true)
    std::cout << "Joystick Connected" << std::endl;
  return 1;
}

int             keyboard_test()
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
    return -1;
  }
  return 1;
}

int		sound_test()
{
  //Loading the Sound File
  sf::SoundBuffer buff;
  if (!buff.loadFromFile(""))
    return -1;

  //Playing the sound loaded
  sf::Sound	sound;
  sound.setBuffer(buff);
  sound.play();

  return 1;
}

int		music_test()
{
  sf::Music	music;
  if (!music.openFromFile(""))
    return -1;
  music.play();
  return 1;
}

int		main()
{
  // Create a window with the same pixel depth as the desktop
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow	window;
  window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "My Window");

  sf::Event	event;
    
  //Run the program as long as the window is open
  while (window.isOpen()) {
    
    //Checking the window's events
    if (window.pollEvent(event)) {

      //If the window is closed
      if (event.type == sf::Event::Closed) {
	std::cout << "Window closing" << std::endl;
	window.close();
	return 1;
      }

      //Testing Keyboard Key
      if (keyboard_test() == -1)
	return -1;
      
      //Testing Xbox COntroller
      if (joystick_test() == -1)
	return -1;
      
      //Playing a sound
      //if (sound_test() == -1)
      //	return -1;
      
      //Playing a song
      //if (music_test() == -1)
      //	return -1;)

      //Clear the window with a black screen
      window.clear(sf::Color::Black);


      window.display();

    }  
  }

  return 1;
}
