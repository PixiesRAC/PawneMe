#include "map.h"



int		main() {
  /*  sf::RenderWindow window(sf::VideoMode(700, 500), "Titre");
  sf::Event event;
     
  Map map1("texture1.jpg");

  int		Map[LARGEUR_TILE][HAUTEUR_TILE] = {0, 0, 0, 0, 0,
						   0, 0, 0, 0, 0,
						   0, 0, 0, 1, 0,
						   0, 0, 0, 1, 0,
						   1, 1, 1, 1, 1,};

  map1.loadMapFromTab(Map);
  map1.getMap();
  
  while(window.isOpen())
    {
      while(window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed) {
	    std::cout << "Closing Window" << std::endl;
	    window.close();
	    return 1;
	  }
        }
         
      window.clear();
      map1.drawMap(window, Map);
      window.display();
    }
  
  return 0;

  */
  Map		map("caca");
						
  int           Map[LARGEUR_TILE][HAUTEUR_TILE] = {1, 1, 1, 1, 1,
                                                   1, 1, 1, 1, 1,
                                                   1, 1, 1, 2, 1,
                                                   1, 1, 1, 2, 1,
                                                   2, 2, 2, 2, 2,};


  map.loadNewMapFromTab(Map);
  map.run();
}
