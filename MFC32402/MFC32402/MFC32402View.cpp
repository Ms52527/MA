
// MFC32402View.cpp : CMFC32402View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC32402.h"
#endif

#include "MFC32402Doc.h"
#include "MFC32402View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC32402View

IMPLEMENT_DYNCREATE(CMFC32402View, CView)

BEGIN_MESSAGE_MAP(CMFC32402View, CView)
END_MESSAGE_MAP()

// CMFC32402View ����/����

CMFC32402View::CMFC32402View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CMFC32402View::~CMFC32402View()
{
}

BOOL CMFC32402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC32402View ����

void CMFC32402View::OnDraw(CDC* pDC)
{
	CMFC32402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// CMFC32402View ���

#ifdef _DEBUG
void CMFC32402View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC32402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC32402Doc* CMFC32402View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC32402Doc)));
	return (CMFC32402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC32402View ��Ϣ�������
