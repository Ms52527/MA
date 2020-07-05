
// MFC41402View.cpp : CMFC41402View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC41402.h"
#endif

#include "MFC41402Doc.h"
#include "MFC41402View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41402View

IMPLEMENT_DYNCREATE(CMFC41402View, CView)

BEGIN_MESSAGE_MAP(CMFC41402View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_OPENDLG, &CMFC41402View::OnOpendlg)
END_MESSAGE_MAP()

// CMFC41402View 构造/析构

CMFC41402View::CMFC41402View()
{
	// TODO: 在此处添加构造代码

}

CMFC41402View::~CMFC41402View()
{
}

BOOL CMFC41402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41402View 绘制

void CMFC41402View::OnDraw(CDC* /*pDC*/)
{
	CMFC41402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41402View 诊断

#ifdef _DEBUG
void CMFC41402View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41402Doc* CMFC41402View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41402Doc)));
	return (CMFC41402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41402View 消息处理程序


void CMFC41402View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CFileDialog cfd(true);
	int r = cfd.DoModal();

	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();

		a = filename;

		GetDC()->TextOutW(100, 100, filename);

	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC41402View::OnOpendlg()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	dlg.DA = a;
	UpdateData(false);

	int r = dlg.DoModal();
	if (r == IDOK)
	{


	}

}
