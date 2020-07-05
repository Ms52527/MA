
// MFC42102View.cpp : CMFC42102View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC42102View ����/����

CMFC42102View::CMFC42102View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42102View::~CMFC42102View()
{
}

BOOL CMFC42102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42102View ����

void CMFC42102View::OnDraw(CDC* pDC)
{
	CMFC42102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString a;
	a = _T("�����������ͼ��ʾͼƬ����ѡ�Ŵ����ļ�·�����ı�������ʾͼƬ");
	pDC->TextOutW(300, 300, a);
}


// CMFC42102View ���

#ifdef _DEBUG
void CMFC42102View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42102Doc* CMFC42102View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42102Doc)));
	return (CMFC42102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42102View ��Ϣ�������


void CMFC42102View::OnFileOpen()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������


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
	// TODO: �ڴ���������������


	CFileDialog cfd(false);  //��������
	int r = cfd.DoModal();  //�����Ի���
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
	// TODO: �ڴ���������������

	Dlg1 afa;
	int r = afa.DoModal();
	if (r = IDOK)
	{
		


	}
	

}
