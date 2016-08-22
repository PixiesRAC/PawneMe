#ifndef BRIDGE_TO_MENU_SELECTION_HPP_
# define BRIDGE_TO_MENU_SELECTION_HPP_

#include <map>
#include "../component/componentMenuMain.hpp"



/** 
 * \class bridgeToMenuSelection
 * \brief Class qui permet de faire un "PONT" entre la selection du joueur et l'execution  * du choix
 * \author pixies
 */

class	bridgeToMenuSelection
{
public :

  bridgeToMenuSelection(t_infoSprite);
  /* pour le moment */
  ~bridgeToMenuSelection() = default;
  
private :

  /** 
 * \fn bridgePlay
 * \brief PONT ENTRE LA CHOIX PLAY ET LEXECUTION DE PLAY
 * \author pixies
 */

  void	bridgePlay();

  
  /** 
 * \fn bridgeStop
 * \brief PONT ENTRE LA CHOIX PLAY ET LEXECUTION DE STOP
 * \author pixies
 */
  
  void	bridgeStop() {};
  void	bridgeOptions() {};
  void	bridgeCredtis() {};

  /* TYPE PE FCT POUR MA MAP */
  
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
