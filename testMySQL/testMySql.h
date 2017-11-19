#ifndef __TEST__MYSQL__H__
#define __TEST__MYSQL__H__

#define t_test "t_test"
#define t_schema "cplusplus"

class TC_MySQL
{
public:
	TC_MySQL();
	virtual ~TC_MySQL();
	int RequestCreateTable();
	int RequestInsertData();
	void PRI_ALL_DATA();
private:
	void Init();
	MYSQL* m_pMySql;
};


#endif // !__TEST__MYSQL__H__
