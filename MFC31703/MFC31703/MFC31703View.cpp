
// MFC31703View.cpp : CMFC31703View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC31703.h"
#endif

#include "MFC31703Doc.h"
#include "MFC31703View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC31703View

IMPLEMENT_DYNCREATE(CMFC31703View, CView)

BEGIN_MESSAGE_MAP(CMFC31703View, CView)
END_MESSAGE_MAP()

// CMFC31703View ����/����

CMFC31703View::CMFC31703View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC31703View::~CMFC31703View()
{
}

BOOL CMFC31703View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC31703View ����

void CMFC31703View::OnDraw(CDC* /*pDC*/)
{
	CMFC31703Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC31703View ���

#ifdef _DEBUG
void CMFC31703View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC31703View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC31703Doc* CMFC31703View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC31703Doc)));
	return (CMFC31703Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC31703View ��Ϣ�������
