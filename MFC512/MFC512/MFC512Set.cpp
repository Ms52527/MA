
// MFC512Set.cpp : CMFC512Set ���ʵ��
//

#include "stdafx.h"
#include "MFC512.h"
#include "MFC512Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC512Set ʵ��

// ���������� 2020��6��1��, 22:07

IMPLEMENT_DYNAMIC(CMFC512Set, CRecordset)

CMFC512Set::CMFC512Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC512Set::GetDefaultConnect()
{
	return _T("DSN=5\x56fe\x7247;DBQ=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC512Set::GetDefaultSQL()
{
	return _T("[ͼƬ]");
}

void CMFC512Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC512Set ���

#ifdef _DEBUG
void CMFC512Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC512Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

