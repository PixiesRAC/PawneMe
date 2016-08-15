#include <future>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <vector>
#include <queue>

void	fct_thread(int test)
{
  std::this_thread::sleep_for (std::chrono::seconds(3));
  std::cout << "Je suis dans ma fonction thread" << std::endl;
}

class	threadPool
{
  threadPool(threadPool&) = delete;
  threadPool& operator=(threadPool&) = delete;
  
public :
  
  threadPool(int size);
  ~threadPool();

  /* Ajoute les taches a la queue */
  void	addTask(std::function<void(int)>);

private :

  /* Stock les threads */
  std::vector<std::thread>		_vThread;

  /* Stock les taches, en gros la taches de la fonction utilisée */
  std::queue<std::function<void(int)>>	_qTasks;

  std::condition_variable	       	_cond_var;
  std::mutex				_mutex;

  bool					done;
  void					fct_call(int value);
};

threadPool::threadPool(int size) {

  while (size != 0) {
    this->_vThread.push_back(std::thread(&threadPool::fct_call, this, size));
    --size;
  }
}

threadPool::~threadPool() {
  for (auto &thread : _vThread) {
    if (thread.joinable()) {
      thread.join();
    }
  }
}

void threadPool::fct_call(int value) {

  std::function<void(int)>	fctTask;

  std::unique_lock<std::mutex>	verrou(_mutex);

  std::cout << "Je suis en train d'attendre le lancement des threads !" << std::endl;
  _cond_var.wait(verrou,
		 [this]
		 {
		   return (!_qTasks.empty());});

  if (_qTasks.empty()) {
    return;
  }
		       
  std::cout << "J'ai fini d'attendre" << std::endl;
  fctTask = this->_qTasks.front();
  _qTasks.pop();
  fctTask(42);
}

void	threadPool::addTask(std::function<void(int)> fct) {
  
  std::unique_lock<std::mutex>	verrou(_mutex);
  _qTasks.push(fct);
  _cond_var.notify_one();
}

int	main()
{

  threadPool	tP(3);

  tP.addTask(fct_thread);
  //  for (int i = 0; i != 100000; ++i) {
  //    std::cout << "Deroulement du jeux" << std::endl;
  //  }
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  tP.addTask(fct_thread);
  return (0);
}
