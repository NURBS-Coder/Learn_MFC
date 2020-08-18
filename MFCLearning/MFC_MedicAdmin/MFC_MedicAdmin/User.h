#pragma once
#include "UserSet.h"

class CUser
{
public:
	CUser(void);
	~CUser(void);

public:
	void SetAllMember(CString accout, CString pwd, CString type, CString name =_T(""));
	//��ȡ�˺�
	CString GetAccount();
	//��ȡ����
	CString GetPwd();
	//��ȡ����
	CString GetType();
	//��ȡ����
	CString GetName();

	void SetUserSet(CUserSet *pUserSet);

	//�ɹ�Ϊ�㣬ʧ�ܷ���
	int Login();

private:
	CString m_userAccount;
	CString m_userPwd;
	CString m_userType;
	CString m_userName;

	//�û����ݿ��¼��ָ��
	CUserSet *m_pUserSet;
public:
	//�ɹ�Ϊ�㣬ʧ�ܷ���
	int ChangePwd(CString OldPwd, CString NewPwd, CString SurePwd);
	int DelUser(CString Account);
};

