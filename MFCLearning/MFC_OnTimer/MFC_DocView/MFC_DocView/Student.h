#pragma once
class Student
{
public:
	Student(int id,CString name,int age,int score);
	~Student(void);

public:
	int m_id;
	CString m_name;
	int m_age;
	int m_score;

};

