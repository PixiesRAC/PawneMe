#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

#include <thread>
#include <condition_variable>
#include <mutex>

#include <vector>
#include <queue>

#include <iostream>

/* Prend la signature de la tache qu'on devra thread en param, ca sera le update en l'occurence */

/** 
 * \class threadPool
 * \brief Class de threadPool, contient un template qui correspond
 * à la signature de fonction qu'on voudra thread (exemple : std::function<void()>)
 * \author pixies
 */

template <typename TASKSIGN>
class	threadPool
{

public :

  /** 
   * \fn Constructeur threadPool
   * \param unsigned short size Nombre de thread crée
   * \brief Assigne dans un std::vector le nombre de thread defini
   *	par le parametre
   */
  
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

  /**
   * \fn constructeur par default threadPool
   * \brief SANS PARAMETRE
   */
  
  threadPool() {
    std::cout << "Thread Pool de 0" << std::endl;
  };


  /**
   * \fn Destructeur  ~threadPool
   * \brief join si possible tout les thread cf cpp.com
   */
  
  ~threadPool(){
    for (auto &thread : this->_VThread) {
      if (thread.joinable()) {
	thread.join();
      }
    }
  };
  
  threadPool(threadPool&) = delete;
  threadPool operator=(threadPool&) = delete;

  /**
   * \fn taskLaunch
   * \param TASKSIGN correspond a la signature de fonction des threads
   * \brief Permettra dans lancer la fonction voulu dans le thread en att   *	ente
   */
  
  bool	taskLaunch(TASKSIGN);

private :

  /**
   *	\brief std::vector contenant le nombre de thread 
   *
   */
  std::vector<std::thread>		_VThread;

  /**
   *	\brief std::queue contenant les taches des threads
   *
  */
  
  std::queue<TASKSIGN>			_QTasks;

  unsigned short			_size;

  std::condition_variable		_cond_var;

  std::mutex				_mutex;

  /**
   * \fn fctThread
   * \brief Fonction lancé par le thread qui lancera la fonction voulu pa   *	r l'utilisateur
   */
  
  TASKSIGN	const &fctThread() {

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
  }
};

#endif /* !THREADPOOL_HPP_ */
