
// MFC50501View.cpp : CMFC50501View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC50501.h"
#endif

#include "MFC50501Set.h"
#include "MFC50501Doc.h"
#include "MFC50501View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC50501View

IMPLEMENT_DYNCREATE(CMFC50501View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC50501View, CRecordView)
END_MESSAGE_MAP()

// CMFC50501View ����/����

CMFC50501View::CMFC50501View()
	: CRecordView(IDD_MFC50501_FORM)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC50501View::~CMFC50501View()
{
}

void CMFC50501View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}

BOOL CMFC50501View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC50501View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC50501Set;
	CRecordView::OnInitialUpdate();

}


// CMFC50501View ���

#ifdef _DEBUG
void CMFC50501View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC50501View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC50501Doc* CMFC50501View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC50501Doc)));
	return (CMFC50501Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC50501View ���ݿ�֧��
CRecordset* CMFC50501View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC50501View ��Ϣ�������
