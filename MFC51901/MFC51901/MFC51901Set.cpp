
// MFC51901Set.cpp : CMFC51901Set ���ʵ��
//

#include "stdafx.h"
#include "MFC51901.h"
#include "MFC51901Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC51901Set ʵ��

// ���������� 2020��5��19��, 20:08

IMPLEMENT_DYNAMIC(CMFC51901Set, CRecordset)

CMFC51901Set::CMFC51901Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC51901Set::GetDefaultConnect()
{
	return _T("DSN=\x589e\x52a0\x4fee\x6539;DBQ=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC51901Set::GetDefaultSQL()
{
	return _T("[12345��]");
}

void CMFC51901Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC51901Set ���

#ifdef _DEBUG
void CMFC51901Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC51901Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

