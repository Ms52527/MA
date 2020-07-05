
// MFC0View.cpp : CMFC0View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC0.h"
#endif

#include "MFC0Doc.h"
#include "MFC0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC0View

IMPLEMENT_DYNCREATE(CMFC0View, CView)

BEGIN_MESSAGE_MAP(CMFC0View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC0View 构造/析构

CMFC0View::CMFC0View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);

	}
}

CMFC0View::~CMFC0View()
{
}

BOOL CMFC0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC0View 绘制

void CMFC0View::OnDraw(CDC* pDC)
{
	CMFC0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
			
			set = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);

	}
	
	for (int i = 0; i < N; i++)
	{
		if (tim[i])
			SetTimer(i+5, rand() % 200 + 100, NULL);
	}
	
}


// CMFC0View 诊断

#ifdef _DEBUG
void CMFC0View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC0Doc* CMFC0View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC0Doc)));
	return (CMFC0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC0View 消息处理程序


void CMFC0View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect cd;
	GetClientRect(&cd);


	for (int i = 0; i < N; i++)
	{
		if (nIDEvent == i)
		{
			cr[i].top += 10;
			cr[i].bottom += 10;
		}

		if (cr[i].bottom >= (cd.bottom - cd.top))
		{
		    KillTimer(i);
			tim[i] = 1;
			
		}

	}
	
	for (int i = 0; i < N; i++)
	{

		if (nIDEvent == i + 5)
		{
			cr[i].top -= 10;
			cr[i].bottom -= 10;
		}
	}
	
		Invalidate();
	
	CView::OnTimer(nIDEvent);
}
