
// MFC42001View.cpp : CMFC42001View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42001.h"
#endif

#include "MFC42001Doc.h"
#include "MFC42001View.h"
#include "MyDlog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42001View

IMPLEMENT_DYNCREATE(CMFC42001View, CView)

BEGIN_MESSAGE_MAP(CMFC42001View, CView)
	ON_COMMAND(ID_OPEN, &CMFC42001View::OnOpen)
END_MESSAGE_MAP()

// CMFC42001View 构造/析构

CMFC42001View::CMFC42001View()
{
	// TODO: 在此处添加构造代码

}

CMFC42001View::~CMFC42001View()
{
}

BOOL CMFC42001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42001View 绘制

void CMFC42001View::OnDraw(CDC* pDC)
{
	CMFC42001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s = _T("点击工具栏视图打开计算器");
	pDC->TextOutW(100,100,s);


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC42001View 诊断

#ifdef _DEBUG
void CMFC42001View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42001Doc* CMFC42001View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42001Doc)));
	return (CMFC42001Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42001View 消息处理程序


void CMFC42001View::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	MyDlog dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}

}
