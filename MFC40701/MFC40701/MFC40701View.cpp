
// MFC40701View.cpp : CMFC40701View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC40701.h"
#endif

#include "MFC40701Doc.h"
#include "MFC40701View.h"
#include"MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC40701View

IMPLEMENT_DYNCREATE(CMFC40701View, CView)

BEGIN_MESSAGE_MAP(CMFC40701View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC40701View::OnPopout)
END_MESSAGE_MAP()

// CMFC40701View ����/����

CMFC40701View::CMFC40701View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC40701View::~CMFC40701View()
{
}

BOOL CMFC40701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC40701View ����

void CMFC40701View::OnDraw(CDC* /*pDC*/)
{
	CMFC40701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC40701View ���

#ifdef _DEBUG
void CMFC40701View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC40701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC40701Doc* CMFC40701View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC40701Doc)));
	return (CMFC40701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC40701View ��Ϣ�������


void CMFC40701View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString A ("�����˳��Ի���");

		GetDC()->TextOutW(100, 100, A);




	}

}
