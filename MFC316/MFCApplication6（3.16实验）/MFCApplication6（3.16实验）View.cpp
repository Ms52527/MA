
// MFCApplication6��3.16ʵ�飩View.cpp : CMFCApplication6��316ʵ�飩View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication6��3.16ʵ�飩.h"
#endif

#include "MFCApplication6��3.16ʵ�飩Doc.h"
#include "MFCApplication6��3.16ʵ�飩View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6��316ʵ�飩View

IMPLEMENT_DYNCREATE(CMFCApplication6��316ʵ�飩View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6��316ʵ�飩View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication6��316ʵ�飩View ����/����

CMFCApplication6��316ʵ�飩View::CMFCApplication6��316ʵ�飩View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication6��316ʵ�飩View::~CMFCApplication6��316ʵ�飩View()
{
}

BOOL CMFCApplication6��316ʵ�飩View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6��316ʵ�飩View ����

void CMFCApplication6��316ʵ�飩View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication6��316ʵ�飩Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// CMFCApplication6��316ʵ�飩View ���

#ifdef _DEBUG
void CMFCApplication6��316ʵ�飩View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6��316ʵ�飩View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6��316ʵ�飩Doc* CMFCApplication6��316ʵ�飩View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6��316ʵ�飩Doc)));
	return (CMFCApplication6��316ʵ�飩Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6��316ʵ�飩View ��Ϣ�������


void CMFCApplication6��316ʵ�飩View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	a = point.x;
	b = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication6��316ʵ�飩View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	c = point.x;
	d = point.y;
	CClientDC dc(this);
	CRect cr(a,b,c,d);

	dc.Rectangle(cr);


	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication6��316ʵ�飩View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);

	CString A;
	A.Format(_T("X=%d,Y=%d"), point.x, point.y);
	dc.TextOutW(100, 100, A);

	CView::OnMouseMove(nFlags, point);
}
