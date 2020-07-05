
// MFC41401View.cpp : CMFC41401View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC41401.h"
#endif

#include "MFC41401Doc.h"
#include "MFC41401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41401View

IMPLEMENT_DYNCREATE(CMFC41401View, CView)

BEGIN_MESSAGE_MAP(CMFC41401View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC41401View 构造/析构

CMFC41401View::CMFC41401View()
{
	// TODO: 在此处添加构造代码

}

CMFC41401View::~CMFC41401View()
{
}

BOOL CMFC41401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41401View 绘制

void CMFC41401View::OnDraw(CDC* /*pDC*/)
{
	CMFC41401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41401View 诊断

#ifdef _DEBUG
void CMFC41401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41401Doc* CMFC41401View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41401Doc)));
	return (CMFC41401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41401View 消息处理程序


void CMFC41401View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		
		GetDC()->TextOutW(100, 100, filename);

	}


	CView::OnLButtonDblClk(nFlags, point);
}
