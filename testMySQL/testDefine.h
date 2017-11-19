#ifndef __TEST__DEFINE__H__
#define __TEST__DEFINE__H__

#include "cstdio"

#define _my_sql_account "yfgu"
#define	_my_sql_passwd  "950gyf101"
#define _my_sql_host	"localhost"
#define _my_sql_db		"cplusplus"
#define _my_sql_port	3306

#define LOG_PROCESS_ERROR(condition)	\
if(!condition)							\
{										\
	printf("File: %s, Line: %d, Function %s ERROR!\n", __FILE__, __LINE__, __FUNCTION__);	\
	goto Exit0;							\
}			

#define EV_PROCESS_ERROR(condition)	\
if(!condition)							\
{										\
	goto Exit0;							\
}	

#define EV_PROCESS_SUCCESS(condition)	\
if(condition)							\
{										\
	goto Exit1;							\
}


#define ERR_PRI(format,...)				\
{										\
	fprintf(stderr, format, ##__VA_ARGS__);		\
}

#endif
