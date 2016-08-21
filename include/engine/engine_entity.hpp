#ifndef ENGINE_ENTITY_HPP_
# define ENGINE_ENTITY_HPP_

/**
* \enum t_Entity
* \brief Union contenant toute les entitées du jeux
* \author Pixies
*/

typedef enum class      e_Entity // (une entité est tout ce qui existe dans le logiciel genre la video, le son, les personnages etc...)
{
  ALL,
    OTHER,
    NOTHING,
    WINDOW,
    MAP,
    SON,
    PNJ,
    HERO,
    MENU,
    KEYKOARD,
    }                   t_Entity;

#endif /* !ENGINE_ENTITY_HPP_ */
