
// MFC42002AView.cpp : CMFC42002AView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42002A.h"
#endif

#include "MFC42002ADoc.h"
#include "MFC42002AView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002AView

IMPLEMENT_DYNCREATE(CMFC42002AView, CView)

BEGIN_MESSAGE_MAP(CMFC42002AView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC42002AView 构造/析构

CMFC42002AView::CMFC42002AView()
{
	// TODO: 在此处添加构造代码

}

CMFC42002AView::~CMFC42002AView()
{
}

BOOL CMFC42002AView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42002AView 绘制

void CMFC42002AView::OnDraw(CDC* pDC)
{
	CMFC42002ADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(A);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC42002AView 诊断

#ifdef _DEBUG
void CMFC42002AView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002AView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002ADoc* CMFC42002AView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002ADoc)));
	return (CMFC42002ADoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002AView 消息处理程序


void CMFC42002AView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	X1 = point.x;
	Y1 = point.y;
	flag = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC42002AView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	X2 = point.x;
	Y2 = point.y;
	A.left = X1;
	A.top = Y1;
	A.right = X2;
	A.bottom = Y2;
	Invalidate();
	flag = 0;



	CView::OnLButtonUp(nFlags, point);
}


void CMFC42002AView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) {
		X2 = point.x;
		Y2 = point.y;
		A.left = X1;
		A.top = Y1;
		A.right = X2;
		A.bottom = Y2;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
