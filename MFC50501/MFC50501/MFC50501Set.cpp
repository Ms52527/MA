
// MFC50501Set.cpp : CMFC50501Set ���ʵ��
//

#include "stdafx.h"
#include "MFC50501.h"
#include "MFC50501Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC50501Set ʵ��

// ���������� 2020��5��18��, 11:57

IMPLEMENT_DYNAMIC(CMFC50501Set, CRecordset)

CMFC50501Set::CMFC50501Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = 0.0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
// #error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC50501Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90\x5b66\x751f\x4fe1\x606f\x8868;DBQ=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6\\\x5b66\x751f\x4fe1\x606f\x8868.xls;DefaultDir=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMFC50501Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMFC50501Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Double(pFX, _T("[�ֻ�����]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC50501Set ���

#ifdef _DEBUG
void CMFC50501Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC50501Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

