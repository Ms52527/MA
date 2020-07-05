
// MFC42101View.cpp : CMFC42101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42101.h"
#endif

#include "MFC42101Doc.h"
#include "MFC42101View.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42101View

IMPLEMENT_DYNCREATE(CMFC42101View, CView)

BEGIN_MESSAGE_MAP(CMFC42101View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC42101View::OnFileOpen)
	
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFC42101View::OnFileSaveAs)
END_MESSAGE_MAP()

// CMFC42101View 构造/析构

CMFC42101View::CMFC42101View()
{
	// TODO: 在此处添加构造代码

}

CMFC42101View::~CMFC42101View()
{
}

BOOL CMFC42101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42101View 绘制

void CMFC42101View::OnDraw(CDC* pDC)
{
	CMFC42101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString JJ;
	JJ = _T("保存是序列化，另存为是文件读写");
	pDC->TextOutW(100, 100, JJ);


	pDC->TextOutW(200, 200, pDoc->s);
}


// CMFC42101View 诊断

#ifdef _DEBUG
void CMFC42101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42101Doc* CMFC42101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42101Doc)));
	return (CMFC42101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42101View 消息处理程序


void CMFC42101View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CMFC42101Doc* pDoc = GetDocument();

	CFileDialog cfd (true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();

		GetDC()->TextOutW(100,100,filename);

		pDoc->s = filename;

	}
}




void CMFC42101View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码


	CMFC42101Doc* pDoc = GetDocument();
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)

	{
		ofstream ofs(cfd.GetPathName());
		CString s = pDoc->s;
		ofs << CT2A(s.GetString()) << endl;
	}
}
