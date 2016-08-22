#include "../../include/bridge/bridgeToMenuSelection.hpp"
//#include "../../include/engine/engine_factory_component.hpp"
//#include "../../include/engine/engine_component_manager_system.hpp"

extern bool	g_menuSelection;

std::map<t_infoSprite, bridgeToMenuSelection::pfuncBridge> bridgeToMenuSelection::_mBridge = {
  {t_infoSprite::PLAY, &bridgeToMenuSelection::bridgePlay} /*,
							     A rajouter ensuite */
};

/* Envoyer le this du menu principal pour pouvoir le detruire ? */
bridgeToMenuSelection::bridgeToMenuSelection(t_infoSprite infoSprite) : _Cwindow(componentWindow::getWindow()) {

  // http://stackoverflow.com/questions/14814158/c-call-pointer-to-member-function
  //(obj.*pmf)( params );   //  Through an object or reference.
  //(ptr->*pmf)( params );  //  Through a pointer.
  
  pfuncBridge	func;

  func = bridgeToMenuSelection::_mBridge[infoSprite];
  (this->*func)(); /* Parenthese obligatoire, ->* ppur call un pointer d'une fonction membre */
}

void	bridgeToMenuSelection::bridgePlay()
{
  /* DEMARRER LE JEUX */
  std::cout << "Vous avez choisis PLAY" << std::endl;
  this->_Cwindow.close();
  g_menuSelection = true;
}
