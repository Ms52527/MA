
// MFC31701View.cpp : CMFC31701View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC31701.h"
#endif

#include "MFC31701Doc.h"
#include "MFC31701View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31701View

IMPLEMENT_DYNCREATE(CMFC31701View, CView)

BEGIN_MESSAGE_MAP(CMFC31701View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC31701View ����/����

CMFC31701View::CMFC31701View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;

}

CMFC31701View::~CMFC31701View()
{
}

BOOL CMFC31701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC31701View ����

void CMFC31701View::OnDraw(CDC* /*pDC*/)
{
	CMFC31701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC31701View ���

#ifdef _DEBUG
void CMFC31701View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31701Doc* CMFC31701View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31701Doc)));
	return (CMFC31701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31701View ��Ϣ�������


void CMFC31701View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString K;
	set = true;
	a = point.x;
	b = point.y;
	K.Format(_T("�����X=%d,Y=%d"), a, b);
	dc.TextOutW(20, 100, K);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC31701View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set)
	count +=1;
	

	CView::OnMouseMove(nFlags, point);
}

void CMFC31701View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString A;
	CString P;
	CString O;
	c = point.x;
	d = point.y;
	distance = sqrt((a - c)*(a - c) + (b - d)*(b - d));

	P.Format(_T("̧��X=%d,Y=%d"), c, d);
	dc.TextOutW(20, 200, P);
	O.Format(_T("����=%d"), distance);
	dc.TextOutW(20, 300, O);

	m = (double)distance / count;

	A.Format(_T("����=%d,ƽ������=%.6f"), count,m );
	dc.TextOutW(200, 100, A);
	
	count = 0;

	CView::OnLButtonUp(nFlags, point);
}


