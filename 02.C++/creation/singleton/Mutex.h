#include <pthread.h>
    
class Mutex
{
 public:
    Mutex(pthread_mutex_t *pMutex);      
    ~Mutex();
 private:
    pthread_mutex_t *m_mutex;      
};
