
// MFC525View.cpp : CMFC525View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC525.h"
#endif

#include "MFC525Set.h"
#include "MFC525Doc.h"
#include "MFC525View.h"
#include "bigpic.h"
#include "sort.h"
#include "search.h"
#include "record.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC525View

IMPLEMENT_DYNCREATE(CMFC525View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC525View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC525View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC525View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC525View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC525View::OnRecordLast)
	ON_WM_PAINT()

	ON_BN_CLICKED(IDC_BUTTON1, &CMFC525View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC525View::OnBnClickedButton2)
	ON_COMMAND(ID_Sort, &CMFC525View::OnSort)
	ON_COMMAND(ID_search, &CMFC525View::Onsearch)
	ON_COMMAND(ID_record, &CMFC525View::Onrecord)
END_MESSAGE_MAP()

// CMFC525View ����/����

CMFC525View::CMFC525View()
	: CRecordView(IDD_MFC525_FORM)
	, name(_T(""))
	, num(0)
	, age(0)
	, pic(_T(""))
	, high(0)
	, money(0)
	, empty(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC525View::~CMFC525View()
{
}

void CMFC525View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT7, empty);
}

BOOL CMFC525View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC525View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC525Set;
	CRecordView::OnInitialUpdate();

}


// CMFC525View ���

#ifdef _DEBUG
void CMFC525View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC525View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC525Doc* CMFC525View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC525Doc)));
	return (CMFC525Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC525View ���ݿ�֧��
CRecordset* CMFC525View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC525View ��Ϣ�������


void CMFC525View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC525View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC525View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}


void CMFC525View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}

void CMFC525View::OnPaint()
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



void CMFC525View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	bigpic xx;
	xx.fil = m_pSet->m_4;
	xx.DoModal();
}


void CMFC525View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);

}


void CMFC525View::OnSort()
{
	// TODO: �ڴ���������������
	sort or ;
	int r = or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or .pp);
		m_pSet->Requery();
		UpdateData(false);


	}

}


void CMFC525View::Onsearch()
{
	// TODO: �ڴ���������������
	search sea;
	int r = sea.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strFilter = sea.ii;
		m_pSet->Requery();
		UpdateData(false);

	}
}


void CMFC525View::Onrecord()
{
	// TODO: �ڴ���������������

	record dlg;
	int n, i;
	CString str, s;

	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())

	{
		n = m_pSet->GetODBCFieldCount();


		for (i = 1; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, str);
			s += _T(" ") + str;
		}
		s += _T("\r\n");
		dlg.xx = s;
		UpdateData(false);
		m_pSet->MoveNext();
	}
	if (dlg.DoModal() == IDOK)
	{

	}
}
