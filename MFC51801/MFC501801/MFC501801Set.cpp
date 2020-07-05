
// MFC501801Set.cpp : CMFC501801Set ���ʵ��
//

#include "stdafx.h"
#include "MFC501801.h"
#include "MFC501801Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC501801Set ʵ��

// ���������� 2020��7��5��, 15:56

IMPLEMENT_DYNAMIC(CMFC501801Set, CRecordset)

CMFC501801Set::CMFC501801Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC501801Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\x6d77\x8d3c\x8868;DBQ=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6\\Database3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC501801Set::GetDefaultSQL()
{
	return _T("[��������]");
}

void CMFC501801Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC501801Set ���

#ifdef _DEBUG
void CMFC501801Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC501801Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

