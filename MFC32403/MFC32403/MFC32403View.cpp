
// MFC32403View.cpp : CMFC32403View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC32403.h"
#endif

#include "MFC32403Doc.h"
#include "MFC32403View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32403View

IMPLEMENT_DYNCREATE(CMFC32403View, CView)

BEGIN_MESSAGE_MAP(CMFC32403View, CView)
	ON_COMMAND(DrawLine, &CMFC32403View::OnDrawline)
	ON_COMMAND(DrawRectangle, &CMFC32403View::OnDrawrectangle)
	ON_COMMAND(DrawEllipse, &CMFC32403View::OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC32403View ����/����

CMFC32403View::CMFC32403View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC32403View::~CMFC32403View()
{
}

BOOL CMFC32403View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC32403View ����

void CMFC32403View::OnDraw(CDC* /*pDC*/)
{
	CMFC32403Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC32403View ���

#ifdef _DEBUG
void CMFC32403View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32403View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32403Doc* CMFC32403View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32403Doc)));
	return (CMFC32403Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32403View ��Ϣ�������


void CMFC32403View::OnDrawline()
{
	// TODO: �ڴ���������������
	a = 1;
	Invalidate();

}


void CMFC32403View::OnDrawrectangle()
{
	// TODO: �ڴ���������������
	a = 2;
	Invalidate();
}


void CMFC32403View::OnDrawellipse()
{
	// TODO: �ڴ���������������
	a = 3;
	Invalidate();
}



void CMFC32403View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	dx = point.x;
	dy = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CMFC32403View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ux = point.x;
	uy = point.y;
	CClientDC dc(this);
	CRect cd(dx, dy, ux, uy);

	if (a == 1)
	{
		dc.MoveTo(dx,dy);
		dc.LineTo(ux, uy);
	}
    if (a==2)
	{
		dc.Rectangle(cd);	
	}
	if (a==3)
	{
		dc.Ellipse(cd);

	}
	
	CView::OnLButtonUp(nFlags, point);
}
