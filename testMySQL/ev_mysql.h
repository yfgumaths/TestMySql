#ifndef __EV__MYSQL__H__
#define __EV__MYSQL__H__

#include "mysql.h"
#include "ev_mysql.h"
#include "ev_string.h"

class GYF_SQL
{
public:
	GYF_SQL();
	virtual ~GYF_SQL();
	int Connect(EvString& Host, EvString& Account, EvString& Passwd, EvString& DB, int nPort);
private:
	MYSQL* m_pMySQL;
	int Init();

};

#endif // !__EV__MYSQL__H__

