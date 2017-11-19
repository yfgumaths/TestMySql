#include "testStdHead.h"
#include "testMySql.h"

TC_MySQL::TC_MySQL()
{
	m_pMySql = NULL;
	Init();
}

TC_MySQL::~TC_MySQL()
{
	if (m_pMySql)
		mysql_close(m_pMySql);
}

void TC_MySQL::Init()
{
	int nRetCode = false;
	m_pMySql = mysql_init(m_pMySql);
	LOG_PROCESS_ERROR(m_pMySql);

	m_pMySql = mysql_real_connect(m_pMySql, _my_sql_host, _my_sql_account, _my_sql_passwd, _my_sql_db, _my_sql_port, NULL, 0);
	LOG_PROCESS_ERROR(m_pMySql);

//Exit1:
	nRetCode = true;
Exit0:
	return;
}

int TC_MySQL::RequestCreateTable()
{
	int nResult = false;
	int nRetCode = false;
	string strTabName;
	cout << "TableName: " << endl;
	cin >> strTabName;
	
	if (strTabName.empty())
		LOG_PROCESS_ERROR(false);

//Exit1:
	nResult = true;
Exit0:
	return nResult;
}

int TC_MySQL::RequestInsertData()
{
	int nResult = false;
	int nRetCode = false;
	int idx;
	string strName;
	char SqlQuery[1024];
	char strErr[1024] = "\0";
	cout << "idx: " << endl;
	cin >> idx;
	cout << "strName: " << endl;
	cin >> strName;

	if (strName.empty())
	{
		ERR_PRI("%s\n", "strName Cant be NULL!");
		EV_PROCESS_ERROR(false);
	}

	sprintf_s(SqlQuery, "INSERT INTO %s(idx,name) VALUES (%d,\"%s\");", t_test, idx, strName.c_str());
	ERR_PRI("%s\n", SqlQuery);
	nRetCode = mysql_query(m_pMySql, SqlQuery);

	switch (nRetCode)
	{
	case 0:
		EV_PROCESS_SUCCESS(true);
	default:
		break;
	}

Exit1:
	ERR_PRI("%s\n", "RequestInsertData Success!");
	PRI_ALL_DATA();
	nResult = true;
Exit0:
	if (!nResult)
	{
		int nError = mysql_errno(m_pMySql);
		sprintf_s(strErr, "RequestInsertData ERROR ERRCODE = %d!\n\0", nError);
		ERR_PRI("%s\n", strErr);
	}
	return nResult;
}

void TC_MySQL::PRI_ALL_DATA()
{
	int nResult = false;
	int nRetCode = false;

	char SqlQuery[1024];
	char strErr[1024] = "\0";

	MYSQL_RES* pSqlRes = NULL;
	MYSQL_FIELD* pSqlfields = NULL;
	MYSQL_ROW row;
	int nSqlNum;

	sprintf_s(SqlQuery, "SELECT * FROM %s", t_test);
	nRetCode = mysql_real_query(m_pMySql, SqlQuery, strlen(SqlQuery));
	LOG_PROCESS_ERROR(!nRetCode);

	pSqlRes = mysql_store_result(m_pMySql);
	LOG_PROCESS_ERROR(pSqlRes);

	nSqlNum = mysql_num_fields(pSqlRes);
	LOG_PROCESS_ERROR(nSqlNum);

	pSqlfields = mysql_fetch_field(pSqlRes);
	LOG_PROCESS_ERROR(pSqlfields);

	while (row = mysql_fetch_row(pSqlRes))
		printf("idx = %s, name = %s\n", row[0]?row[0]:"NULL", row[1]?row[1]:"NULL");

//Exit1:
	nResult = true;
Exit0:
	if (!nResult)
	{
		int nError = mysql_errno(m_pMySql);
		ERR_PRI("SQL SELECT ERR %d!\n", nError);
	}
	return;
}