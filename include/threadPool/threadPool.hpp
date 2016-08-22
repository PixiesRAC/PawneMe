#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

#include "../engine/engine_component.hpp"

#include <thread>
#include <condition_variable>
#include <mutex>

#include <vector>
#include <queue>

#include <iostream>

#include <future>

/* Prend la signature de la tache qu'on devra thread en param, ca sera le update en l'occurence */

/** 
 * \class threadPool
 * \brief Class de threadPool, contient un template qui correspond
 * à la signature de fonction qu'on voudra thread (exemple : std::function<void()>)
 * \author pixies
 */

template <typename TASKSIGN> /* Signature de fonction de la tache */
class	threadPool
{

public :

  /* test */
  void	stop() {
    this->~threadPool();
  }
  
  /** 
   * \fn Constructeur threadPool
   * \param unsigned short size Nombre de thread crée
   * \brief Assigne dans un std::vector le nombre de thread defini
   *	par le parametre
   */
  
  threadPool(unsigned short size) : _size(size), _stop(false) {
    std::cout << "Creation d'une thread pool de :" << size << " " << std::endl;
    this->init(size);
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
    
    this->_stop = true;
    this->_cond_var.notify_all();
    for (auto &thread : this->_VThread) {
      if (thread.joinable()) {
    	thread.join();
      }
    }
    std::cout << "TOUT LES THREADS SONT JOIN"  << std::endl;
  };
  
  threadPool(threadPool<TASKSIGN>& copy) = default;

  
  threadPool<TASKSIGN>& operator=(threadPool<TASKSIGN>& copy) = default;
  
  /**
   * \fn taskLaunch
   * \param TASKSIGN correspond a la signature de fonction des threads
   * \brief Permettra dans lancer la fonction voulu dans le thread en att   *	ente
   */
  
  bool	taskLaunch(TASKSIGN f)	{
    std::unique_lock<std::mutex>	uLock(_mutex);

    this->_QTasks.push(f);
    _cond_var.notify_one();
    /* Pour pouvoir vraiment bien verifier si tout les threads ne sont plus en attente */
    std::cout << _size-- << std::endl;
    if (this->_size > 0) {
      return (true);
    }
    return (false);
  }

    /**
   * \fn reload
   * \param unsigned short size, correspond a la taille de la thread pool
   * \brief Permettra de relancer la thread pool si tout les thread preal   * ablement crée sont ou on deja utilisé
   */

  void	reload(unsigned short size)
  {
    
    /* A VERIFIER vector.capacity() si il ne depasse pas vector.max_size() Si c'est le cas plusieur possibilité de tte maniere une exeception sera lancer, DONC Soit utilisé un vector de vector qui va remplir tout les vectors de thread (solution la - compliqué et qui fonctionne bien) , Soit faire une sorte de redemarage du jeux (cancereux), soit faire en sorte de reduire la taille du vector que l'on utilise, pour ce faire il faudra check quel case du vector (thread) et encore en cour (je sais pas faire) */
    
    this->init(size);
  }
  
private :

  void	init(unsigned short size) {
    
    //    if (size > std::thread::hardware_concurrency()) {
    //      size = std::thread::hardware_concurrency();
    //    }
    this->_size = size;
    try {
      while (size != 0) {
	this->_VThread.push_back(std::thread(&threadPool::fctThread, this));
	--size;
      }
    }
    catch ( const std::exception & e ) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << e.what() << std::endl;;
      std::cout << "Trop de thread demandé, thread remis à : " << this->_VThread.size() << std::endl;
      this->_size = this->_VThread.size();
    }
    std::cout << "SIZE : " << this->_VThread.size() << std::endl;
  };
  
  /**
   *	\brief std::vector contenant le nombre de thread 
   *
   */
  std::vector<std::thread>		_VThread;

  /**
   *	\brief std::queue contenant les taches des threads
   *
  */
  
  std::queue<TASKSIGN>		    	_QTasks;

  unsigned short			_size;

  std::condition_variable		_cond_var;

  std::mutex				_mutex;

  bool					_stop;
  
  /**
   * \fn fctThread
   * \brief Fonction lancé par le thread qui lancera la fonction voulu pa   *	r l'utilisateur
   */
  
  /*  TASKSIGN*/void	/*const &*/fctThread() {

    static int	nb = 0;
    std::function<void()>		task;

    std::unique_lock<std::mutex>	uLock(_mutex);

    std::cout << "En attente de l'utilisation d'un thread : " << ++nb << std::endl;    
    _cond_var.wait(uLock,
    		   [this]
    		   {
    		     return (!(this->_QTasks.empty()) || this->_stop);
    		   }
    		   );
    if (this->_stop == true) {
      std::cout << "J'ai recu le signal stop venant du destucteur de la threadPool" << std::endl;
      return ;
    }
    task = this->_QTasks.front();
    this->_QTasks.pop();
    uLock.unlock(); /* HO PUTIN DE FDP QUI M'A RENDU OUF, il m'a rendu vraiment ouf pour le trouver lui */
    try {
      task();
    }
    catch ( const std::exception & e ) {
      std::cout << "CATCH EXCEPTION" << e.what() << std::endl;
    }
  }
};

#endif /* !THREADPOOL_HPP_ */
