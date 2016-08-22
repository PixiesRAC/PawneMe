#ifndef BRIDGE_TO_MENU_SELECTION_HPP_
# define BRIDGE_TO_MENU_SELECTION_HPP_

#include <map>
#include "../component/componentMenuMain.hpp"


class	bridgeToMenuSelection
{
public :

  bridgeToMenuSelection(t_infoSprite);
  /* pour le moment */
  ~bridgeToMenuSelection() = default;
  
private :

  void	bridgePlay();
  void	bridgeStop() {};
  void	bridgeOptions() {};
  void	bridgeCredtis() {};
#ifndef BRIDGE_TO_MENU_SELECTION_HPP_
# define BRIDGE_TO_MENU_SELECTION_HPP_

#include <map>
#include "../component/componentMenuMain.hpp"


class	bridgeToMenuSelection
{
public :

  bridgeToMenuSelection(t_infoSprite)
  /* pour le moment */
  ~bridgeToMenuSelection() = default;
  
private :

  void	bridgePlay();
  void	bridgeStop() {};
  void	bridgeOptions() {};
  void	bridgeCredtis() {};

  typedef void (bridgeToMenuSelection::*pfuncBridge)(void);
  
  //  engineComponentManagerSystem
  // engineFactoryComponent
  //    /* Get window from componentWindow STATIC */

  /* pour pouvoir la fermer au cas ou */
  sf::RenderWindow&		_Cwindow;
  componentMenu*		_menuMain;

  static std::map<t_infoSprite, pfuncBridge>	_mBridge;

};

#endif /* !BRIDGETOMENUSELECTION*/

  typedef void (bridgeToMenuSelection::*pfuncBridge)(void);
  
  //  engineComponentManagerSystem
  // engineFactoryComponent
  //    /* Get window from componentWindow STATIC */

  /* pour pouvoir la fermer au cas ou */
  sf::RenderWindow&		_Cwindow;
  componentMenu*		_menuMain;

  static std::map<t_infoSprite, pfuncBridge>	_mBridge;

};

#endif /* !BRIDGETOMENUSELECTION*/
