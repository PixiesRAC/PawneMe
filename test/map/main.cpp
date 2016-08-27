#include <thread>
#include <array>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/* EN ATTENDANT A FAIRE AU PROPRE */

/* ENUM CORRESPONDANT AU TYPE DE SPRITE */
typedef enum	/*class*/	e_decor
{
  GRASS,
    BRICK

}			t_decor;

class	tileset
{
public :
  tileset() : quad(sf::Quads, 4) {
    window.create(sf::VideoMode(800, 600), "My window");
  }

  /* FONCTION QUI PERMET DE LOAD LE TILESET */
  
  bool loadTileset(const std::string &&file) {
    if ((m_tileset.loadFromFile(file)) == false)
      return false;
    /* IMPORTANT ############################################################ IMPORTANT @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ IMPORTANT */
    /* C'est ici qu'il permet de savoir quel tileset on utilise, on envoie states a window.draw, il doit y avoir une liaison entre states et le vertexArray, mais OSEF */
    states.texture = &m_tileset;
    return true;
  }

  /* FONCTION QUI INITIE LE STD::ARRAY ET LE STD::AMP */
  
  void	createMap();

  /* fonction qui contient la boucle qui genere la map */
  void	generateMap(const sf::Vector2u&);

  /* taille de la map en x (nombre de sprite) */
  int	x_size_map;

  /* taille de la map en y (nombre de sprite) */
  int	y_size_map;

  /* taille de la map gloab (nombre de sprite), surement a changer, a voir avec js comment on va gerer les map */
  static constexpr  int  sizeMap = 24;

  /* texture du tileset */
  
  sf::Texture m_tileset;

  /* class qui permet de faire un window.draw cf sfml, j'ai pas chercher en profondeur */
  sf::RenderStates states;

  /* class qui contiendra le sprites a afficher */
  
  sf::VertexArray quad;

  /* LA FENETRE */
  
  sf::RenderWindow window;

  /* Tableau qui contiendra la map */
  
  std::array<t_decor, sizeMap> arrayMap;

  /* map qui contient un enum correspondant au decor (sprites), et qui associera une position du tileset a l'enum correspondant */
  
  std::map<t_decor, sf::VertexArray> mapVertex;

};

void tileset::createMap() {
  /* MAP DE 4 SUR 6 */
  
  this->x_size_map = 3;
  this->y_size_map = 5; /* bien evidement lorsque l'on multiplie les deux nombre(+1 a chaque nombre, psk on commence a compter a 0 sur la map et non à 1) on obtient la taille de la map */
                        // 1   2     3       4
  this->arrayMap = { {BRICK, GRASS, BRICK, GRASS, //1
		      BRICK, GRASS, BRICK, GRASS,// 2
  		      BRICK, GRASS, BRICK, GRASS, // 3
  		      BRICK, GRASS, BRICK, GRASS, // 4
		      BRICK, GRASS, BRICK, GRASS, // 5
      		      BRICK, GRASS, GRASS, BRICK} }; // 6


  /* POSITION DE LHERBE DANS LE TILESET */
  
  quad[0].texCoords = sf::Vector2f(0, 0);
  quad[1].texCoords = sf::Vector2f(32, 0);
  quad[2].texCoords = sf::Vector2f(32, 32);
  quad[3].texCoords = sf::Vector2f(0, 32);
  mapVertex[GRASS] = quad;
  
  /* POSITION DE LA BRIQUE  DANS LE TILESET */
  
  quad[0].texCoords = sf::Vector2f(32, 32);
  quad[1].texCoords = sf::Vector2f(64, 32);
  quad[2].texCoords = sf::Vector2f(64, 64);
  quad[3].texCoords = sf::Vector2f(32, 64);
  mapVertex[BRICK] = quad;
}

void tileset::generateMap(const sf::Vector2u &vSizeTile) {

  int	pos_map = 0; /* compteur pour l'indexation de la map */
  
  for (int y = 0; y <= y_size_map; ++y) { /* LARGEUR */
    for (int x = 0; x <= x_size_map; ++x) { /* LONGUEUR */
      //      quad[0].position = sf::Vector2f(0, 0);
      //      quad[1].position = sf::Vector2f(64, 0);
      //      quad[2].position = sf::Vector2f(64, 64);
      //      quad[3].position = sf::Vector2f(0, 64);

      /* POUR TROUVER LES FORMULES, j'ai d'abord essayer les valeurs en dur pour tatonner le terrain, comme afficher ci-dessus et dessous et puis j'ai poser
       * sur papier pour voir les liaision, c'est a partir de la que j'ai trouver les formules */
      
      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML*/
      quad[0].position = sf::Vector2f((vSizeTile.x * x),
				      (vSizeTile.y * y));


      std::cout << "COORDONNEE 1"
		<< " X : "
		<< vSizeTile.x * x
		<< " Y : "
		<< vSizeTile.y * y
		<< std::endl;;

      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML */
      quad[1].position = sf::Vector2f(vSizeTile.x + (vSizeTile.x * x),
				      (vSizeTile.y * y));


      std::cout << "COORDONNEE 2"
		<< " X : "
		<< vSizeTile.x + (vSizeTile.x * x)
		<< " Y : "
		<< vSizeTile.y * y
		<< std::endl;;

      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML */
      quad[2].position = sf::Vector2f(vSizeTile.x + (vSizeTile.x * x),
				      vSizeTile.y + (vSizeTile.y * y));

      std::cout << "COORDONNEE 3"
		<< " X : "
		<< vSizeTile.x + (vSizeTile.x * x)
		<< " Y : "
		<< vSizeTile.y + (vSizeTile.y * y)
		<< std::endl;;


      /* FORMULE POUR METTRE TOUJOURS A LA BONNE POSITION LE SPRITE VOULU CF SFML */
      quad[3].position = sf::Vector2f((vSizeTile.x * x),
				      (vSizeTile.y * (y + 1)));


      std::cout << "COORDONNEE 4"
		<< " X : "
		<< (vSizeTile.x * x)
		<< " Y : "
		<< (vSizeTile.y * (y + 1))
		<< std::endl;

      /* POSITION LE VERTEX SUR LE TILSET ET ACCEDE DIRECTEMENT AU SPRITE VOULUE, grace a this->arrayMap[pos_map] (oublie pas qu'un enum c'est aussi un int, exepter pour les enum class ou la faut static_cast mais ca c'est autre chose*/
      
      quad[0].texCoords = mapVertex[this->arrayMap[pos_map]][0].texCoords;
      quad[1].texCoords = mapVertex[this->arrayMap[pos_map]][1].texCoords;
      quad[2].texCoords = mapVertex[this->arrayMap[pos_map]][2].texCoords;
      quad[3].texCoords = mapVertex[this->arrayMap[pos_map]][3].texCoords;

      if (++pos_map > this->arrayMap.size()) {
	break;
      }

      //      quad[0].texCoords = sf::Vector2f(0, 0);
      //      quad[1].texCoords = sf::Vector2f(32, 0);
      //      quad[2].texCoords = sf::Vector2f(32, 32);
      //      quad[3].texCoords = sf::Vector2f(0, 32);

      /* Draw chaque vertexArray */
      window.draw(quad, states);
      std::cout << std::endl;
    }
    std::cout << "NEW Y" << std::endl;
  }

  //  quad[0].position = sf::Vector2f(64, 0);
  //  quad[1].position = sf::Vector2f(128, 0);
  //  quad[2].position = sf::Vector2f(128, 64);
  //  quad[3].position = sf::Vector2f(64, 64);


  //  quad[0].texCoords = mapVertex[BRICK][0].texCoords;
  //  quad[1].texCoords = mapVertex[BRICK][1].texCoords;
  //  quad[2].texCoords = mapVertex[BRICK][2].texCoords;
  //  quad[3].texCoords = mapVertex[BRICK][3].texCoords;

}

int	main(void)
{
  
  tileset	objTileset;
  
  if ((objTileset.loadTileset("./texture/magecity.png")) == false) {
    std::cerr << "Error load tileset" << std::endl;
    return (1);
  }
  objTileset.window.clear();
  objTileset.createMap();
  objTileset.generateMap(sf::Vector2u(64, 64)); /* zoom automatique */
  
  while (objTileset.window.isOpen())
    {
      // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
      sf::Event event;
      while (objTileset.window.pollEvent(event))
	{
	  // évènement "fermeture demandée" : on ferme la fenêtre
	  if (event.type == sf::Event::Closed)
	    objTileset.window.close();
	}
      objTileset.window.display();
      std::this_thread::sleep_for (std::chrono::seconds(1));
    }

  return (0);
}
