
// MFC51901View.cpp : CMFC51901View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC51901.h"
#endif

#include "MFC51901Set.h"
#include "MFC51901Doc.h"
#include "MFC51901View.h"
#include "ADD_DLG.h"
#include "DLG_MODIFY.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC51901View

IMPLEMENT_DYNCREATE(CMFC51901View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC51901View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC51901View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC51901View::OnBnClickedButton3ADD)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC51901View::OnBnClickedButton4MODIFY)
END_MESSAGE_MAP()

// CMFC51901View 构造/析构

CMFC51901View::CMFC51901View()
	: CRecordView(IDD_MFC51901_FORM)
	, P(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC51901View::~CMFC51901View()
{
}

void CMFC51901View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC51901View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC51901View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC51901Set;
	CRecordView::OnInitialUpdate();

}


// CMFC51901View 诊断

#ifdef _DEBUG
void CMFC51901View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC51901View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC51901Doc* CMFC51901View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC51901Doc)));
	return (CMFC51901Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC51901View 数据库支持
CRecordset* CMFC51901View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC51901View 消息处理程序


void CMFC51901View::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//删除
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void CMFC51901View::OnBnClickedButton3ADD()
{
	// TODO: 在此添加控件通知处理程序代码
	//增加
	ADD_DLG  adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long I = adddlg.L;
		m_pSet->AddNew();
		m_pSet->m_1 = I;
		m_pSet->Update();
		UpdateData(false);


	}

}


void CMFC51901View::OnBnClickedButton4MODIFY()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改
	m_pSet->Edit();
	DLG_MODIFY modifydlg;
	int Y= modifydlg.DoModal();
	if (Y == IDOK)
	{
		long I = modifydlg.M;
		m_pSet->Edit();
		m_pSet->m_1 = I;
		m_pSet->Update();
		UpdateData(false);
	}

	
}
