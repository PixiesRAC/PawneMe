#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <atomic>

std::condition_variable cond_var; /* dans une classe */
std::mutex		cv_m;
std::atomic<bool>			done(false);

void	update_texture()
{
  int	i = 0;
  
  std::unique_lock<std::mutex> lk(cv_m);
  while (i != 24) {
    std::cout << "J'update les texture" << std::endl;
    ++i;
  }
  done = true;
  cond_var.notify_one();
}

void	coucou()
{
  int	i = 0;
  while (i != 24) {
    std::cout << "Coucou" << std::endl;
    ++i;
  }
}

void	update_texture_2()
{
  std::unique_lock<std::mutex> lk(cv_m);
  std::cout << "Je rentre dans le 2" << std::endl;
  while (!done) {
    cond_var.wait(lk);
  }
  std::cout << "fini de  rentre dans le 2" << std::endl;
}

int		main()
{
  std::cout << std::thread::hardware_concurrency() << std::endl;
  /*  std::thread	tTexture(&update_texture);
  std::thread	t(&coucou);
  std::thread	tTexture2(&update_texture_2);*/


  
  //  tTexture.join();
  //  t.join();
  //  tTexture2.join();
  return (0);
}
