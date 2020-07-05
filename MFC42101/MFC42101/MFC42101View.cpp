
// MFC42101View.cpp : CMFC42101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC42101View ����/����

CMFC42101View::CMFC42101View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42101View::~CMFC42101View()
{
}

BOOL CMFC42101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42101View ����

void CMFC42101View::OnDraw(CDC* pDC)
{
	CMFC42101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString JJ;
	JJ = _T("���������л������Ϊ���ļ���д");
	pDC->TextOutW(100, 100, JJ);


	pDC->TextOutW(200, 200, pDoc->s);
}


// CMFC42101View ���

#ifdef _DEBUG
void CMFC42101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42101Doc* CMFC42101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42101Doc)));
	return (CMFC42101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42101View ��Ϣ�������


void CMFC42101View::OnFileOpen()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������


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
