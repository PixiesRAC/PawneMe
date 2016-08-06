#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <typeinfo>

/* situé dans la classe bien evidement */

std::condition_variable	cond_var;
std::mutex m;
bool				check = false;

void	fct_thread(int value)
{

  std::this_thread::sleep_for(std::chrono::seconds(1)); /* attend 1sec pour ce thread work simulate */
  //  while (1) {
  std::unique_lock<std::mutex> lock(m);
  std::cout << value << std::endl;
  check = true;
  cond_var.notify_one();

  //    --value;
  //  }
}

int	main()
{
  std::vector<int>		tab = {55, 55, 33, 44, 11, 22, 3333};
  std::vector<std::thread>	tl;
 


  for (auto it : tab){
    tl.push_back(std::thread(fct_thread, it));
  }

  for (auto &it : tl){
    if (check != true)  {
      std::cout << "FALSE" << std::endl;
    }
    //      
    //    std::cout << typeid(it).name() << std::endl;
    it.join();
    check = false;
  }
  return (0);
}
