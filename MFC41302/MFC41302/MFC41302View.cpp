
// MFC41302View.cpp : CMFC41302View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC41302.h"
#endif

#include "MFC41302Doc.h"
#include "MFC41302View.h"
#include "DLGADD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41302View

IMPLEMENT_DYNCREATE(CMFC41302View, CView)

BEGIN_MESSAGE_MAP(CMFC41302View, CView)
	ON_COMMAND(ID_OPEN, &CMFC41302View::OnOpen)
END_MESSAGE_MAP()

// CMFC41302View ����/����

CMFC41302View::CMFC41302View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC41302View::~CMFC41302View()
{
}

BOOL CMFC41302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41302View ����

void CMFC41302View::OnDraw(CDC* pDC)
{
	CMFC41302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s = _T("�����������ͼ�򿪼�����");
	pDC->TextOutW(100, 100, s);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC41302View ���

#ifdef _DEBUG
void CMFC41302View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41302Doc* CMFC41302View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41302Doc)));
	return (CMFC41302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41302View ��Ϣ�������


void CMFC41302View::OnOpen()
{
	// TODO: �ڴ���������������
	DLGADD dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
