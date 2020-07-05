
// MFC42001View.cpp : CMFC42001View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC42001.h"
#endif

#include "MFC42001Doc.h"
#include "MFC42001View.h"
#include "MyDlog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC42001View

IMPLEMENT_DYNCREATE(CMFC42001View, CView)

BEGIN_MESSAGE_MAP(CMFC42001View, CView)
	ON_COMMAND(ID_OPEN, &CMFC42001View::OnOpen)
END_MESSAGE_MAP()

// CMFC42001View ����/����

CMFC42001View::CMFC42001View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC42001View::~CMFC42001View()
{
}

BOOL CMFC42001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC42001View ����

void CMFC42001View::OnDraw(CDC* pDC)
{
	CMFC42001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s = _T("�����������ͼ�򿪼�����");
	pDC->TextOutW(100,100,s);


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC42001View ���

#ifdef _DEBUG
void CMFC42001View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC42001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC42001Doc* CMFC42001View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC42001Doc)));
	return (CMFC42001Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC42001View ��Ϣ�������


void CMFC42001View::OnOpen()
{
	// TODO: �ڴ���������������
	MyDlog dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}

}
