#ifndef THREADPOOL_H_
#define THREADPOOL_H_

/*
 *��ͬ���뷴Ӧ��ģʽ���̳߳�
 *author:RyanXin
*/
#include <list>
#include <stdio.h>
#include <exception>
#include <pthread.h>

#include "locker.h"


/*
 *�ͻ�������Ҫ��֤��״̬����Ϊͬһ�������ϵĲ�ͬ��������ɲ�ͬ���̴߳���
 */

template<typename T>
class threadpool
{
public:
	threadpool(int thread_number = 8, int max_requests = 10000);
	~threadpool();
	bool append(T* request);
private:
	/*�����߳����к��������ϴӹ���������ȡ������ִ��*/
	static void* worker(void* arg);
	void  run();

	int m_thread_number;      /*�̳߳����̵߳���Ŀ*/
	int m_max_requests;       /*�����������������������*/
	pthread_t * m_threads;    /*�����̳߳ص�����,��СΪm_thread_number*/
	std::list<T*> m_workqueue;/*�������*/
	locker m_queuelocker;     /*����������еĻ�����*/
	sem m_queuestat;          /*�Ƿ���������Ҫ����*/
	bool m_stop;              /*�Ƿ�����߳�*/
};
#endif // !THREADPOOL_H_
