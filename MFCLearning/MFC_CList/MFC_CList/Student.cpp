#include "stdafx.h"
#include "Student.h"


Student::Student(int id,CString name,int age,double score)
{
	m_id = id;
	m_name = name;
	m_age = age;
	m_score = score;
}


Student::~Student(void)
{
}
