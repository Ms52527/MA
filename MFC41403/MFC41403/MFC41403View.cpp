
// MFC41403View.cpp : CMFC41403View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC41403.h"
#endif

#include "MFC41403Doc.h"
#include "MFC41403View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41403View

IMPLEMENT_DYNCREATE(CMFC41403View, CView)

BEGIN_MESSAGE_MAP(CMFC41403View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_OPENDLG, &CMFC41403View::OnOpendlg)
END_MESSAGE_MAP()

// CMFC41403View ����/����

CMFC41403View::CMFC41403View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC41403View::~CMFC41403View()
{
}

BOOL CMFC41403View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41403View ����

void CMFC41403View::OnDraw(CDC* /*pDC*/)
{
	CMFC41403Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC41403View ���

#ifdef _DEBUG
void CMFC41403View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41403View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41403Doc* CMFC41403View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41403Doc)));
	return (CMFC41403Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41403View ��Ϣ�������


void CMFC41403View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ



	CFileDialog cfd(true);
	int r = cfd.DoModal();

	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();

		a = filename;
	
		GetDC()->TextOutW(100, 100, filename);

	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC41403View::OnOpendlg()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	dlg.bb = a;
	int r = dlg.DoModal();
	if (r == IDOK)
	{


	}
}
