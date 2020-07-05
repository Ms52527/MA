
// MFC42002BView.cpp : CMFC42002BView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC42002B.h"
#endif

#include "MFC42002BDoc.h"
#include "MFC42002BView.h"
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002BView

IMPLEMENT_DYNCREATE(CMFC42002BView, CView)

BEGIN_MESSAGE_MAP(CMFC42002BView, CView)
	ON_COMMAND(ID_SHOWDLG, &CMFC42002BView::OnShowdlg)
END_MESSAGE_MAP()

// CMFC42002BView ����/����

CMFC42002BView::CMFC42002BView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42002BView::~CMFC42002BView()
{
}

BOOL CMFC42002BView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42002BView ����

void CMFC42002BView::OnDraw(CDC* /*pDC*/)
{
	CMFC42002BDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC42002BView ���

#ifdef _DEBUG
void CMFC42002BView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002BView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002BDoc* CMFC42002BView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002BDoc)));
	return (CMFC42002BDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002BView ��Ϣ�������


void CMFC42002BView::OnShowdlg()
{
	// TODO: �ڴ���������������

	Dlg1 dlg;
	if (dlg.DoModal() == IDOK)
	{
		CClientDC dc(this);

		A.top = dlg.top;
		A.bottom = dlg.bottom;
		A.right = dlg.right;
		A.left = dlg.left;


		dc.Ellipse(A);

	}


}
