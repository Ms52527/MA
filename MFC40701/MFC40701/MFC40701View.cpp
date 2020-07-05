
// MFC40701View.cpp : CMFC40701View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC40701.h"
#endif

#include "MFC40701Doc.h"
#include "MFC40701View.h"
#include"MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC40701View

IMPLEMENT_DYNCREATE(CMFC40701View, CView)

BEGIN_MESSAGE_MAP(CMFC40701View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC40701View::OnPopout)
END_MESSAGE_MAP()

// CMFC40701View 构造/析构

CMFC40701View::CMFC40701View()
{
	// TODO: 在此处添加构造代码

}

CMFC40701View::~CMFC40701View()
{
}

BOOL CMFC40701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC40701View 绘制

void CMFC40701View::OnDraw(CDC* /*pDC*/)
{
	CMFC40701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC40701View 诊断

#ifdef _DEBUG
void CMFC40701View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC40701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC40701Doc* CMFC40701View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC40701Doc)));
	return (CMFC40701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC40701View 消息处理程序


void CMFC40701View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString A ("你以退出对话框");

		GetDC()->TextOutW(100, 100, A);




	}

}
