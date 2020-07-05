
// MFC42002AView.cpp : CMFC42002AView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC42002A.h"
#endif

#include "MFC42002ADoc.h"
#include "MFC42002AView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42002AView

IMPLEMENT_DYNCREATE(CMFC42002AView, CView)

BEGIN_MESSAGE_MAP(CMFC42002AView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC42002AView ����/����

CMFC42002AView::CMFC42002AView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42002AView::~CMFC42002AView()
{
}

BOOL CMFC42002AView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42002AView ����

void CMFC42002AView::OnDraw(CDC* pDC)
{
	CMFC42002ADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(A);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC42002AView ���

#ifdef _DEBUG
void CMFC42002AView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42002AView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42002ADoc* CMFC42002AView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42002ADoc)));
	return (CMFC42002ADoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42002AView ��Ϣ�������


void CMFC42002AView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	X1 = point.x;
	Y1 = point.y;
	flag = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC42002AView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	X2 = point.x;
	Y2 = point.y;
	A.left = X1;
	A.top = Y1;
	A.right = X2;
	A.bottom = Y2;
	Invalidate();
	flag = 0;



	CView::OnLButtonUp(nFlags, point);
}


void CMFC42002AView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) {
		X2 = point.x;
		Y2 = point.y;
		A.left = X1;
		A.top = Y1;
		A.right = X2;
		A.bottom = Y2;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
