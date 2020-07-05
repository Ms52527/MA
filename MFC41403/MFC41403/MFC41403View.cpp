
// MFC41403View.cpp : CMFC41403View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC41403.h"
#endif

#include "MFC41403Doc.h"
#include "MFC41403View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41403View

IMPLEMENT_DYNCREATE(CMFC41403View, CView)

BEGIN_MESSAGE_MAP(CMFC41403View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_OPENDLG, &CMFC41403View::OnOpendlg)
END_MESSAGE_MAP()

// CMFC41403View 构造/析构

CMFC41403View::CMFC41403View()
{
	// TODO: 在此处添加构造代码

}

CMFC41403View::~CMFC41403View()
{
}

BOOL CMFC41403View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41403View 绘制

void CMFC41403View::OnDraw(CDC* /*pDC*/)
{
	CMFC41403Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41403View 诊断

#ifdef _DEBUG
void CMFC41403View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41403View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41403Doc* CMFC41403View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41403Doc)));
	return (CMFC41403Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41403View 消息处理程序


void CMFC41403View::OnLButtonDblClk(UINT nFlags, CPoint point)
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


void CMFC41403View::OnOpendlg()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	dlg.bb = a;
	int r = dlg.DoModal();
	if (r == IDOK)
	{


	}
}
