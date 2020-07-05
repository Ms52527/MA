
// MFC31702View.cpp : CMFC31702View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC31702.h"
#endif

#include "MFC31702Doc.h"
#include "MFC31702View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31702View

IMPLEMENT_DYNCREATE(CMFC31702View, CView)

BEGIN_MESSAGE_MAP(CMFC31702View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC31702View 构造/析构

CMFC31702View::CMFC31702View()
{
	// TODO: 在此处添加构造代码

}

CMFC31702View::~CMFC31702View()
{
}

BOOL CMFC31702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC31702View 绘制

void CMFC31702View::OnDraw(CDC* pDC)
{
	CMFC31702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: 在此处为本机数据添加绘制代码
	
	/*
	CRect CD;
	GetClientRect(&CD);

	pDoc->w = CD.Width()/2;
	pDoc->h = CD.Height()/2;

	pDoc->cr = CRect(pDoc->w- 50, pDoc->h - 50, pDoc->w+ 50, pDoc->h+ 50 );
	*/
	pDC->Rectangle(pDoc->cr);
}


// CMFC31702View 诊断

#ifdef _DEBUG
void CMFC31702View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31702Doc* CMFC31702View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31702Doc)));
	return (CMFC31702Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31702View 消息处理程序


void CMFC31702View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC31702Doc* pDoc = GetDocument();
	CRect ct;
	GetClientRect(&ct);
	CClientDC dc(this);
	switch (nChar)
	{
	case VK_UP:
	{
		if (pDoc->cr.top > 0)
			pDoc->cr.top -= 20;
		    pDoc->cr.bottom -= 20;
	}
	break;

	case VK_DOWN:
	{
		if (pDoc->cr.bottom<(ct.bottom- ct.top ))
			pDoc->cr.top += 20;
		    pDoc->cr.bottom += 20;
	}
	break;

	case VK_LEFT:
	{
		if (pDoc->cr.left > 0)
			pDoc->cr.left -= 20;
		    pDoc->cr.right -= 20;
	}
	break;

	case VK_RIGHT:
	{
		if (pDoc->cr.right <(ct.right  - ct.left))
			pDoc->cr.left += 20;
		    pDoc->cr.right += 20;
	}
	break;
	case VK_HOME:
	{
		if (pDoc->cr.left > 0 && pDoc->cr.top > 0)
			pDoc->cr.left -= 10;
		    pDoc->cr.top -= 10;
	}
	break;

	case VK_END:
	{
		if (pDoc->cr.right < (ct.right - ct.left)&& pDoc->cr.bottom<(ct.bottom - ct.top))
			pDoc->cr.top += 10;
		    pDoc->cr.left += 10;
	}
	break;
	}
	InvalidateRect(NULL,TRUE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}






void CMFC31702View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC31702Doc* pDoc = GetDocument();

	//pDoc->cr = CRect(pDoc->w - 50, pDoc->h - 50, pDoc->w + 50, pDoc->h + 50);
	pDoc->cr.bottom = 500;
	pDoc->cr.top = 300;
	pDoc->cr.right = 400;
	pDoc->cr.left = 600;

	InvalidateRect(NULL, TRUE);
	

	CView::OnLButtonDown(nFlags, point);
}
