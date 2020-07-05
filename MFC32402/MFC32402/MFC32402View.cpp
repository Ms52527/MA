
// MFC32402View.cpp : CMFC32402View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC32402.h"
#endif

#include "MFC32402Doc.h"
#include "MFC32402View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32402View

IMPLEMENT_DYNCREATE(CMFC32402View, CView)

BEGIN_MESSAGE_MAP(CMFC32402View, CView)
END_MESSAGE_MAP()

// CMFC32402View 构造/析构

CMFC32402View::CMFC32402View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CMFC32402View::~CMFC32402View()
{
}

BOOL CMFC32402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC32402View 绘制

void CMFC32402View::OnDraw(CDC* pDC)
{
	CMFC32402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// CMFC32402View 诊断

#ifdef _DEBUG
void CMFC32402View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32402Doc* CMFC32402View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32402Doc)));
	return (CMFC32402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32402View 消息处理程序
