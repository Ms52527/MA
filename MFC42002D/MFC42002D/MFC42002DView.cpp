
// MFC42002DView.cpp : CMFC42002DView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42002D.h"
#endif

#include "MFC42002DDoc.h"
#include "MFC42002DView.h"
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002DView

IMPLEMENT_DYNCREATE(CMFC42002DView, CView)

BEGIN_MESSAGE_MAP(CMFC42002DView, CView)
	ON_COMMAND(ID_SHOWDLG, &CMFC42002DView::OnShowdlg)
END_MESSAGE_MAP()

// CMFC42002DView 构造/析构

CMFC42002DView::CMFC42002DView()
{
	// TODO: 在此处添加构造代码

	crect.bottom = 600;
	crect.top = 100;
	crect.left = 100;
	crect.right = 500;


}

CMFC42002DView::~CMFC42002DView()
{
}

BOOL CMFC42002DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42002DView 绘制

void CMFC42002DView::OnDraw(CDC* /*pDC*/)
{
	CMFC42002DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	 


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC42002DView 诊断

#ifdef _DEBUG
void CMFC42002DView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002DDoc* CMFC42002DView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002DDoc)));
	return (CMFC42002DDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002DView 消息处理程序


void CMFC42002DView::OnShowdlg()
{
	// TODO: 在此添加命令处理程序代码
	Dlg1 dlg;
	if (dlg.DoModal() == IDOK)
	{

		CClientDC dc(this);
		int a, b, c;
		a = dlg.A;
		b = dlg.B;
	    c = dlg.C;

		CBrush  newBrush(RGB(a, b, c));
		CBrush *oldBrush = dc.SelectObject(&newBrush);
		dc.Ellipse(crect);
		dc.SelectObject(oldBrush);
	
	
	
	
	}

}
