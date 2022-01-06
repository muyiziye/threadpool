/*************************************************************************
  > File Name: main.cpp
  > Author: LiuYang
  > Mail: liuyang91
  > Created Time: Thu Nov 25 00:21:47 2021
 ************************************************************************/
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>

#include <iostream>

#include "logSystem.hpp"
#include "threadpool.h"
using namespace std;


void fun1(std::string str){
    std::cout << "call fun1: " << str << "The thread id is " << pthread_self()  << std::endl;
}

void fun2(std::string str){
    LOG_TRACE("call fun2, str is %s, thread id is %u.\n", str.c_str(), pthread_self());
    sleep(1);
}

int main()
{
    LOG_ENTER();

    MY_THREAD_POOL::ThreadPool tpool1;

    TpTask task1;
    task1.task_function = fun1;
    task1.task_param = "t1";
    cout << "add 1 task" << endl;
    tpool1.addTask(task1);

    TpTask task2;
    task2.task_function = fun2;

    for (int i=100; i > 0; --i){
        task2.task_param = std::to_string(i);
        tpool1.addTask(task2);
    }

    tpool1.run();
    tpool1.stop();

    LOG_EXIT();
    return 0;
}


