
// MFC40702View.cpp : CMFC40702View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC40702.h"
#endif

#include "MFC40702Doc.h"
#include "MFC40702View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC40702View

IMPLEMENT_DYNCREATE(CMFC40702View, CView)

BEGIN_MESSAGE_MAP(CMFC40702View, CView)
	ON_COMMAND(ID_ONPUT, &CMFC40702View::OnOnput)
END_MESSAGE_MAP()

// CMFC40702View ����/����

CMFC40702View::CMFC40702View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC40702View::~CMFC40702View()
{
}

BOOL CMFC40702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC40702View ����

void CMFC40702View::OnDraw(CDC* /*pDC*/)
{
	CMFC40702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC40702View ���

#ifdef _DEBUG
void CMFC40702View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC40702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC40702Doc* CMFC40702View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC40702Doc)));
	return (CMFC40702Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC40702View ��Ϣ�������


void CMFC40702View::OnOnput()
{
	// TODO: �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{



	}

}
