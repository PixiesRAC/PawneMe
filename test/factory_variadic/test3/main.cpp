#include <functional>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
class	base
{
public :
  virtual void display() {
    std::cout << "BASE" << std::endl;
  }
  virtual int get() = 0;
};

class	subBaseA : public base
{
public :
  subBaseA(int a, std::string n) :
    _a(a),
    _n(n)
  {};

    virtual void display() {
    std::cout << "BASE A" << std::endl;
  }

  virtual int get(){};
  int		_a;
  std::string	_n;
};


class	subBaseB : public base
{
public :
  subBaseB(bool	b) :
    _b(b)
  {};

    virtual void display() {
    std::cout << "BASE B" << std::endl;
  }

  virtual int get() { return _b; };
  bool _b;
};

void	testBase(base *b)
{
  b->display();
  std::cout << typeid(b).name() << std::endl;
  std::cout << b->get() << std::endl;
}

template <typename Type>
class	factory
{
public :
  template <typename ...Args>
  static Type *create(Args &&...args) noexcept {
    Type *_type = new Type(std::forward<Args>(args)...);
    return (_type);
  }
  };


template <typename T>
void	_display(T last)
{
  std::cout << last << std::endl;
}

template <typename T, typename ...Args>
void	_display(T value, Args ...args) {
  std::cout << value << std::endl;
  _display((args)...);
}

template <typename ...Args>
void	display(Args &&...args) {
  std::cout << "Appel de la fonction variadique" << sizeof...((args)) << std::endl;
  _display(std::forward<Args>(args)...);
}



int	main()
{
  display(42, 48, 98, 48, 1584, 42, 25, 12);
  subBaseA *baseA = factory<subBaseA>::create<int>(42, std::string("test"));
  std::cout << "New instance of "<< typeid(baseA).name() << std::endl;
  subBaseB *baseB = factory<subBaseB>::create<int>(false);
  std::cout << "New instance of "<< typeid(baseB).name() << std::endl;

  testBase(baseA);
  testBase(baseB);
  return (0);
}
