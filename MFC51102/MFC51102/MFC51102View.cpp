
// MFC51102View.cpp : CMFC51102View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC51102.h"
#endif

#include "MFC51102Set.h"
#include "MFC51102Doc.h"
#include "MFC51102View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC51102View

IMPLEMENT_DYNCREATE(CMFC51102View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC51102View, CRecordView)
	ON_COMMAND(ID_RECORD_PREV, &CMFC51102View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC51102View::OnRecordNext)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC51102View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CMFC51102View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC51102View ����/����

CMFC51102View::CMFC51102View()
	: CRecordView(IDD_MFC51102_FORM)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, pic(_T(""))
	, high(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC51102View::~CMFC51102View()
{
}

void CMFC51102View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1 );
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
}

BOOL CMFC51102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC51102View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC51102Set;
	CRecordView::OnInitialUpdate();

}


// CMFC51102View ���

#ifdef _DEBUG
void CMFC51102View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC51102View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC51102Doc* CMFC51102View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC51102Doc)));
	return (CMFC51102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC51102View ���ݿ�֧��
CRecordset* CMFC51102View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC51102View ��Ϣ�������

void CMFC51102View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC51102View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC51102View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}




void CMFC51102View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();

}

 void CMFC51102View::OnPaint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPaintDC dc(this);
	CImage img;
	CString filename;
	CString str1;
	GetDlgItemText(IDC_EDIT4, str1);
	filename = str1;

	img.Load(filename);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();

	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}


	pDC->SetStretchBltMode(HALFTONE);//�ļ���ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}

