
// MFC31703View.cpp : CMFC31703View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC31703.h"
#endif

#include "MFC31703Doc.h"
#include "MFC31703View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31703View

IMPLEMENT_DYNCREATE(CMFC31703View, CView)

BEGIN_MESSAGE_MAP(CMFC31703View, CView)
END_MESSAGE_MAP()

// CMFC31703View 构造/析构

CMFC31703View::CMFC31703View()
{
	// TODO: 在此处添加构造代码

}

CMFC31703View::~CMFC31703View()
{
}

BOOL CMFC31703View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC31703View 绘制

void CMFC31703View::OnDraw(CDC* /*pDC*/)
{
	CMFC31703Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC31703View 诊断

#ifdef _DEBUG
void CMFC31703View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31703View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31703Doc* CMFC31703View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31703Doc)));
	return (CMFC31703Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31703View 消息处理程序
