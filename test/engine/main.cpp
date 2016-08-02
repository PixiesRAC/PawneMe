#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

/* PAS FINI, JE DOIS MODIFIER LA CLASS MERE POUR QUE CA WORK LARBRE DHERITAGE */
/* BON COURAGE, J'AI TOUT FAIT DANS LE MAIN */

typedef enum class 	e_Entity // (une entité est tout ce qui existe dans le logiciel genre la video, le son, les personnages, ma bite etc...) ////
{
  SON,
    PNJ,
    NOTHING,
    MENU,
    KEYKOARD,
    RAC,
    HERO,
    }			t_Entity;

class	component /* interface entité */
{
public : 
  virtual ~component() = default;
  virtual void update() = 0;
  /* va contenir des methodes pures pour les updates etc... 
   ou alors crée une interface system et une classe system pour chaque entité qui lui appelera les updates, comme ca si on boucle
sur les components, on sera pas obligé de tout parcourir, mais parcours seulement les entitées voulus ! */
};


///// COMPONENT DE TEST (correspond a la data d'une entité)

class	Son : public component /* LE SON*/
{
public : 
  virtual void update() {std::cout << "Update de SON" << std::endl;};
  Son() : _type(t_Entity::SON) {
  }
  t_Entity _type;
};

class	ComponentMonster : public component /* monstre pnj */
{
public :
  virtual void update() {std::cout << "Update de monster" << std::endl;};
  ComponentMonster() : _type(t_Entity::PNJ) {
}
  t_Entity _type;
};

class	ComponentHero : public component /* joueur */
{
public :
  virtual void update() {std::cout << "Update de HERO" << std::endl;};
  ComponentHero() : _type(t_Entity::HERO) {};
  t_Entity _type;
};

class	ComponentRAC : public component /* pnj boss */
{
public :
  virtual void update() {std::cout << "Update de RAC" << std::endl;};
  void	test() {};
  ComponentRAC() : _type(t_Entity::RAC) {};
  ~ComponentRAC() = default;
  ComponentRAC(ComponentRAC&) = default;
  ComponentRAC& operator=(const ComponentRAC&) = default;

public :
  void	run()  {
    std::cout << "Je fait un run" << std::endl;
  }
  t_Entity _type;
};

/* CLASS DE TEST POUR LE MOMENT DUCOUP ELLE EST NUL */
class	ComponentManagerSystem /* class qui va gerer les entité et call les fonction necessaires */
  {
public :
  void	fillVectorComponent(component* cpnmt)
  {
    this->_vComponent.push_back(cpnmt);
    std::cout << this->_vComponent.size() << std::endl;
  }
    void	updateSpecificComponent(t_Entity type)
    {
      //    std::for_each(_vComponent.begin(), _vComponent.end(), [type](component *elem){  /* LAMBDA */
      //	int	i = 0;
      //	if (elem->_type == type) {
      //	std::cout << "Je m'occupe de toute les entitées specifié : " << static_cast<int>(elem->_type) << std::endl; /* Pour le update selecif */
      //	++i;
      //	std::cout << "Il y en a : " << i << std::endl;});
      //	}
      for (auto value : this->_vComponent){
	//	std::cout << static_cast<int>(value->_type) << std::endl; /* Connaitre le type @@@@@@@@@@@@ @@@@@@@@@ @@@@@@@@ ! */
      }
    }
private : 
  std::vector<component*>	_vComponent; /* Liste de  composant */
};


///// FACTORY D'ENTITÉ ///// SE CHARGE DE CRER LES ENTITÉ
namespace nmBuildComponent /* Necessite un namespace pour pouvoir templater et specialiser ses functions  ref => 
http://stackoverflow.com/questions/3052579/explicit-specialization-in-non-namespace-scope*/
{
    template <typename T>
    T * const buildComponentNm()
    {
      component	*entite = new T;
      std::cout << "New component banale : " << std::endl;
      /* GO INIT */
      return (entite);
    }

    template <>
    ComponentRAC* const buildComponentNm<ComponentRAC>()
    {
      ComponentRAC *entite = new ComponentRAC;
      std::cout << "New component RAC : " << std::endl;
      /* GO INIT */
      return (entite);
    }

  template <>
    Son * const buildComponentNm<Son>()
    {
      Son *entite = new Son;
      std::cout << "New component de SON : " << std::endl;
      /* GO INIT */
      return (entite);
    }
};

class	factoryComponent
{
  factoryComponent() = default;
  ~factoryComponent() = default;
  factoryComponent(const factoryComponent &) = delete;
  factoryComponent& operator=(const factoryComponent&) = delete;

public : 

  static factoryComponent	*createFactory() {

    if (IsInstanciate == nullptr) {
      IsInstanciate = new factoryComponent;
      std::cout << "Create factory" << std::endl;
    }
    else
      std::cout << "factory already create" << std::endl;
    return (IsInstanciate);
  };

  static void		kill()
  {
    if (IsInstanciate != nullptr) {
      delete IsInstanciate;
      IsInstanciate = nullptr;
    }
  }

    template <typename T>
    T * const buildComponent()
    {
      return (nmBuildComponent::buildComponentNm<T>()); /* appel du namespace */
    }  
private : 

  static factoryComponent	*IsInstanciate;

};

factoryComponent *factoryComponent::IsInstanciate = nullptr;

int	main()
{
  std::vector<component*>	vComponent;
  ComponentManagerSystem	CpnmtMSystem;

  /* Create factory */
  factoryComponent *fctComponent = factoryComponent::createFactory();

  /* Crée les composants et associe les entités */
  auto *thach = fctComponent->buildComponent<ComponentRAC>();
  thach->update();
  //  CpnmtMSystem.fillVectorComponent(thach);
  //  thach->run();
  //  auto sandy = fctComponent->buildComponent<ComponentHero>();
  //  CpnmtMSystem.fillVectorComponent(sandy);
  //  sandy->run();
  //  auto soundMenu = fctComponent->buildComponent<Son>();
  //  CpnmtMSystem.fillVectorComponent(soundMenu);
  //  auto soundGame = fctComponent->buildComponent<Son>();
  //  CpnmtMSystem.fillVectorComponent(soundGame);
  //  auto soundBoss = fctComponent->buildComponent<Son>();
  //  CpnmtMSystem.fillVectorComponent(soundBoss);

  /* UPDATE */
  CpnmtMSystem.updateSpecificComponent(t_Entity::SON);
  return (0);
}
