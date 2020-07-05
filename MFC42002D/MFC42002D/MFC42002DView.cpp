
// MFC42002DView.cpp : CMFC42002DView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC42002D.h"
#endif

#include "MFC42002DDoc.h"
#include "MFC42002DView.h"
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002DView

IMPLEMENT_DYNCREATE(CMFC42002DView, CView)

BEGIN_MESSAGE_MAP(CMFC42002DView, CView)
	ON_COMMAND(ID_SHOWDLG, &CMFC42002DView::OnShowdlg)
END_MESSAGE_MAP()

// CMFC42002DView ����/����

CMFC42002DView::CMFC42002DView()
{
	// TODO: �ڴ˴���ӹ������

	crect.bottom = 600;
	crect.top = 100;
	crect.left = 100;
	crect.right = 500;


}

CMFC42002DView::~CMFC42002DView()
{
}

BOOL CMFC42002DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42002DView ����

void CMFC42002DView::OnDraw(CDC* /*pDC*/)
{
	CMFC42002DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	 


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC42002DView ���

#ifdef _DEBUG
void CMFC42002DView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002DDoc* CMFC42002DView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002DDoc)));
	return (CMFC42002DDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002DView ��Ϣ�������


void CMFC42002DView::OnShowdlg()
{
	// TODO: �ڴ���������������
	Dlg1 dlg;
	if (dlg.DoModal() == IDOK)
	{

		CClientDC dc(this);
		int a, b, c;
		a = dlg.A;
		b = dlg.B;
	    c = dlg.C;

		CBrush  newBrush(RGB(a, b, c));
		CBrush *oldBrush = dc.SelectObject(&newBrush);
		dc.Ellipse(crect);
		dc.SelectObject(oldBrush);
	
	
	
	
	}

}
