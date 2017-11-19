#include "ev_mysql.h"
#include "testDefine.h"

GYF_SQL::GYF_SQL()
{
	m_pMySQL = NULL;
}


GYF_SQL::~GYF_SQL()
{
	if (m_pMySQL)
		delete m_pMySQL;
}

int GYF_SQL::Init()
{
	int nResult = false;
	int nRetCode = false;
	m_pMySQL = mysql_init(m_pMySQL);
	LOG_PROCESS_ERROR(m_pMySQL);

Exit0:
	return nResult;
}

int GYF_SQL::Connect(EvString& Host, EvString& Account, EvString& Passwd, EvString& DB, int nPort)
{
	int nResult = false;
	int nRetCode = false;

	m_pMySQL = mysql_real_connect(m_pMySQL, Host.c_str(), Account.c_str(), Passwd.c_str(), DB.c_str(), nPort, NULL, 0);
	EV_PROCESS_ERROR(m_pMySQL);
//Exit1:
	nResult = true;
Exit0:
	return nResult;
}
