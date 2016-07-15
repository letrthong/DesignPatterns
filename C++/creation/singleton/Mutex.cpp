#include "Mutex.h"
    
Mutex::Mutex(pthread_mutex_t *pMutex)
{
     m_mutex = pMutex;
     pthread_mutex_lock(m_mutex);
}
          
Mutex::~Mutex()
{
    pthread_mutex_unlock(m_mutex);
}