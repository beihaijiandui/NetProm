#ifndef HTTP_CONN_H_
#define HTTP_CONN_H_

#include <stdio.h>
#include "locker.h"

class http_conn
{
public:
	/*�ļ�������󳤶�*/
	static const int FILENAME_LEN = 200;
	/*���������Ĵ�С*/
	static const int READ_BUFFER_SIZE = 2048;
	/*д�������Ĵ�С*/
	static const int WRITE_BUFFER_SIZE = 1024;
	/*HTTP���󷽷�*/
	enum METHOD
	{
		GET=0,POST,HEAD,PUT,DELETE,TRACE,OPTIONS,CONNECT,PATCH
	};
	
	
};

};
#endif // !HTTP_CONN_H_

