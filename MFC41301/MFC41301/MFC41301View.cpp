
// MFC41301View.cpp : CMFC41301View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC41301.h"
#endif

#include "MFC41301Doc.h"
#include "MFC41301View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41301View

IMPLEMENT_DYNCREATE(CMFC41301View, CView)

BEGIN_MESSAGE_MAP(CMFC41301View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC41301View 构造/析构

CMFC41301View::CMFC41301View()
{
	// TODO: 在此处添加构造代码

	a = 0;
  
}

CMFC41301View::~CMFC41301View()
{
}

BOOL CMFC41301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41301View 绘制

void CMFC41301View::OnDraw(CDC* pDC)
{
	CMFC41301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

	

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41301View 诊断

#ifdef _DEBUG
void CMFC41301View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41301Doc* CMFC41301View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41301Doc)));
	return (CMFC41301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41301View 消息处理程序


void CMFC41301View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);
	re.left = 100;
	re.right = 500;
	re.top = 200;
	re.bottom = 400;
	
	if (point.x>100&&point.x<500&&point.y>200&&point.y<400)
	a = 1;

	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC41301View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	CRect A(point.x - 100, point.y - 200, point.x + 100, point.y + 200);
	dc.Rectangle(A);
	a = 0;
	
 


	CView::OnLButtonUp(nFlags, point);
}


void CMFC41301View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	if (a == 1) 
	{
		CClientDC dc(this);

		CRect A(point.x - 100, point.y - 200, point.x + 100, point.y + 200);
		dc.Rectangle(A);
		Invalidate();
	}

	

	CView::OnMouseMove(nFlags, point);
}


