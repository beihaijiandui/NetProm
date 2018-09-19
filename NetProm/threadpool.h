#ifndef THREADPOOL_H_
#define THREADPOOL_H_

/*
 *半同步半反应堆模式的线程池
 *author:RyanXin
*/
#include <list>
#include <stdio.h>
#include <exception>
#include <pthread.h>

#include "locker.h"


/*
 *客户请求需要保证无状态，因为同一个连接上的不同请求可能由不同的线程处理
 */

template<typename T>
class threadpool
{
public:
	threadpool(int thread_number = 8, int max_requests = 10000);
	~threadpool();
	bool append(T* request);
private:
	/*工作线程运行函数，不断从工作队列中取出任务并执行*/
	static void* worker(void* arg);
	void  run();

	int m_thread_number;      /*线程池中线程的数目*/
	int m_max_requests;       /*请求队列中允许的最大请求数*/
	pthread_t * m_threads;    /*描述线程池的数组,大小为m_thread_number*/
	std::list<T*> m_workqueue;/*请求队列*/
	locker m_queuelocker;     /*保护请求队列的互斥锁*/
	sem m_queuestat;          /*是否有任务需要处理*/
	bool m_stop;              /*是否结束线程*/
};
#endif // !THREADPOOL_H_
