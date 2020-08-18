#include "stdafx.h"
#include "User.h"


CUser::CUser(void)
{
	m_pUserSet = NULL;
}


CUser::~CUser(void)
{
}


void CUser::SetAllMember(CString account, CString pwd, CString type, CString name)
{
	m_userAccount=account;
	m_userPwd=pwd;
	m_userType=type;
	m_userName=name;
}

CString CUser::GetAccount()
{
	return m_userAccount;
}

CString CUser::GetPwd()
{
	return m_userPwd;
}

CString CUser::GetType()
{
	return m_userType;
}

CString CUser::GetName()
{
	return m_userName;
}

void CUser::SetUserSet(CUserSet *pUserSet)
{
	m_pUserSet = pUserSet;
}

int CUser::Login()
{
	if(m_pUserSet == NULL)
	{
		return -1;
	}

	//���ù�������
	CString SQL;
	SQL.Format(_T("account = '%s' and password = '%s' and classification = '%s'"),m_userAccount,m_userPwd,m_userType);

	//����
	m_pUserSet->m_strFilter = SQL;

	//��ѯ
	m_pUserSet->Requery();

	//�ж���û������
	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -2;
	}

	return 0;
}

int CUser::ChangePwd(CString OldPwd, CString NewPwd, CString SurePwd)
{
	if(m_pUserSet == NULL)
	{
		return -1;
	}

	if (OldPwd.IsEmpty() || NewPwd.IsEmpty() || SurePwd.IsEmpty())
	{
		return -2;
	}

	if (OldPwd != m_userPwd)
	{
		return -7;
	}

	if (OldPwd == NewPwd)
	{
		return -3;
	}

	if(NewPwd != SurePwd)
	{
		return -4;
	}

	//�������������ݿ�ָ��ָ��ǰ��Ҫ��������
	CString SQL;
	SQL.Format(_T("account = '%s' and password = '%s' and classification = '%s'"),m_userAccount,m_userPwd,m_userType);

	//����
	m_pUserSet->m_strFilter = SQL;

	//��ѯ
	m_pUserSet->Requery();

	//�ж���û������
	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -5;
	}

	//�޸�����
	m_pUserSet->Edit();

	m_pUserSet->m_password = NewPwd;

	//����
	if (m_pUserSet->CanUpdate())
	{
		if(TRUE == m_pUserSet->Update())	//���³ɹ�
		{
			m_userPwd = NewPwd;
		}else
		{
			return -6;
		}
	}

	return 0;
}


int CUser::DelUser(CString Account)
{
	if(m_pUserSet == NULL)
	{
		return -1;
	}

	if (Account.IsEmpty())
	{
		return -2;
	}

	if(Account == m_userAccount)
	{
		return -3;
	}

	//�������������ݿ�ָ��ָ��ǰ��Ҫ��������
	CString SQL;
	SQL.Format(_T("account = '%s'"),Account);

	//����
	m_pUserSet->m_strFilter = SQL;

	//��ѯ
	m_pUserSet->Requery();

	//�ж���û������
	if (m_pUserSet->GetRecordCount() == 0)
	{
		return -4;
	}

	//ɾ���˺ż�¼
	m_pUserSet->Delete();

	//���£�����Ҫ��������
	//if (m_pUserSet->CanUpdate())
	//{
	//	if(FALSE == m_pUserSet->Update())	//����ʧ��
	//	{
	//		return -5;
	//	}
	//}

	return 0;
}
