
// MFC323View.cpp : CMFC323View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC323.h"
#endif

#include "MFC323Doc.h"
#include "MFC323View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC323View

IMPLEMENT_DYNCREATE(CMFC323View, CView)

BEGIN_MESSAGE_MAP(CMFC323View, CView)
	ON_COMMAND(ID_HUATU, &CMFC323View::OnHuatu)
END_MESSAGE_MAP()

// CMFC323View 构造/析构

CMFC323View::CMFC323View()
{
	// TODO: 在此处添加构造代码

}

CMFC323View::~CMFC323View()
{
}

BOOL CMFC323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC323View 绘制

void CMFC323View::OnDraw(CDC* /*pDC*/)
{
	CMFC323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC323View 诊断

#ifdef _DEBUG
void CMFC323View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC323Doc* CMFC323View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC323Doc)));
	return (CMFC323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC323View 消息处理程序


void CMFC323View::OnHuatu()

{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CRect cd;
	GetClientRect(&cd);
	CPoint A;
	A = cd.CenterPoint();
	int red = 0, green = 0, blue = 0;
	int width = 2;
	

	for (int i = 10; i >0; i--)
	{
		int color = RGB(red, green, blue);
		CPen newPen(PS_SOLID,width,color);
		CPen *oldPen = dc.SelectObject(&newPen);
		int r = i * 50;
		CRect cr(A.x - r, A.y - r, A.x + r, A.y + r);
		dc.Ellipse(cr);
		dc.SelectObject(oldPen);
		red += 92;
		green += 76;
		blue += 68;
		
	}
	
}
