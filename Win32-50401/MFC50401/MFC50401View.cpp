
// MFC50401View.cpp : CMFC50401View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC50401.h"
#endif

#include "MFC50401Doc.h"
#include "MFC50401View.h"
#include"�׳�.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMFC50401View

IMPLEMENT_DYNCREATE(CMFC50401View, CView)

BEGIN_MESSAGE_MAP(CMFC50401View, CView)
END_MESSAGE_MAP()

// CMFC50401View ����/����

CMFC50401View::CMFC50401View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC50401View::~CMFC50401View()
{
}

BOOL CMFC50401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC50401View ����

void CMFC50401View::OnDraw(CDC* pDC)
{
	CMFC50401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S, SS;
	//S = CString(pchar());
	//pDC->TextOutW(200, 200, S);
	F2 b;
	S.Format(_T("%d ��������ʹ��"), b.GetNum(pDoc->n));
	if (b.Factorial(pDoc->n) > 50000)
	{
		SS.Format(_T("�������������"));
	}
	else
	{
		SS.Format(_T("�����׳˵Ľ��Ϊ��%d"), b.Factorial(pDoc->n));

	}
	pDC->TextOutW(300, 200, S);
	pDC->TextOutW(300, 300, SS);


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC50401View ���

#ifdef _DEBUG
void CMFC50401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC50401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC50401Doc* CMFC50401View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC50401Doc)));
	return (CMFC50401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC50401View ��Ϣ�������
