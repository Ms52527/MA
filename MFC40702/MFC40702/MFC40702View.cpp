
// MFC40702View.cpp : CMFC40702View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC40702.h"
#endif

#include "MFC40702Doc.h"
#include "MFC40702View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC40702View

IMPLEMENT_DYNCREATE(CMFC40702View, CView)

BEGIN_MESSAGE_MAP(CMFC40702View, CView)
	ON_COMMAND(ID_ONPUT, &CMFC40702View::OnOnput)
END_MESSAGE_MAP()

// CMFC40702View 构造/析构

CMFC40702View::CMFC40702View()
{
	// TODO: 在此处添加构造代码

}

CMFC40702View::~CMFC40702View()
{
}

BOOL CMFC40702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC40702View 绘制

void CMFC40702View::OnDraw(CDC* /*pDC*/)
{
	CMFC40702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC40702View 诊断

#ifdef _DEBUG
void CMFC40702View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC40702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC40702Doc* CMFC40702View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC40702Doc)));
	return (CMFC40702Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC40702View 消息处理程序


void CMFC40702View::OnOnput()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{



	}

}
