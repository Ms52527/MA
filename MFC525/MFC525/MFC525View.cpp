
// MFC525View.cpp : CMFC525View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC525.h"
#endif

#include "MFC525Set.h"
#include "MFC525Doc.h"
#include "MFC525View.h"
#include "bigpic.h"
#include "sort.h"
#include "search.h"
#include "record.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC525View

IMPLEMENT_DYNCREATE(CMFC525View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC525View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC525View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC525View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC525View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC525View::OnRecordLast)
	ON_WM_PAINT()

	ON_BN_CLICKED(IDC_BUTTON1, &CMFC525View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC525View::OnBnClickedButton2)
	ON_COMMAND(ID_Sort, &CMFC525View::OnSort)
	ON_COMMAND(ID_search, &CMFC525View::Onsearch)
	ON_COMMAND(ID_record, &CMFC525View::Onrecord)
END_MESSAGE_MAP()

// CMFC525View 构造/析构

CMFC525View::CMFC525View()
	: CRecordView(IDD_MFC525_FORM)
	, name(_T(""))
	, num(0)
	, age(0)
	, pic(_T(""))
	, high(0)
	, money(0)
	, empty(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC525View::~CMFC525View()
{
}

void CMFC525View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT7, empty);
}

BOOL CMFC525View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC525View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC525Set;
	CRecordView::OnInitialUpdate();

}


// CMFC525View 诊断

#ifdef _DEBUG
void CMFC525View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC525View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC525Doc* CMFC525View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC525Doc)));
	return (CMFC525Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC525View 数据库支持
CRecordset* CMFC525View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC525View 消息处理程序


void CMFC525View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC525View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC525View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}


void CMFC525View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}

void CMFC525View::OnPaint()
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



void CMFC525View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	bigpic xx;
	xx.fil = m_pSet->m_4;
	xx.DoModal();
}


void CMFC525View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);

}


void CMFC525View::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	sort or ;
	int r = or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or .pp);
		m_pSet->Requery();
		UpdateData(false);


	}

}


void CMFC525View::Onsearch()
{
	// TODO: 在此添加命令处理程序代码
	search sea;
	int r = sea.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strFilter = sea.ii;
		m_pSet->Requery();
		UpdateData(false);

	}
}


void CMFC525View::Onrecord()
{
	// TODO: 在此添加命令处理程序代码

	record dlg;
	int n, i;
	CString str, s;

	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())

	{
		n = m_pSet->GetODBCFieldCount();


		for (i = 1; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, str);
			s += _T(" ") + str;
		}
		s += _T("\r\n");
		dlg.xx = s;
		UpdateData(false);
		m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}
}
