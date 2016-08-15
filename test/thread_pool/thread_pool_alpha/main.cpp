#include <thread>
#include <condition_variable>
#include <mutex>

#include <vector>
#include <queue>

#include <iostream>

int	fonction_thread_test()
{
  /* Simulation work */
  std::this_thread::sleep_for (std::chrono::seconds(1));
  std::cout << "Fonction pour test la thread pool" << std::endl;
}

/* Prend la signature de la tache qu'on devra thread en param, ca sera le update en l'occurence */

template <typename TASKSIGN>
class	threadPool
{

public :
  
  threadPool(unsigned short size) : _size(size) {
    std::cout << "Creation d'une thread pool de :" << size << " " << std::endl;
    /* Verification nombre de thread max */
    if (size > std::thread::hardware_concurrency()) {
      size = std::thread::hardware_concurrency();
      std::cout << "Trop de thread demandé, thread remis à : " << size << std::endl;
      this->_size = size;
    }
    while (size != 0) {
      this->_VThread.push_back(std::thread(&threadPool::fctThread, this));
      --size;
    }
  };
  
  threadPool() {
    std::cout << "Thread Pool de 0" << std::endl;
  };
  
  ~threadPool(){
    for (auto &thread : this->_VThread) {
      if (thread.joinable()) {
	thread.join();
      }
    }
  };
  
  threadPool(threadPool&) = delete;
  threadPool operator=(threadPool&) = delete;
  
  /* Permettra de lancer la function voulu dans le thread qui à ete préalablement construit */
  bool	taskLaunch(TASKSIGN);

private :

  /* vector contenant le nombre de thread */
  std::vector<std::thread>		_VThread;

  /* queue contenant les taches des threads */
  std::queue<TASKSIGN>			_QTasks;

  /* Nombre de thread restant */
  unsigned short			_size;

  std::condition_variable		_cond_var;

  std::mutex				_mutex;
  
public : 
  TASKSIGN const 	&fctThread() {

    TASKSIGN				task;
    std::unique_lock<std::mutex>	uLock(_mutex);

    std::cout << "En attente de l'utilisation d'un thread" << std::endl;    
    _cond_var.wait(uLock,
		   [this]
		   {
		     return (!(this->_QTasks.empty()));
		   }
		   );

    task = this->_QTasks.front();
    this->_QTasks.pop();
    task();
    return (task);
  }
};

template <typename TASKSIGN>
bool	threadPool<TASKSIGN>::taskLaunch(TASKSIGN f) {
  
  std::unique_lock<std::mutex>	uLock(_mutex);
  this->_QTasks.push(f);
  _cond_var.notify_one();
}

int	main()
{
  threadPool<std::function<int()>>	thPoold(40);

  thPoold.taskLaunch(fonction_thread_test);
  thPoold.taskLaunch(fonction_thread_test);
  return (0);
}
