#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <atomic>

//std::atomic<int> Aval(12);
int	forward =5;

class	test
{
public : 
  test() {done = false, done2 = false;}
  ~test() = default;
  test(const test&) = delete;
  test& operator=(test&) = delete;
  
public :
  /* static */   int		update(int);
  /* static */	 int		afterUpdate();
  void	coucou();

  
  std::mutex			_m;
  std::condition_variable	cond_var;
  bool				done;
  bool				done2;
  
};

int	test::afterUpdate()
{
  std::unique_lock<std::mutex> lock(this->_m);
  std::cout << "Waiting" << std::endl;
  cond_var.wait(lock);
  std::this_thread::sleep_for(std::chrono::seconds(1)); /* Simulate Work */
  std::cout << "After the update" << std::endl;
}

int	test::update(int value)
{
  std::this_thread::sleep_for(std::chrono::seconds(1)); /* Simulate Work */
  std::cout << "Je suis dans ma fonction UPDATE\nValue: " << value << std::endl;
  this->cond_var.notify_one();
  
  std::unique_lock<std::mutex> lock(this->_m);
  std::cout << forward++ << std::endl;
  if (!this->done && !this->done2) {
    lock.unlock(); /* WHY */
    std::this_thread::sleep_for(std::chrono::seconds(1)); /* Simulate Work */
    std::cout << "JE SUIS SUR MON DERNIER THREAD" << std::endl;
    lock.lock(); /* WHY */
    this->cond_var.notify_one();
  }
  
  //  this->done = true;
}

void	test::coucou()
{
  std::unique_lock<std::mutex> lock(this->_m);
  cond_var.wait(lock);
  std::cout << "Coucou" << std::endl;
  this->done = true;
  this->done2 = true;
  this->cond_var.notify_one();
}

int	main()
{
  test	Test;
  
  constexpr int	limit = 5;
  //  std::vector<std::thread> tl;

  //  tl.push_back(std::thread(&test::afterUpdate, &Test));
  //  for (int i = 0; i != limit; ++i) {
  //    tl.push_back(std::thread(&test::update, i));
  //  tl.push_back(std::thread(&test::update, &Test, 5));
  //  }
  
  //  for (auto &it : tl)
  //    {
  //      it.join();
  //}
  std::thread t1(&test::update, &Test, 5);
  std::thread t2(&test::afterUpdate, &Test);
  std::thread t3(&test::coucou, &Test);

  t3.join();
  t1.join();
  t2.join();
  return (0);
}
