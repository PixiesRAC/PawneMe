#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>

std::condition_variable cv;
std::mutex cv_m;

void	func_1()
{
  std::cout << "Je suis dans la fonction 1" << std::endl;
  std::unique_lock<std::mutex> lk(cv_m);
  cv.wait(lk);
  cv.notify_one();
}

void	func_2()
{
  std::cout << "Je suis dans la fonction 2" << std::endl;
  std::unique_lock<std::mutex> lk(cv_m);
  cv.wait(lk);
  cv.notify_one();

}

void	func_3()
{
  cv.notify_one();
  std::unique_lock<std::mutex> lk(cv_m);
  //  cv.wait(lk);
  std::cout << "Je suis dans la fonction 3" << std::endl;
}

int	main()
{
  std::thread	t1(func_1);
  std::thread	t2(func_2);
  std::thread	t3(func_3);

  t1.join();
  t2.join();
  t3.join();
  return (0);
}
