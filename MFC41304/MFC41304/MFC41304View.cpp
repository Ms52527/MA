
// MFC41304View.cpp : CMFC41304View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC41304.h"
#endif

#include "MFC41304Doc.h"
#include "MFC41304View.h"
#include "DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41304View

IMPLEMENT_DYNCREATE(CMFC41304View, CView)

BEGIN_MESSAGE_MAP(CMFC41304View, CView)
	ON_COMMAND(ID_OPEN, &CMFC41304View::OnOpen)
END_MESSAGE_MAP()

// CMFC41304View ����/����

CMFC41304View::CMFC41304View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC41304View::~CMFC41304View()
{
}

BOOL CMFC41304View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC41304View ����

void CMFC41304View::OnDraw(CDC* /*pDC*/)
{
	CMFC41304Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC41304View ���

#ifdef _DEBUG
void CMFC41304View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41304View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41304Doc* CMFC41304View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41304Doc)));
	return (CMFC41304Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41304View ��Ϣ�������


void CMFC41304View::OnOpen()
{
	// TODO: �ڴ���������������
	DLG dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
