#include "../../include/threadPool/threadPool.hpp"

template <typename TASKSIGN>
bool	threadPool<TASKSIGN>::taskLaunch(TASKSIGN f) {
  
  std::unique_lock<std::mutex>	uLock(_mutex);
  this->_QTasks.push(f);
  this->_size--;
  _cond_var.notify_one();
  if (this->_size > 0)
    return (true);
  return (false);
}
