#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <iostream>

void	fct_1()
{
  std::this_thread::sleep_for(std::chrono::seconds(1));
  for (int i = 0; i != 150; ++i) {
    std::cout << "Salut je suis thach" << std::endl;
  }
}

int	fct_2(int value)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //  for (int i = 0; i != 150; ++i) {
    //    std::cout << "BONJOUR JE TE BAISE" << std::endl;;
    //  }
    std::cout << value << std::endl;
  return (value);
}


void	fct_3()
{
  std::this_thread::sleep_for(std::chrono::seconds(1));
  for (int i = 0; i != 150; ++i) {
    std::cout << "BONJOUR JE SUIS LA FONCTION THIRD" << std::endl;;
  }  
}


int	main()
{
  //  std::thread	t1(fct_1);
  //  std::thread	t2(fct_2);
  //  std::thread	t3(fct_3);

  //  t1.join();
  //  t2.join();
  //  t3.join();



  //  std::packaged_task<void()> task1(fct_1);
  //  std::packaged_task<int(int)> task2(fct_2);
  //  std::packaged_task<void()> task3(fct_3);

  //  task1();
  //  task2(42);
  //  std::future<int> f1 = task2.get_future();
  //  std::cout << "Je recois " << f1.get() << std::endl;
  //  task3();

  //  auto f = std::async(fct_1);
  //  std::future<int> f1 = std::async(fct_2, 42);
  //  auto f3 = std::async(fct_3);

  //  f.get();
  //  std::cout << "Je recois " << f1.get() << std::endl;
  //  f3.get();

  std::promise<int> p;
  return (0);
}
