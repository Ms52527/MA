
// MFCUsingWinLIBDLLView.cpp : CMFCUsingWinLIBDLLView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCUsingWinLIBDLL.h"
#endif

#include "MFCUsingWinLIBDLLDoc.h"
#include "MFCUsingWinLIBDLLView.h"
#include"W32.h"
#include"W32D.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCUsingWinLIBDLLView

IMPLEMENT_DYNCREATE(CMFCUsingWinLIBDLLView, CView)

BEGIN_MESSAGE_MAP(CMFCUsingWinLIBDLLView, CView)
END_MESSAGE_MAP()

// CMFCUsingWinLIBDLLView 构造/析构

CMFCUsingWinLIBDLLView::CMFCUsingWinLIBDLLView()
{
	// TODO: 在此处添加构造代码

}

CMFCUsingWinLIBDLLView::~CMFCUsingWinLIBDLLView()
{
}

BOOL CMFCUsingWinLIBDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCUsingWinLIBDLLView 绘制

void CMFCUsingWinLIBDLLView::OnDraw(CDC* pDC)
{
	CMFCUsingWinLIBDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s = CString(pchar());
	pDC->TextOutW(100, 100, s);

	CString ss;

	ss.Format(_T("这个是从动态链接库返回的值：%d"),GetInt());
	pDC->TextOutW(200, 200, ss);
}


// CMFCUsingWinLIBDLLView 诊断

#ifdef _DEBUG
void CMFCUsingWinLIBDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCUsingWinLIBDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCUsingWinLIBDLLDoc* CMFCUsingWinLIBDLLView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCUsingWinLIBDLLDoc)));
	return (CMFCUsingWinLIBDLLDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCUsingWinLIBDLLView 消息处理程序
