
// MFC501801View.cpp : CMFC501801View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC501801.h"
#endif

#include "MFC501801Set.h"
#include "MFC501801Doc.h"
#include "MFC501801View.h"
#include "BIGpic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC501801View

IMPLEMENT_DYNCREATE(CMFC501801View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC501801View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC501801View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC501801View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC501801View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC501801View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC501801View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFC501801View ����/����

CMFC501801View::CMFC501801View()
	: CRecordView(IDD_MFC501801_FORM)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, pic(_T(""))
	, high(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC501801View::~CMFC501801View()
{
}

void CMFC501801View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
}

BOOL CMFC501801View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC501801View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC501801Set;
	CRecordView::OnInitialUpdate();

}


// CMFC501801View ���

#ifdef _DEBUG
void CMFC501801View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC501801View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC501801Doc* CMFC501801View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC501801Doc)));
	return (CMFC501801Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC501801View ���ݿ�֧��
CRecordset* CMFC501801View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC501801View ��Ϣ�������


void CMFC501801View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC501801View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC501801View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}


void CMFC501801View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}

void CMFC501801View::OnPaint()
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






void CMFC501801View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	BIGpic xx;
	xx.fil = m_pSet->m_4;
	xx.DoModal();
}
