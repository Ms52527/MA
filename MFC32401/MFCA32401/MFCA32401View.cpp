
// MFCA32401View.cpp : CMFCA32401View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCA32401.h"
#endif

#include "MFCA32401Doc.h"
#include "MFCA32401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA32401View

IMPLEMENT_DYNCREATE(CMFCA32401View, CView)

BEGIN_MESSAGE_MAP(CMFCA32401View, CView)
	ON_COMMAND(SHOWNAME, &CMFCA32401View::OnShowname)
END_MESSAGE_MAP()

// CMFCA32401View ����/����

CMFCA32401View::CMFCA32401View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCA32401View::~CMFCA32401View()
{
}

BOOL CMFCA32401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCA32401View ����

void CMFCA32401View::OnDraw(CDC* /*pDC*/)
{
	CMFCA32401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCA32401View ���

#ifdef _DEBUG
void CMFCA32401View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA32401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA32401Doc* CMFCA32401View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA32401Doc)));
	return (CMFCA32401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA32401View ��Ϣ�������


void CMFCA32401View::OnShowname()
{

	// TODO: �ڴ���������������

	CClientDC dc(this);
	CString a;
	a = _T("���ğ�");
	dc.TextOutW(100, 200, a);
}
