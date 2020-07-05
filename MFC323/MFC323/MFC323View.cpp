
// MFC323View.cpp : CMFC323View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC323.h"
#endif

#include "MFC323Doc.h"
#include "MFC323View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC323View

IMPLEMENT_DYNCREATE(CMFC323View, CView)

BEGIN_MESSAGE_MAP(CMFC323View, CView)
	ON_COMMAND(ID_HUATU, &CMFC323View::OnHuatu)
END_MESSAGE_MAP()

// CMFC323View ����/����

CMFC323View::CMFC323View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC323View::~CMFC323View()
{
}

BOOL CMFC323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC323View ����

void CMFC323View::OnDraw(CDC* /*pDC*/)
{
	CMFC323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC323View ���

#ifdef _DEBUG
void CMFC323View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC323Doc* CMFC323View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC323Doc)));
	return (CMFC323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC323View ��Ϣ�������


void CMFC323View::OnHuatu()

{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	CRect cd;
	GetClientRect(&cd);
	CPoint A;
	A = cd.CenterPoint();
	int red = 0, green = 0, blue = 0;
	int width = 2;
	

	for (int i = 10; i >0; i--)
	{
		int color = RGB(red, green, blue);
		CPen newPen(PS_SOLID,width,color);
		CPen *oldPen = dc.SelectObject(&newPen);
		int r = i * 50;
		CRect cr(A.x - r, A.y - r, A.x + r, A.y + r);
		dc.Ellipse(cr);
		dc.SelectObject(oldPen);
		red += 92;
		green += 76;
		blue += 68;
		
	}
	
}
