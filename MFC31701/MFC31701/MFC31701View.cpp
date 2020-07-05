
// MFC31701View.cpp : CMFC31701View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC31701.h"
#endif

#include "MFC31701Doc.h"
#include "MFC31701View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31701View

IMPLEMENT_DYNCREATE(CMFC31701View, CView)

BEGIN_MESSAGE_MAP(CMFC31701View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC31701View 构造/析构

CMFC31701View::CMFC31701View()
{
	// TODO: 在此处添加构造代码
	count = 0;

}

CMFC31701View::~CMFC31701View()
{
}

BOOL CMFC31701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC31701View 绘制

void CMFC31701View::OnDraw(CDC* /*pDC*/)
{
	CMFC31701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC31701View 诊断

#ifdef _DEBUG
void CMFC31701View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31701Doc* CMFC31701View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31701Doc)));
	return (CMFC31701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31701View 消息处理程序


void CMFC31701View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString K;
	set = true;
	a = point.x;
	b = point.y;
	K.Format(_T("点击：X=%d,Y=%d"), a, b);
	dc.TextOutW(20, 100, K);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC31701View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	count +=1;
	

	CView::OnMouseMove(nFlags, point);
}

void CMFC31701View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString A;
	CString P;
	CString O;
	c = point.x;
	d = point.y;
	distance = sqrt((a - c)*(a - c) + (b - d)*(b - d));

	P.Format(_T("抬起：X=%d,Y=%d"), c, d);
	dc.TextOutW(20, 200, P);
	O.Format(_T("距离=%d"), distance);
	dc.TextOutW(20, 300, O);

	m = (double)distance / count;

	A.Format(_T("次数=%d,平均像素=%.6f"), count,m );
	dc.TextOutW(200, 100, A);
	
	count = 0;

	CView::OnLButtonUp(nFlags, point);
}


