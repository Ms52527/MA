
// MFCApplication5View.cpp : CMFCApplication5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCApplication5View 构造/析构

CMFCApplication5View::CMFCApplication5View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5View 绘制

void CMFCApplication5View::OnDraw(CDC* pDC)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(pDoc->cr1);
	pDC->Rectangle(pDoc->cr2);
	pDC->Rectangle(pDoc->cr3);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication5View 诊断

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View 消息处理程序


void CMFCApplication5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CClientDC dc(this);
;
	CString A,B,C,D;

	D= _T("点击无效");

	if (point.x > 100 && point.x < 200 && point.y>200 && point.y < 300)
	{
		pDoc->a = rand() % 50 + 5;
		A.Format(_T("a=%d"), pDoc->a);
		dc.TextOutW(150, 250, A);
		
	}
	else
		if (point.x > 400 && point.x < 500 && point.y>400 && point.y < 600)
		{
			pDoc->b = rand() % 50 + 5;
			B.Format(_T("b=%d"), pDoc->b);
			dc.TextOutW(450, 500, B);
		
		}
		else
			if (point.x > 100 && point.x < 250 && point.y>400 && point.y < 500 )
			{
				pDoc->c = pDoc->a + pDoc->b;
				C.Format(_T("a+b=%d"), pDoc->c);
				dc.TextOutW(150, 450, C);
			

			}
			else
				dc.TextOutW(500,300, D);

		
		
	

	CView::OnLButtonDown(nFlags, point);
}


