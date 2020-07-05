
// MFC512View.cpp : CMFC512View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC512.h"
#endif

#include "MFC512Set.h"
#include "MFC512Doc.h"
#include "MFC512View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC512View

IMPLEMENT_DYNCREATE(CMFC512View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC512View, CRecordView)
	
	ON_COMMAND(ID_RECORD_FIRST, &CMFC512View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC512View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC512View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC512View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC512View ����/����

CMFC512View::CMFC512View()
	: CRecordView(IDD_MFC512_FORM)
	, Pname(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	Path = _T("D:\\VCʵ��\\�����ļ�\\ʵ��ͼƬ\\");
	a = 0;

}

CMFC512View::~CMFC512View()
{
}

void CMFC512View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC512View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC512View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC512Set;
	CRecordView::OnInitialUpdate();

}


// CMFC512View ���

#ifdef _DEBUG
void CMFC512View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC512View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC512Doc* CMFC512View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC512Doc)));
	return (CMFC512Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC512View ���ݿ�֧��
CRecordset* CMFC512View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC512View ��Ϣ�������





void CMFC512View::OnRecordFirst()
{
	// TODO: �ڴ���������������

	m_pSet->MoveFirst();
	UpdateData(false);
	
	
	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();

	
}


void CMFC512View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	
	
	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();
	
}


void CMFC512View::OnRecordNext()
{
	// TODO: �ڴ���������������

	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	

	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();
	
	
}


void CMFC512View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	

	GetDlgItemText(IDC_EDIT1, str);
	filename = Path + str;
	a = 1;
	Invalidate();
	

}

void CMFC512View::Drawpic(CString file)
{
	CImage img;
	img.Load(file);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();


	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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

void CMFC512View::OnPaint()
{
	CPaintDC dc(this);
	CImage img;
	
	
	if (a == 0)
	{
		CString str1;
		GetDlgItemText(IDC_EDIT1, str1);
		filename = Path + str1;
	}
	
	img.Load(filename);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();

	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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
