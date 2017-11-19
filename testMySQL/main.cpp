#include "testStdHead.h"
#include "testMySql.h"

int testMySql()
{
	int nResult = false;
	int nRetCode = false;
	TC_MySQL* pTcMySql = NULL;
	int nOperateCode = 0;

	pTcMySql = new TC_MySQL();
	LOG_PROCESS_ERROR(pTcMySql);

	while (true)
	{
		bool bForceBreak = false;
		cout << "Please Insert Operate Code:" << endl;
		cin >> nOperateCode;

		switch (nOperateCode)
		{
		case -1:
			bForceBreak = true;
			break;
		case 0:
			pTcMySql->RequestCreateTable();
			break;
		case 1:
			pTcMySql->RequestInsertData();
			break;
		case 2:
			pTcMySql->PRI_ALL_DATA();
		default:
			break;
		}

		if (bForceBreak)
			break;
	}

//Exit1:
	nResult = true;
Exit0:
	if (pTcMySql)
		delete pTcMySql;
	return nResult;
}


int main()
{

	testMySql();

	system("pause");
	return 0;
}