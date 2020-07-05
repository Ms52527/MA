
// MFC41402View.cpp : CMFC41402View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC41402.h"
#endif

#include "MFC41402Doc.h"
#include "MFC41402View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41402View

IMPLEMENT_DYNCREATE(CMFC41402View, CView)

BEGIN_MESSAGE_MAP(CMFC41402View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_OPENDLG, &CMFC41402View::OnOpendlg)
END_MESSAGE_MAP()

// CMFC41402View ����/����

CMFC41402View::CMFC41402View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC41402View::~CMFC41402View()
{
}

BOOL CMFC41402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41402View ����

void CMFC41402View::OnDraw(CDC* /*pDC*/)
{
	CMFC41402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC41402View ���

#ifdef _DEBUG
void CMFC41402View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41402Doc* CMFC41402View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41402Doc)));
	return (CMFC41402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41402View ��Ϣ�������


void CMFC41402View::OnLButtonDblClk(UINT nFlags, CPoint point)
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


void CMFC41402View::OnOpendlg()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	dlg.DA = a;
	UpdateData(false);

	int r = dlg.DoModal();
	if (r == IDOK)
	{


	}

}
