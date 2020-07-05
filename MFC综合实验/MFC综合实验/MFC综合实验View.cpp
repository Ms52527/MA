
// MFC�ۺ�ʵ��View.cpp : CMFC�ۺ�ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC�ۺ�ʵ��.h"
#endif

#include "MFC�ۺ�ʵ��Set.h"
#include "MFC�ۺ�ʵ��Doc.h"
#include "MFC�ۺ�ʵ��View.h"
#include "bigpic.h"
#include "sort.h"
#include "search.h"
#include "record.h"
#include "edit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC�ۺ�ʵ��View

IMPLEMENT_DYNCREATE(CMFC�ۺ�ʵ��View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC�ۺ�ʵ��View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC�ۺ�ʵ��View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC�ۺ�ʵ��View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC�ۺ�ʵ��View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC�ۺ�ʵ��View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC�ۺ�ʵ��View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC�ۺ�ʵ��View::OnBnClickedButton2)
	ON_COMMAND(ID_Sort, &CMFC�ۺ�ʵ��View::OnSort)
	ON_COMMAND(ID_search, &CMFC�ۺ�ʵ��View::Onsearch)
	ON_COMMAND(ID_ADD, &CMFC�ۺ�ʵ��View::OnAdd)
	ON_COMMAND(ID_MODIFY, &CMFC�ۺ�ʵ��View::OnModify)
	ON_COMMAND(ID_DELETE, &CMFC�ۺ�ʵ��View::OnDelete)
	ON_COMMAND(ID_record, &CMFC�ۺ�ʵ��View::Onrecord)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC�ۺ�ʵ��View ����/����

CMFC�ۺ�ʵ��View::CMFC�ۺ�ʵ��View()
	: CRecordView(IDD_MFC_FORM)
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

CMFC�ۺ�ʵ��View::~CMFC�ۺ�ʵ��View()
{
}

void CMFC�ۺ�ʵ��View::DoDataExchange(CDataExchange* pDX)
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

BOOL CMFC�ۺ�ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC�ۺ�ʵ��View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC�ۺ�ʵ��Set;
	CRecordView::OnInitialUpdate();

}


// CMFC�ۺ�ʵ��View ���

#ifdef _DEBUG
void CMFC�ۺ�ʵ��View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC�ۺ�ʵ��View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC�ۺ�ʵ��Doc* CMFC�ۺ�ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC�ۺ�ʵ��Doc)));
	return (CMFC�ۺ�ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC�ۺ�ʵ��View ���ݿ�֧��
CRecordset* CMFC�ۺ�ʵ��View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC�ۺ�ʵ��View ��Ϣ�������


void CMFC�ۺ�ʵ��View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC�ۺ�ʵ��View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

	Invalidate();
}


void CMFC�ۺ�ʵ��View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();
}


void CMFC�ۺ�ʵ��View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);

	Invalidate();

}


void CMFC�ۺ�ʵ��View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bigpic xx;
	xx.fil = m_pSet->m_4;
	xx.DoModal();

}


void CMFC�ۺ�ʵ��View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter.Format(_T(""));
	m_pSet->m_strSort.Format(_T(""));
	m_pSet->Requery();
	UpdateData(false);
}


void CMFC�ۺ�ʵ��View::OnSort()
{
	// TODO: �ڴ���������������
	sort or ;
	int r = or .DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strSort.Format(_T("%s"), or .x);
		m_pSet->Requery();
		UpdateData(false);


	}

}


void CMFC�ۺ�ʵ��View::Onsearch()
{
	// TODO: �ڴ���������������
	search sea;
	int r = sea.DoModal();
	if (r == IDOK)
	{
		m_pSet->m_strFilter = sea.y;
		m_pSet->Requery();
		UpdateData(false);

	}

}


void CMFC�ۺ�ʵ��View::OnAdd()
{
	// TODO: �ڴ���������������

	edit stu;
	int r = stu.DoModal();
	if (r == IDOK)
	{
		m_pSet->AddNew();
		m_pSet->m_1 = stu.name;
		m_pSet->m_2 = stu.num;
		m_pSet->m_3 = stu.age;
		m_pSet->m_4 = stu.pic;
		m_pSet->m_5 = stu.high;
		m_pSet->m_6 = stu.money;
		empty = stu.empty;

		m_pSet->Update();
		UpdateData(false);


	}
}


void CMFC�ۺ�ʵ��View::OnModify()
{
	// TODO: �ڴ���������������
	edit stu;
	m_pSet->Edit();
	
	int Y = stu.DoModal();
	if (Y == IDOK)
	{
		
		m_pSet->Edit();
		m_pSet->m_1 = stu.name;
		m_pSet->m_2 = stu.num;
		m_pSet->m_3 = stu.age;
		m_pSet->m_4 = stu.pic;
		m_pSet->m_5 = stu.high;
		m_pSet->m_6 = stu.money;
		empty = stu.empty;



		m_pSet->Update();
		UpdateData(false);
	}


}


void CMFC�ۺ�ʵ��View::OnDelete()
{
	// TODO: �ڴ���������������

	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void CMFC�ۺ�ʵ��View::Onrecord()
{
	// TODO: �ڴ���������������
	CString ss = _T("");
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		CString s;
		int n = m_pSet->GetODBCFieldCount();
		for (int i = 0; i < n; i++)
		{
			m_pSet->GetFieldValue((short)i, s);
			ss += s + _T(" ");

		}
		ss += _T("\r\n");
		m_pSet->MoveNext();

	}
	//CClientDC dc(this);
	//dc.TextOutW(700, 100, ss);
	record dlg;
	dlg.pp = ss;
	if (dlg.DoModal() == IDOK)
	{

	}

}


void CMFC�ۺ�ʵ��View::OnPaint()
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
