
// MFC42002CView.cpp : CMFC42002CView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC42002C.h"
#endif

#include "MFC42002CDoc.h"
#include "MFC42002CView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002CView

IMPLEMENT_DYNCREATE(CMFC42002CView, CView)

BEGIN_MESSAGE_MAP(CMFC42002CView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC42002CView ����/����

CMFC42002CView::CMFC42002CView()
{
	// TODO: �ڴ˴���ӹ������

	A.bottom = 600;
	A.top = 100;
	A.left = 100;
	A.right = 500;

}

CMFC42002CView::~CMFC42002CView()
{
}

BOOL CMFC42002CView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42002CView ����

void CMFC42002CView::OnDraw(CDC* pDC)
{
	CMFC42002CDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Ellipse(A);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC42002CView ���

#ifdef _DEBUG
void CMFC42002CView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002CView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002CDoc* CMFC42002CView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002CDoc)));
	return (CMFC42002CDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002CView ��Ϣ�������


void CMFC42002CView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (point.x > 100 && point.x < 500 && point.y>100 && point.y < 600)
	{
		CClientDC dc(this);
		CPen *oldpen;
		CPen	newpen;


		newpen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));


		oldpen = dc.SelectObject(&newpen);
		CRect B(100, 100, 500, 600);
		dc.Rectangle(B);
		dc.SelectObject(oldpen);
		GetDC()->Ellipse(A);


	}



	CView::OnMButtonDown(nFlags, point);
}
