
// MFCApplication6（3.16实验）View.cpp : CMFCApplication6（316实验）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication6（3.16实验）.h"
#endif

#include "MFCApplication6（3.16实验）Doc.h"
#include "MFCApplication6（3.16实验）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6（316实验）View

IMPLEMENT_DYNCREATE(CMFCApplication6（316实验）View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6（316实验）View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication6（316实验）View 构造/析构

CMFCApplication6（316实验）View::CMFCApplication6（316实验）View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication6（316实验）View::~CMFCApplication6（316实验）View()
{
}

BOOL CMFCApplication6（316实验）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6（316实验）View 绘制

void CMFCApplication6（316实验）View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication6（316实验）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

}


// CMFCApplication6（316实验）View 诊断

#ifdef _DEBUG
void CMFCApplication6（316实验）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6（316实验）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6（316实验）Doc* CMFCApplication6（316实验）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6（316实验）Doc)));
	return (CMFCApplication6（316实验）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6（316实验）View 消息处理程序


void CMFCApplication6（316实验）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	a = point.x;
	b = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication6（316实验）View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	c = point.x;
	d = point.y;
	CClientDC dc(this);
	CRect cr(a,b,c,d);

	dc.Rectangle(cr);


	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication6（316实验）View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	CString A;
	A.Format(_T("X=%d,Y=%d"), point.x, point.y);
	dc.TextOutW(100, 100, A);

	CView::OnMouseMove(nFlags, point);
}
