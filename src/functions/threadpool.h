#ifndef __FUNCTIONS_THREADPOOL_H__
#define __FUNCTIONS_THREADPOOL_H__
/*************************************************************************
	> File Name: threadpool.h
	> Author: LiuYang
	> Mail: liu-yang91.qq.com
	> Created Time: Thu Nov 25 07:00:29 2021
 ************************************************************************/

#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <thread>

// can use like Task(std::string);
typedef std::function<void(std::string)> TaskFunction;

struct {
    TaskFunction task_function;
    std::string task_param;
}TpTask;

namespace MY_THREAD_POOL{

class ThreadPool
{
public: 
    ThreadPool();
    ~ThreadPool();

    // Add task into task queue, the task_param will be used by Task(string)
    void addTask(TpTask my_task);

    // get Thread max number for threadpool
    inline int getThreadMaxNumber(){return m_thread_max_num;}

private:
    // initialization the Thread pool
    void initThreadpool();

private:
    std::vector<std::thread> m_thread_vec;
    std::queue<Task> m_tasks_queue;
    // define the max thread num;
    int m_thread_max_num;
    bool m_stop_threadpool;


}



} // END of MY_THREAD_POOL

#endif // __FUNCTIONS_THREADPOOL_H__

