
// MFC50501View.cpp : CMFC50501View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC50501.h"
#endif

#include "MFC50501Set.h"
#include "MFC50501Doc.h"
#include "MFC50501View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC50501View

IMPLEMENT_DYNCREATE(CMFC50501View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC50501View, CRecordView)
END_MESSAGE_MAP()

// CMFC50501View 构造/析构

CMFC50501View::CMFC50501View()
	: CRecordView(IDD_MFC50501_FORM)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC50501View::~CMFC50501View()
{
}

void CMFC50501View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}

BOOL CMFC50501View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC50501View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC50501Set;
	CRecordView::OnInitialUpdate();

}


// CMFC50501View 诊断

#ifdef _DEBUG
void CMFC50501View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC50501View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC50501Doc* CMFC50501View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC50501Doc)));
	return (CMFC50501Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC50501View 数据库支持
CRecordset* CMFC50501View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC50501View 消息处理程序
