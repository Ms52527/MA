
// MFC42002CView.cpp : CMFC42002CView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42002C.h"
#endif

#include "MFC42002CDoc.h"
#include "MFC42002CView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002CView

IMPLEMENT_DYNCREATE(CMFC42002CView, CView)

BEGIN_MESSAGE_MAP(CMFC42002CView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC42002CView 构造/析构

CMFC42002CView::CMFC42002CView()
{
	// TODO: 在此处添加构造代码

	A.bottom = 600;
	A.top = 100;
	A.left = 100;
	A.right = 500;

}

CMFC42002CView::~CMFC42002CView()
{
}

BOOL CMFC42002CView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42002CView 绘制

void CMFC42002CView::OnDraw(CDC* pDC)
{
	CMFC42002CDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Ellipse(A);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC42002CView 诊断

#ifdef _DEBUG
void CMFC42002CView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002CView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002CDoc* CMFC42002CView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002CDoc)));
	return (CMFC42002CDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002CView 消息处理程序


void CMFC42002CView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (point.x > 100 && point.x < 500 && point.y>100 && point.y < 600)
	{
		CClientDC dc(this);
		CPen *oldpen;
		CPen	newpen;


		newpen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));


		oldpen = dc.SelectObject(&newpen);
		CRect B(100, 100, 500, 600);
		dc.Rectangle(B);
		dc.SelectObject(oldpen);
		GetDC()->Ellipse(A);


	}



	CView::OnMButtonDown(nFlags, point);
}
