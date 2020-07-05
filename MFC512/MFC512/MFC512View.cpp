
// MFC512View.cpp : CMFC512View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC512.h"
#endif

#include "MFC512Set.h"
#include "MFC512Doc.h"
#include "MFC512View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC512View

IMPLEMENT_DYNCREATE(CMFC512View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC512View, CRecordView)
	
	ON_COMMAND(ID_RECORD_FIRST, &CMFC512View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC512View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC512View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC512View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC512View 构造/析构

CMFC512View::CMFC512View()
	: CRecordView(IDD_MFC512_FORM)
	, Pname(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	Path = _T("D:\\VC实验\\数据文件\\实验图片\\");
	a = 0;

}

CMFC512View::~CMFC512View()
{
}

void CMFC512View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC512View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC512View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC512Set;
	CRecordView::OnInitialUpdate();

}


// CMFC512View 诊断

#ifdef _DEBUG
void CMFC512View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC512View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC512Doc* CMFC512View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC512Doc)));
	return (CMFC512Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC512View 数据库支持
CRecordset* CMFC512View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC512View 消息处理程序





void CMFC512View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码

	m_pSet->MoveFirst();
	UpdateData(false);
	
	
	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();

	
}


void CMFC512View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	
	
	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();
	
}


void CMFC512View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码

	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	

	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();
	
	
}


void CMFC512View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	

	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();
	

}

void CMFC512View::Drawpic(CString file)
{
	CImage img;
	img.Load(file);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();


	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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

void CMFC512View::OnPaint()
{
	CPaintDC dc(this);
	CImage img;
	
	
	if (a == 0)
	{
		CString str1;
		GetDlgItemText(IDC_EDIT1, str1);
		filename = Path + str1;
	}
	
	img.Load(filename);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();

	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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
