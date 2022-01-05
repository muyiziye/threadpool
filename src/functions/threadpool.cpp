#include "threadpool.h"

#include <unistd.h>

#define THREAD_MAX_NUMBER 10

namespace MY_THREAD_POOL{

ThreadPool::ThreadPool():
    m_thread_max_num(THREAD_MAX_NUMBER),
    m_stop_threadpool(false)
{
    m_thread_vec.clear();

    initThreadpool();
}

ThreadPool::~ThreadPool(){
}

void ThreadPool::addTask(TpTask my_task){
    std::lock_guard<std::mutex> lck(m_tasks_mutex);
    m_tasks_queue.push(my_task);
}

void ThreadPool::thread_handle(){
    std::cout << "run thread_handle..." << std::endl;
    std::unique_lock<std::mutex> lck(m_thread_mutex);
    while(!m_stop_threadpool){
        {
            m_cv.wait(lck);
        }

        TpTask my_task; 
        {
            std::lock_guard<std::mutex> new_lck(m_tasks_mutex);
            if (m_tasks_queue.size() < 1){
                continue;
            }
            my_task = m_tasks_queue.front();
            m_tasks_queue.pop();
        }
        my_task.task_function(my_task.task_param);
    }
}

void ThreadPool::initThreadpool()
{
    for(int i = 0; i<m_thread_max_num; ++i){
        m_thread_vec.push_back(std::thread(&ThreadPool::thread_handle, this));
    }
}

void ThreadPool::run()
{
    while(m_tasks_queue.size() != 0){
        m_cv.notify_one();
    }
}

void ThreadPool::stop()
{
    m_stop_threadpool = true;
    m_cv.notify_all();
    for(auto &my_thread : m_thread_vec){
        my_thread.join();
    }
}

} // END of MY_THREAD_POOL

