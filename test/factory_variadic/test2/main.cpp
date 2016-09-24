#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <functional>

std::vector<std::function<void()>> vF;
			  
template <int First, int End>
struct SwitchKey
{
  static void done() {
      std::cout << First << std::endl;
      SwitchKey<First + 1, End>::done();
    }
};

template <int First>
struct SwitchKey<First, First> /* Quand il sont egaux */
{
  static void done() {
    vF[First]();
    std::cout << "First : " << First << std::endl;
  }
};

int	main()
{
  int constexpr key = 1;

  vF.emplace_back(
		  []() -> void {
		    std::cout << "index 1" << std::endl;
		  });
  vF.emplace_back(
		  []() -> void {
		    std::cout << "index 2" << std::endl;
		  });
  vF.emplace_back(
		  []() -> void {
		    std::cout << "index 3" << std::endl;
		  });

  SwitchKey<0, key>::done();
  return (0);
}
