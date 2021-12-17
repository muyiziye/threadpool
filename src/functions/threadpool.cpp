#include "threadpool.h"


#define THREAD_MAX_NUMBER 2

namespace MY_THREAD_POOL{

ThreadPool::ThreadPool():
    thread_num(THREAD_MAX_NUMBER),
    m_stop_threadpool(false)
{
    m_thread_vec.clean();
    m_tasks_queue.clean();
}

ThreadPool::~ThreadPool(){}

void ThreadPool::addTask(TpTask mytask){
    m_tasks_queue.push(my_task);
    // todo, send msg to thread_pool
}

void ThreadPool::thread_handle(){
    while(!m_stop_threadpool){

    }
}

void ThreadPool::initThreadpool()
{
    for(int i = 0; i<m_thread_max_num; ++i){
        m_thread_vec.push_back(std::thread(thread_handle()));
    }
        
}

} // END of MY_THREAD_POOL

