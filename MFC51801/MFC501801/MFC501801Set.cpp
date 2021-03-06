
// MFC501801Set.cpp : CMFC501801Set 类的实现
//

#include "stdafx.h"
#include "MFC501801.h"
#include "MFC501801Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC501801Set 实现

// 代码生成在 2020年7月5日, 15:56

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
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFC501801Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\x6d77\x8d3c\x8868;DBQ=D:\\VC\x5b9e\x9a8c\\\x6570\x636e\x6587\x4ef6\\Database3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC501801Set::GetDefaultSQL()
{
	return _T("[海贼王表]");
}

void CMFC501801Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Text(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);
	RFX_Text(pFX, _T("[字段4]"), m_4);
	RFX_Text(pFX, _T("[字段5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC501801Set 诊断

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

