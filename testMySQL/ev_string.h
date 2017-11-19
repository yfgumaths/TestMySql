#ifndef __EV__STRING__H__
#define __EV__STRING__H__

#include <string>
#include <cstring>

#define EvString GYF_STRING
using namespace std;

class GYF_STRING
{
public:
	GYF_STRING();
	virtual ~GYF_STRING();
	char* c_str();
	void Init(string& str);
	void Init(char* str);
	char* GetString();
	bool IsEmpty();
private:
	string* m_str;
};


#endif
