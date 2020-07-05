
// MFC综合实验View.cpp : CMFC综合实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC综合实验.h"
#endif

#include "MFC综合实验Set.h"
#include "MFC综合实验Doc.h"
#include "MFC综合实验View.h"
#include "bigpic.h"
#include "sort.h"
#include "search.h"
#include "record.h"
#include "edit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC综合实验View

IMPLEMENT_DYNCREATE(CMFC综合实验View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC综合实验View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC综合实验View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC综合实验View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC综合实验View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC综合实验View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC综合实验View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC综合实验View::OnBnClickedButton2)
	ON_COMMAND(ID_Sort, &CMFC综合实验View::OnSort)
	ON_COMMAND(ID_search, &CMFC综合实验View::Onsearch)
	ON_COMMAND(ID_ADD, &CMFC综合实验View::OnAdd)
	ON_COMMAND(ID_MODIFY, &CMFC综合实验View::OnModify)
	ON_COMMAND(ID_DELETE, &CMFC综合实验View::OnDelete)
	ON_COMMAND(ID_record, &CMFC综合实验View::Onrecord)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC综合实验View 构造/析构

CMFC综合实验View::CMFC综合实验View()
	: CRecordView(IDD_MFC_FORM)
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

CMFC综合实验View::~CMFC综合实验View()
{
}

void CMFC综合实验View::DoDataExchange(CDataExchange* pDX)
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

BOOL CMFC综合实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC综合实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC综合实验Set;
	CRecordView::OnInitialUpdate();

}


// CMFC综合实验View 诊断

#ifdef _DEBUG
void CMFC综合实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC综合实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC综合实验Doc* CMFC综合实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC综合实验Doc)));
	return (CMFC综合实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC综合实验View 数据库支持
CRecordset* CMFC综合实验View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC综合实验View 消息处理程序


void CMFC综合实验View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC综合实验View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC综合实验View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}


void CMFC综合实验View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();

}


void CMFC综合实验View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	bigpic xx;
	xx.fil = m_pSet->m_4;
	xx.DoModal();

}


void CMFC综合实验View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);
}


void CMFC综合实验View::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	sort or ;
	int r = or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or .x);
		m_pSet->Requery();
		UpdateData(false);


	}

}


void CMFC综合实验View::Onsearch()
{
	// TODO: 在此添加命令处理程序代码
	search sea;
	int r = sea.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strFilter = sea.y;
		m_pSet->Requery();
		UpdateData(false);

	}

}


void CMFC综合实验View::OnAdd()
{
	// TODO: 在此添加命令处理程序代码

	edit stu;
	int r = stu.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_1 = stu.name;
		m_pSet->m_2 = stu.num;
		m_pSet->m_3 = stu.age;
		m_pSet->m_4 = stu.pic;
		m_pSet->m_5 = stu.high;
		m_pSet->m_6 = stu.money;
		empty = stu.empty;

		m_pSet->Update();
		UpdateData(false);


	}
}


void CMFC综合实验View::OnModify()
{
	// TODO: 在此添加命令处理程序代码
	edit stu;
	m_pSet->Edit();
	
	int Y = stu.DoModal();
	if (Y == IDOK)
	{
		
		m_pSet->Edit();
		m_pSet->m_1 = stu.name;
		m_pSet->m_2 = stu.num;
		m_pSet->m_3 = stu.age;
		m_pSet->m_4 = stu.pic;
		m_pSet->m_5 = stu.high;
		m_pSet->m_6 = stu.money;
		empty = stu.empty;



		m_pSet->Update();
		UpdateData(false);
	}


}


void CMFC综合实验View::OnDelete()
{
	// TODO: 在此添加命令处理程序代码

	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void CMFC综合实验View::Onrecord()
{
	// TODO: 在此添加命令处理程序代码
	CString ss = _T("");
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		CString s;
		int n = m_pSet->GetODBCFieldCount();
		for (int i = 0; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, s);
			ss += s + _T(" ");

		}
		ss += _T("\r\n");
		m_pSet->MoveNext();

	}
	//CClientDC dc(this);
	//dc.TextOutW(700, 100, ss);
	record dlg;
	dlg.pp = ss;
	if (dlg.DoModal() == IDOK)
	{

	}

}


void CMFC综合实验View::OnPaint()
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
