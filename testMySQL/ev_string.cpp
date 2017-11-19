#include "ev_string.h"

GYF_STRING::GYF_STRING()
{
	m_str = NULL;
}

GYF_STRING::~GYF_STRING()
{
	if(m_str)
		delete m_str;
}

char* GYF_STRING::c_str()
{
	return m_str ?"":(*m_str).c_str();
}

void GYF_STRING::Init(string& str)
{
	if (!m_str)
		m_str = new string();

	if (!m_str)
		return;

	*m_str = str;
}

void GYF_STRING::Init(char* str)
{
	if (!m_str)
		m_str = new string();

	if (!m_str)
		return;

	*m_str = str;
}

char* GYF_STRING::GetString()
{
	return (*m_str).c_str();
}

bool GYF_STRING::IsEmpty()
{
	if (!m_str)
		return true;

	return m_str->empty()?true:false;
}