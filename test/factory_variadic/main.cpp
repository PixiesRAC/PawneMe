#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <functional>
#include <type_traits>

class	base
{
public :
  base() {
    std::cout << "construction de base" << std::endl;
  }
  std::string value;
  int		nombre;
};

class	subBaseX : public base
{
public :
  subBaseX() {};
  subBaseX(std::string v, int n) {
    std::cout << "construction de subBaseX" << std::endl;
    value = v; nombre = n;};
};

class	subBaseY : public base
{
public :
  
  subBaseY() {
    std::cout << "construction de subBaseY" << std::endl;
  }
};

class	subBaseZ : public base
{
public :
  subBaseZ() {};
  subBaseZ(int n) {
    nombre = n;
    std::cout << "construction de subBaseZ" << std::endl;
  };
};

typedef enum/* class*/	e_key : int
{
  SUBASEX = 0,
    SUBASEY,
    SUBASEZ,
}			t_key;

std::vector<std::function<void()>> vF;

template <typename U>
base	*factory_(U &&value)
{
  std::cout << __FUNCTION__ << std::endl;
  std::cout << "New instance of "<< typeid(U).name() << std::endl;

}

template <typename U, typename ... Args>
base	*factory_(U &&value, Args &&... args)
{
  std::cout << "IL reste " << sizeof...(args) << std::endl;
  factory_(std::forward<U>(value));
  factory_(std::forward<Args>(args)...);
}

template <typename ... Args> /* With arg parameter */
base	*factory(t_key key, Args &&... args)
{
  vF[key]();
  std::cout << "NOUVEL APPEL A LA FACTORY " << "key : " << key << " " << __FUNCTION__ << " args : " << sizeof...(args) << std::endl;
}

template <>
base	*factory(t_key key) /* WITH 0 ARGS */
{
  std::cout << "Without : " << key << std::endl;
  switch (key) {
  case  t_key::SUBASEX :
    return new subBaseX;
    break;
  case  t_key::SUBASEY :
    return new subBaseY;
    break; // return new SUBASEY
  case  t_key::SUBASEZ :
    return new subBaseZ;
    break; // return new SUBASEZ
  }
}

template <typename T> /* Without parameters */
base	*factory() /* unique_ptr */
{
  std::cout << "New instance of "<< typeid(T).name() << std::endl;
}


int	main()
{
  vF.emplace_back( []() -> void {
      std::cout << "via le vector subBaseX" << std::endl;
    }) ;
  vF.emplace_back( []() -> void {
      std::cout << "via le vector subBaseY" << std::endl;
    });
  vF.emplace_back( []() -> void {
      std::cout << "via le vector subBaseZ" << std::endl;
    });

  //  vF[t_key::SUBASEX]();
  //  vF[t_key::SUBASEY]();

  
  //  factory<subBaseX>();
  base *xBase = factory(t_key::SUBASEX, std::string("coucou"), 42);
  //  std::cout << xBase->value << std::endl;
  //  std::cout << xBase->nombre << std::endl;
  
  base *zBase = factory(t_key::SUBASEZ, 48);
  //  std::cout << zBase->nombre << std::endl;
  
  //  base *yBase = factory(t_key::SUBASEY);
  return (0);
}
