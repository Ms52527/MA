
// MFCUsingWinLIBDLLView.cpp : CMFCUsingWinLIBDLLView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCUsingWinLIBDLL.h"
#endif

#include "MFCUsingWinLIBDLLDoc.h"
#include "MFCUsingWinLIBDLLView.h"
#include"W32.h"
#include"W32D.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCUsingWinLIBDLLView

IMPLEMENT_DYNCREATE(CMFCUsingWinLIBDLLView, CView)

BEGIN_MESSAGE_MAP(CMFCUsingWinLIBDLLView, CView)
END_MESSAGE_MAP()

// CMFCUsingWinLIBDLLView ����/����

CMFCUsingWinLIBDLLView::CMFCUsingWinLIBDLLView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCUsingWinLIBDLLView::~CMFCUsingWinLIBDLLView()
{
}

BOOL CMFCUsingWinLIBDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCUsingWinLIBDLLView ����

void CMFCUsingWinLIBDLLView::OnDraw(CDC* pDC)
{
	CMFCUsingWinLIBDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s = CString(pchar());
	pDC->TextOutW(100, 100, s);

	CString ss;

	ss.Format(_T("����ǴӶ�̬���ӿⷵ�ص�ֵ��%d"),GetInt());
	pDC->TextOutW(200, 200, ss);
}


// CMFCUsingWinLIBDLLView ���

#ifdef _DEBUG
void CMFCUsingWinLIBDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCUsingWinLIBDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCUsingWinLIBDLLDoc* CMFCUsingWinLIBDLLView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCUsingWinLIBDLLDoc)));
	return (CMFCUsingWinLIBDLLDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCUsingWinLIBDLLView ��Ϣ�������
