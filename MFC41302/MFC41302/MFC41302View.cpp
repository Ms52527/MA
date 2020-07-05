
// MFC41302View.cpp : CMFC41302View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC41302.h"
#endif

#include "MFC41302Doc.h"
#include "MFC41302View.h"
#include "DLGADD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41302View

IMPLEMENT_DYNCREATE(CMFC41302View, CView)

BEGIN_MESSAGE_MAP(CMFC41302View, CView)
	ON_COMMAND(ID_OPEN, &CMFC41302View::OnOpen)
END_MESSAGE_MAP()

// CMFC41302View 构造/析构

CMFC41302View::CMFC41302View()
{
	// TODO: 在此处添加构造代码

}

CMFC41302View::~CMFC41302View()
{
}

BOOL CMFC41302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41302View 绘制

void CMFC41302View::OnDraw(CDC* pDC)
{
	CMFC41302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s = _T("点击工具栏视图打开计算器");
	pDC->TextOutW(100, 100, s);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41302View 诊断

#ifdef _DEBUG
void CMFC41302View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41302Doc* CMFC41302View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41302Doc)));
	return (CMFC41302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41302View 消息处理程序


void CMFC41302View::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	DLGADD dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
