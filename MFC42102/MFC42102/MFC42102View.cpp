
// MFC42102View.cpp : CMFC42102View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC42102.h"
#endif

#include "MFC42102Doc.h"
#include "MFC42102View.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42102View

IMPLEMENT_DYNCREATE(CMFC42102View, CView)

BEGIN_MESSAGE_MAP(CMFC42102View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC42102View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMFC42102View::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFC42102View::OnFileSaveAs)
	ON_COMMAND(ID_OPENPIC, &CMFC42102View::OnOpenpic)
END_MESSAGE_MAP()

// CMFC42102View 构造/析构

CMFC42102View::CMFC42102View()
{
	// TODO: 在此处添加构造代码

}

CMFC42102View::~CMFC42102View()
{
}

BOOL CMFC42102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC42102View 绘制

void CMFC42102View::OnDraw(CDC* pDC)
{
	CMFC42102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString a;
	a = _T("点击工具栏视图显示图片可以选着存有文件路径的文本进行显示图片");
	pDC->TextOutW(300, 300, a);
}


// CMFC42102View 诊断

#ifdef _DEBUG
void CMFC42102View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42102Doc* CMFC42102View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42102Doc)));
	return (CMFC42102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42102View 消息处理程序


void CMFC42102View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	Dlg1 ADA;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		B = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		
		CClientDC dc(this);
		int y=10;
		while (ifs >> s) 
		{
			dc.TextOutW(20, y, CString(s.c_str()));
			y += 30;

			 ADA.C = CString(s.c_str());

		}



	
	}
}


void CMFC42102View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码


	CFileDialog cfd(false);  
	int r = cfd.DoModal(); 
	CClientDC dc(this);
	if (r == IDOK)                  

	{
		ofstream ofs(cfd.GetPathName());
		CString s = B;
		ofs << CT2A(s.GetString()) << endl;
	}

}


void CMFC42102View::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码


	CFileDialog cfd(false);  //建立对象
	int r = cfd.DoModal();  //弹出对话框
	CClientDC dc(this);
	if (r == IDOK)                

	{
		ofstream ofs(cfd.GetPathName());
		CString s = cfd.GetPathName();
		ofs << CT2A(s.GetString()) << endl;

	}

}


void CMFC42102View::OnOpenpic()
{
	// TODO: 在此添加命令处理程序代码

	Dlg1 afa;
	int r = afa.DoModal();
	if (r = IDOK)
	{
		


	}
	

}
