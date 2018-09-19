#ifndef HTTP_CONN_H_
#define HTTP_CONN_H_

#include <stdio.h>
#include "locker.h"

class http_conn
{
public:
	/*文件名的最大长度*/
	static const int FILENAME_LEN = 200;
	/*读缓冲区的大小*/
	static const int READ_BUFFER_SIZE = 2048;
	/*写缓冲区的大小*/
	static const int WRITE_BUFFER_SIZE = 1024;
	/*HTTP请求方法*/
	enum METHOD
	{
		GET=0,POST,HEAD,PUT,DELETE,TRACE,OPTIONS,CONNECT,PATCH
	};
	
	
};

};
#endif // !HTTP_CONN_H_

