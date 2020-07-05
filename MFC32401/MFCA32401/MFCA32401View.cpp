
// MFCA32401View.cpp : CMFCA32401View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA32401.h"
#endif

#include "MFCA32401Doc.h"
#include "MFCA32401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA32401View

IMPLEMENT_DYNCREATE(CMFCA32401View, CView)

BEGIN_MESSAGE_MAP(CMFCA32401View, CView)
	ON_COMMAND(SHOWNAME, &CMFCA32401View::OnShowname)
END_MESSAGE_MAP()

// CMFCA32401View 构造/析构

CMFCA32401View::CMFCA32401View()
{
	// TODO: 在此处添加构造代码

}

CMFCA32401View::~CMFCA32401View()
{
}

BOOL CMFCA32401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA32401View 绘制

void CMFCA32401View::OnDraw(CDC* /*pDC*/)
{
	CMFCA32401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA32401View 诊断

#ifdef _DEBUG
void CMFCA32401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA32401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA32401Doc* CMFCA32401View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA32401Doc)));
	return (CMFCA32401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA32401View 消息处理程序


void CMFCA32401View::OnShowname()
{

	// TODO: 在此添加命令处理程序代码

	CClientDC dc(this);
	CString a;
	a = _T("麻文燊");
	dc.TextOutW(100, 200, a);
}
