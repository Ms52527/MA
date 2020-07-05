
// MFC50401View.cpp : CMFC50401View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC50401.h"
#endif

#include "MFC50401Doc.h"
#include "MFC50401View.h"
#include"阶乘.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMFC50401View

IMPLEMENT_DYNCREATE(CMFC50401View, CView)

BEGIN_MESSAGE_MAP(CMFC50401View, CView)
END_MESSAGE_MAP()

// CMFC50401View 构造/析构

CMFC50401View::CMFC50401View()
{
	// TODO: 在此处添加构造代码

}

CMFC50401View::~CMFC50401View()
{
}

BOOL CMFC50401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC50401View 绘制

void CMFC50401View::OnDraw(CDC* pDC)
{
	CMFC50401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S, SS;
	//S = CString(pchar());
	//pDC->TextOutW(200, 200, S);
	F2 b;
	S.Format(_T("%d 该数可以使用"), b.GetNum(pDoc->n));
	if (b.Factorial(pDoc->n) > 50000)
	{
		SS.Format(_T("该数过大已溢出"));
	}
	else
	{
		SS.Format(_T("该数阶乘的结果为：%d"), b.Factorial(pDoc->n));

	}
	pDC->TextOutW(300, 200, S);
	pDC->TextOutW(300, 300, SS);


	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC50401View 诊断

#ifdef _DEBUG
void CMFC50401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC50401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC50401Doc* CMFC50401View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC50401Doc)));
	return (CMFC50401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC50401View 消息处理程序
