
// MFC�ۺ�ʵ��Set.cpp : CMFC�ۺ�ʵ��Set ���ʵ��
//

#include "stdafx.h"
#include "MFC�ۺ�ʵ��.h"
#include "MFC�ۺ�ʵ��Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC�ۺ�ʵ��Set ʵ��

// ���������� 2020��7��5��, 18:52

IMPLEMENT_DYNAMIC(CMFC�ۺ�ʵ��Set, CRecordset)

CMFC�ۺ�ʵ��Set::CMFC�ۺ�ʵ��Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = 0;
	m_3 = 0;
	m_4 = L"";
	m_5 = 0;
	m_6 = 0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC�ۺ�ʵ��Set::GetDefaultConnect()
{
	return _T("DSN=\x6700\x7ec8\x8868;DBQ=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6\\Database6.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC�ۺ�ʵ��Set::GetDefaultSQL()
{
	return _T("[���ձ�]");
}

void CMFC�ۺ�ʵ��Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Long(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Long(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Long(pFX, _T("[�ֶ�5]"), m_5);
	RFX_Long(pFX, _T("[�ֶ�6]"), m_6);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC�ۺ�ʵ��Set ���

#ifdef _DEBUG
void CMFC�ۺ�ʵ��Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC�ۺ�ʵ��Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

