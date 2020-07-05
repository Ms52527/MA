
// MFC42002BView.cpp : CMFC42002BView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42002B.h"
#endif

#include "MFC42002BDoc.h"
#include "MFC42002BView.h"
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002BView

IMPLEMENT_DYNCREATE(CMFC42002BView, CView)

BEGIN_MESSAGE_MAP(CMFC42002BView, CView)
	ON_COMMAND(ID_SHOWDLG, &CMFC42002BView::OnShowdlg)
END_MESSAGE_MAP()

// CMFC42002BView 构造/析构

CMFC42002BView::CMFC42002BView()
{
	// TODO: 在此处添加构造代码

}

CMFC42002BView::~CMFC42002BView()
{
}

BOOL CMFC42002BView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42002BView 绘制

void CMFC42002BView::OnDraw(CDC* /*pDC*/)
{
	CMFC42002BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC42002BView 诊断

#ifdef _DEBUG
void CMFC42002BView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002BView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002BDoc* CMFC42002BView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002BDoc)));
	return (CMFC42002BDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002BView 消息处理程序


void CMFC42002BView::OnShowdlg()
{
	// TODO: 在此添加命令处理程序代码

	Dlg1 dlg;
	if (dlg.DoModal() == IDOK)
	{
		CClientDC dc(this);

		A.top = dlg.top;
		A.bottom = dlg.bottom;
		A.right = dlg.right;
		A.left = dlg.left;


		dc.Ellipse(A);

	}


}
