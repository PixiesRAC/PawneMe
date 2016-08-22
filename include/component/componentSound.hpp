#ifndef COMPONENTSOUND_HPP_
# define COMPONENTSOUND_HPP_

#include <SFML/Audio.hpp>
#include "../engine/engine_component.hpp"

typedef enum	class	e_SoundType
{
  MENU,
    GAME,
}			t_SoundType;

/** 
 * \class componentSound
 * \brief Class component du son
 * \author pixies
 */

class   componentSound : public engineComponent
{
public :
  /* les default surement a modifier */
  componentSound();
  ~componentSound() {
    std::cout << "-DESTRUCTEUR de componentSound" << std::endl;
    printf("%p\n", this);
  };
  componentSound(componentSound&) = default;
  componentSound(componentSound* other) {
    if (this != other) {
      other = new componentSound;
    }
    printf("%p\n %p\n", this, other);
  }
  componentSound& operator=(componentSound&) = default;

  virtual void update();

  virtual void init();

  t_SoundType	_soundType;

  static constexpr auto _fileSoundMenu = "./son/348997_klankbeeld_horror-ambience-160531-0886.wav";
  
private :
  
  sf::Music	_music;
};

#endif /* !COMPONENTSOUND_HPP */
