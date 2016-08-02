#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

/* PAS FINI, JE DOIS MODIFIER LA CLASS MERE POUR QUE CA WORK LARBRE DHERITAGE */
/* BON COURAGE, J'AI TOUT FAIT DANS LE MAIN */

typedef enum class 	e_Entity // (une entité est tout ce qui existe dans le logiciel genre la video, le son, les personnages, ma bite etc...) ////
{
  ALL,
    OTHER,
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
  /*  virtual*/ t_Entity getTypeEntity() {
    return _type;
  };
  void	setTypeEntity(t_Entity type) {
    _type = type;
  }
  /* va contenir des methodes pures pour les updates etc... 
   ou alors crée une interface system et une classe system pour chaque entité qui lui appelera les updates, comme ca si on boucle
sur les components, on sera pas obligé de tout parcourir, mais parcours seulement les entitées voulus ! */
protected : 
  t_Entity _type;
};


///// COMPONENT DE TEST (correspond a la data d'une entité)

class	Son : public component /* LE SON*/
{
public : 
  virtual void update() {std::cout << "Update de SON" << std::endl;};
  //  virtual t_Entity getTypeEntity() {};
};

class	ComponentMonster : public component /* monstre pnj */
{
public :
  virtual void update() {std::cout << "Update de monster" << std::endl;};
  //  virtual t_Entity getTypeEntity() {};
};

class	ComponentHero : public component /* joueur */
{
public :
  virtual void update() {std::cout << "Update de HERO" << std::endl;};
  //  virtual t_Entity getTypeEntity() {};
};

class	ComponentRAC : public component /* pnj boss */
{
public :
  virtual void update() {std::cout << "Update de RAC" << std::endl;};
  //  virtual t_Entity getTypeEntity() {
  //    std::cout << static_cast<int>(_type) << std::endl;
  //    return _type;
  //  };
  void	RACPOWA()
  {
    std::cout << "FONCTION DU RAC TAVUH" << std::endl;
  }
  void InitValueSpecificRac(int value)
  {
    this->value_RAC = value;
  }
  int	value_RAC;
};

/* CLASS DE TEST POUR LE MOMENT DUCOUP ELLE EST NUL */
class	ComponentManagerSystem /* class qui va gerer les entité et call les fonction necessaires Faire un singleton*/
  {
public :
    void	fillVectorComponent(component* cpnmt) /* pour faire un fector de composant */
  {
    this->_vComponent.push_back(cpnmt);
    std::cout << this->_vComponent.size() << std::endl;
  }
    void	updateSpecificComponent(t_Entity type) /* Pour pouvoir update les entité voulu */
    {
      std::for_each(_vComponent.begin(), _vComponent.end(), [type](component *elem){  /* LAMBDA */
	  if (type == t_Entity::ALL)
	    {
	      std::cout << "Loop sur tout les entity" << std::endl;
	    }
	  else if (elem->getTypeEntity() == type) {
	    std::cout << static_cast<int>(elem->getTypeEntity()) << std::endl;
	  }
	});
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
      T	*entite = new T;
      entite->setTypeEntity(t_Entity::OTHER);
      std::cout << "New component banale : " << std::endl;
      /* GO INIT */
      return (entite);
    }

    template <>
    ComponentRAC* const buildComponentNm<ComponentRAC>()
    {
      ComponentRAC *entite = new ComponentRAC;
      entite->setTypeEntity(t_Entity::RAC);
      entite->InitValueSpecificRac(42);
      std::cout << "New component RAC : " << std::endl;
      /* GO INIT */
      return (entite);
    }

  template <>
    Son * const buildComponentNm<Son>()
    {
      Son *entite = new Son;
      entite->setTypeEntity(t_Entity::SON);
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

void	myfunction(component *compo) /* Fonction qui verifie juste si le type stocker dans la class component fonctionne */
{
  if (compo->getTypeEntity() == t_Entity::RAC) { /* Surement a stocker dans une map */
    ComponentRAC  *Realjs = static_cast<ComponentRAC*>(compo);
    Realjs->RACPOWA();
    std::cout << Realjs->value_RAC << std::endl;
  }
  else {
    std::cout << "Faire d'autre if" << std::endl;
  }
}

int	main()
{
  std::vector<component*>	vComponent;
  ComponentManagerSystem	CpnmtMSystem;

  /* Create factory */
  factoryComponent *fctComponent = factoryComponent::createFactory();

  /* Crée les composants et associe les entités */
  component* thach = fctComponent->buildComponent<ComponentRAC>();
  std::cout << typeid(thach).name() << std::endl; // => Component
  // OU //
  auto* thach2 = fctComponent->buildComponent<ComponentRAC>();
  std::cout << typeid(thach2).name() << std::endl; // => ComponentRAC

  thach->update();
  CpnmtMSystem.fillVectorComponent(thach);
  //  thach->run();
  auto sandy = fctComponent->buildComponent<ComponentHero>();
  CpnmtMSystem.fillVectorComponent(sandy);
  //  sandy->run();
  auto soundMenu = fctComponent->buildComponent<Son>();
  CpnmtMSystem.fillVectorComponent(soundMenu);
  auto soundGame = fctComponent->buildComponent<Son>();
  CpnmtMSystem.fillVectorComponent(soundGame);
  auto soundBoss = fctComponent->buildComponent<Son>();
  CpnmtMSystem.fillVectorComponent(soundBoss);

  /* UPDATE */
  std::cout << std::endl;
  CpnmtMSystem.updateSpecificComponent(t_Entity::SON); /* Update les sons */ /* Mettre chaque type de update dans un thread ???, */
  std::cout << std::endl;
  CpnmtMSystem.updateSpecificComponent(t_Entity::ALL); /* Update tout */







  /* TEST ARBRE */

  ComponentRAC* js = new ComponentRAC; // se fait dans la factory
  js->setTypeEntity(t_Entity::RAC); // Se fait dans la factory
  js->InitValueSpecificRac(42); // se fait dans la factory

  // call de fonction prenant un components 
  myfunction(soundBoss);
  myfunction(js);
  return (0);
}
