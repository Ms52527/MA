
// MFC41301View.cpp : CMFC41301View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC41301.h"
#endif

#include "MFC41301Doc.h"
#include "MFC41301View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41301View

IMPLEMENT_DYNCREATE(CMFC41301View, CView)

BEGIN_MESSAGE_MAP(CMFC41301View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC41301View ����/����

CMFC41301View::CMFC41301View()
{
	// TODO: �ڴ˴���ӹ������

	a = 0;
  
}

CMFC41301View::~CMFC41301View()
{
}

BOOL CMFC41301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41301View ����

void CMFC41301View::OnDraw(CDC* pDC)
{
	CMFC41301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC41301View ���

#ifdef _DEBUG
void CMFC41301View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41301Doc* CMFC41301View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41301Doc)));
	return (CMFC41301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41301View ��Ϣ�������


void CMFC41301View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CClientDC dc(this);
	re.left = 100;
	re.right = 500;
	re.top = 200;
	re.bottom = 400;
	
	if (point.x>100&&point.x<500&&point.y>200&&point.y<400)
	a = 1;

	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC41301View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);

	CRect A(point.x - 100, point.y - 200, point.x + 100, point.y + 200);
	dc.Rectangle(A);
	a = 0;
	
 


	CView::OnLButtonUp(nFlags, point);
}


void CMFC41301View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	if (a == 1) 
	{
		CClientDC dc(this);

		CRect A(point.x - 100, point.y - 200, point.x + 100, point.y + 200);
		dc.Rectangle(A);
		Invalidate();
	}

	

	CView::OnMouseMove(nFlags, point);
}


