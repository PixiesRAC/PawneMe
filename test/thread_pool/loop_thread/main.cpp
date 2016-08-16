#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

std::mutex	mutex;
std::condition_variable	cond;

void	fct_1()
{
  while (1){
    std::unique_lock<std::mutex>	lock(mutex);
    cond.wait(lock);
    std::cout << "Je suis thread 1" << std::endl;
  }
}

void	fct_2()
{
    while (1){
    std::cout << "Je suis thread 2" << std::endl;
  }
}

int	main(void)
{
  std::thread t1(fct_1);
  std::thread t2(fct_2);

  t1.join();
  t2.join();
  return (0);
}
