#pragma once
#include "UserSet.h"

class CUser
{
public:
	CUser(void);
	~CUser(void);

public:
	void SetAllMember(CString accout, CString pwd, CString type, CString name =_T(""));
	//获取账号
	CString GetAccount();
	//获取密码
	CString GetPwd();
	//获取类型
	CString GetType();
	//获取名字
	CString GetName();

	void SetUserSet(CUserSet *pUserSet);

	//成功为零，失败非零
	int Login();

private:
	CString m_userAccount;
	CString m_userPwd;
	CString m_userType;
	CString m_userName;

	//用户数据库记录集指针
	CUserSet *m_pUserSet;
public:
	//成功为零，失败非零
	int ChangePwd(CString OldPwd, CString NewPwd, CString SurePwd);
	int DelUser(CString Account);
};

