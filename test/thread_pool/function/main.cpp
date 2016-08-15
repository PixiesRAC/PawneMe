#include <iostream>
#include <functional>

void	test(int value)
{
  std::cout << " test " << std::endl;
}

int	main(void)
{
  std::function<void(int)>	f(test);

  f(42);
  return (0);
}
