
// MFC41304View.cpp : CMFC41304View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC41304.h"
#endif

#include "MFC41304Doc.h"
#include "MFC41304View.h"
#include "DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41304View

IMPLEMENT_DYNCREATE(CMFC41304View, CView)

BEGIN_MESSAGE_MAP(CMFC41304View, CView)
	ON_COMMAND(ID_OPEN, &CMFC41304View::OnOpen)
END_MESSAGE_MAP()

// CMFC41304View 构造/析构

CMFC41304View::CMFC41304View()
{
	// TODO: 在此处添加构造代码

}

CMFC41304View::~CMFC41304View()
{
}

BOOL CMFC41304View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41304View 绘制

void CMFC41304View::OnDraw(CDC* /*pDC*/)
{
	CMFC41304Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41304View 诊断

#ifdef _DEBUG
void CMFC41304View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41304View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41304Doc* CMFC41304View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41304Doc)));
	return (CMFC41304Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41304View 消息处理程序


void CMFC41304View::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	DLG dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
