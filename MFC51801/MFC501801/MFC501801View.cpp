
// MFC501801View.cpp : CMFC501801View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC501801.h"
#endif

#include "MFC501801Set.h"
#include "MFC501801Doc.h"
#include "MFC501801View.h"
#include "BIGpic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC501801View

IMPLEMENT_DYNCREATE(CMFC501801View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC501801View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC501801View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC501801View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC501801View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC501801View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC501801View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFC501801View 构造/析构

CMFC501801View::CMFC501801View()
	: CRecordView(IDD_MFC501801_FORM)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, pic(_T(""))
	, high(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC501801View::~CMFC501801View()
{
}

void CMFC501801View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
}

BOOL CMFC501801View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC501801View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC501801Set;
	CRecordView::OnInitialUpdate();

}


// CMFC501801View 诊断

#ifdef _DEBUG
void CMFC501801View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC501801View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC501801Doc* CMFC501801View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC501801Doc)));
	return (CMFC501801Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC501801View 数据库支持
CRecordset* CMFC501801View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC501801View 消息处理程序


void CMFC501801View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC501801View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC501801View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}


void CMFC501801View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}

void CMFC501801View::OnPaint()
{
	// TODO: 在此添加控件通知处理程序代码
	CPaintDC dc(this);
	CImage img;
	CString filename;
	CString str1;
	GetDlgItemText(IDC_EDIT4, str1);
	filename = str1;

	img.Load(filename);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();

	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}


	pDC->SetStretchBltMode(HALFTONE);//文件不失真
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}






void CMFC501801View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	BIGpic xx;
	xx.fil = m_pSet->m_4;
	xx.DoModal();
}
