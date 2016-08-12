#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m;
int i = 0;
bool done = false;

void waits()
{
  std::unique_lock<std::mutex> lk(cv_m);
  std::cout << "Waiting... \n";
  cv.wait(lk);//, [](){return i == 1;});
  std::cout << "...finished waiting. i == 1\n";
  done = true;
}

void signals()
{
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Notifying...\n";
  //  cv.notify_one();

  //  std::unique_lock<std::mutex> lk(cv_m);
  while (!done) {
    static int value = 0;
    //    lk.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //    lk.lock();
    std::cerr << "Notifying again...\n";
    //    if (++value == 5) {
      cv.notify_one();
      //    }
  }
}

int main()
{
  std::thread t1(waits), t2(signals);
  t1.join(); t2.join();
}
