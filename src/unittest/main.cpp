/*************************************************************************
	> File Name: main.cpp
	> Author: LiuYang
	> Mail: liuyang91
	> Created Time: Thu Nov 25 00:21:47 2021
 ************************************************************************/
#include <unistd.h>

#include <iostream>

#include "logSystem.hpp"
#include "threadpool.h"
using namespace std;

void fun1(std::string str){
    std::cout << "call fun1:" << str  << std::endl;
}

void fun2(std::string str){
    std::cout << "call fun2:" << str << std::endl;
}

int main()
{
    LOG_ENTER();

    MY_THREAD_POOL::ThreadPool tpool1;
    TpTask task1;
    task1.task_function = fun1;
    task1.task_param = "t1";
    tpool1.addTask(task1);
    
    TpTask task2;
    task2.task_function = fun2;
    task2.task_param = "t2";
    tpool1.addTask(task2);

    tpool1.run();
    usleep(1000000);
    tpool1.stop();


    LOG_EXIT();
    return 0;
}


