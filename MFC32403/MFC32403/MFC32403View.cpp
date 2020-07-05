
// MFC32403View.cpp : CMFC32403View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC32403.h"
#endif

#include "MFC32403Doc.h"
#include "MFC32403View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32403View

IMPLEMENT_DYNCREATE(CMFC32403View, CView)

BEGIN_MESSAGE_MAP(CMFC32403View, CView)
	ON_COMMAND(DrawLine, &CMFC32403View::OnDrawline)
	ON_COMMAND(DrawRectangle, &CMFC32403View::OnDrawrectangle)
	ON_COMMAND(DrawEllipse, &CMFC32403View::OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC32403View 构造/析构

CMFC32403View::CMFC32403View()
{
	// TODO: 在此处添加构造代码

}

CMFC32403View::~CMFC32403View()
{
}

BOOL CMFC32403View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC32403View 绘制

void CMFC32403View::OnDraw(CDC* /*pDC*/)
{
	CMFC32403Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC32403View 诊断

#ifdef _DEBUG
void CMFC32403View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32403View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32403Doc* CMFC32403View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32403Doc)));
	return (CMFC32403Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32403View 消息处理程序


void CMFC32403View::OnDrawline()
{
	// TODO: 在此添加命令处理程序代码
	a = 1;
	Invalidate();

}


void CMFC32403View::OnDrawrectangle()
{
	// TODO: 在此添加命令处理程序代码
	a = 2;
	Invalidate();
}


void CMFC32403View::OnDrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	a = 3;
	Invalidate();
}



void CMFC32403View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	dx = point.x;
	dy = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CMFC32403View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ux = point.x;
	uy = point.y;
	CClientDC dc(this);
	CRect cd(dx, dy, ux, uy);

	if (a == 1)
	{
		dc.MoveTo(dx,dy);
		dc.LineTo(ux, uy);
	}
    if (a==2)
	{
		dc.Rectangle(cd);	
	}
	if (a==3)
	{
		dc.Ellipse(cd);

	}
	
	CView::OnLButtonUp(nFlags, point);
}
