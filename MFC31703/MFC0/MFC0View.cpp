
// MFC0View.cpp : CMFC0View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC0.h"
#endif

#include "MFC0Doc.h"
#include "MFC0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC0View

IMPLEMENT_DYNCREATE(CMFC0View, CView)

BEGIN_MESSAGE_MAP(CMFC0View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC0View ����/����

CMFC0View::CMFC0View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);

	}
}

CMFC0View::~CMFC0View()
{
}

BOOL CMFC0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC0View ����

void CMFC0View::OnDraw(CDC* pDC)
{
	CMFC0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
			
			set = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);

	}
	
	for (int i = 0; i < N; i++)
	{
		if (tim[i])
			SetTimer(i+5, rand() % 200 + 100, NULL);
	}
	
}


// CMFC0View ���

#ifdef _DEBUG
void CMFC0View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC0Doc* CMFC0View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC0Doc)));
	return (CMFC0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC0View ��Ϣ�������


void CMFC0View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CRect cd;
	GetClientRect(&cd);


	for (int i = 0; i < N; i++)
	{
		if (nIDEvent == i)
		{
			cr[i].top += 10;
			cr[i].bottom += 10;
		}

		if (cr[i].bottom >= (cd.bottom - cd.top))
		{
		    KillTimer(i);
			tim[i] = 1;
			
		}

	}
	
	for (int i = 0; i < N; i++)
	{

		if (nIDEvent == i + 5)
		{
			cr[i].top -= 10;
			cr[i].bottom -= 10;
		}
	}
	
		Invalidate();
	
	CView::OnTimer(nIDEvent);
}
