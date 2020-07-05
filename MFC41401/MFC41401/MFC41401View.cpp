
// MFC41401View.cpp : CMFC41401View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC41401.h"
#endif

#include "MFC41401Doc.h"
#include "MFC41401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41401View

IMPLEMENT_DYNCREATE(CMFC41401View, CView)

BEGIN_MESSAGE_MAP(CMFC41401View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC41401View ����/����

CMFC41401View::CMFC41401View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC41401View::~CMFC41401View()
{
}

BOOL CMFC41401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41401View ����

void CMFC41401View::OnDraw(CDC* /*pDC*/)
{
	CMFC41401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC41401View ���

#ifdef _DEBUG
void CMFC41401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41401Doc* CMFC41401View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41401Doc)));
	return (CMFC41401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41401View ��Ϣ�������


void CMFC41401View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		
		GetDC()->TextOutW(100, 100, filename);

	}


	CView::OnLButtonDblClk(nFlags, point);
}
