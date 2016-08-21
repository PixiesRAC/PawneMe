#ifndef COMPONENTWINDOW_HPP_
# define COMPONENTWINDOW_HPP_


#include "../engine/engine_component.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/** 
 * \class componentWindow
 * \brief Class component de la map
 * \author pixies
 */

class   componentWindow : public engineComponent
{
public :
  /* les default surement a modifier */
  componentWindow();
  ~componentWindow();
  componentWindow(componentWindow&) = default;
  componentWindow& operator=(componentWindow&) = default;

  virtual void update();

  virtual void init();

  static  sf::RenderWindow&	getWindow() {
    return (componentWindow::_window);
  }
  
private :

static   sf::RenderWindow	_window;
  
};

#endif /* !COMPONENTWINDOW_HPP_ */

