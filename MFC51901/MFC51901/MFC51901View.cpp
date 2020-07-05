
// MFC51901View.cpp : CMFC51901View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC51901.h"
#endif

#include "MFC51901Set.h"
#include "MFC51901Doc.h"
#include "MFC51901View.h"
#include "ADD_DLG.h"
#include "DLG_MODIFY.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC51901View

IMPLEMENT_DYNCREATE(CMFC51901View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC51901View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC51901View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC51901View::OnBnClickedButton3ADD)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC51901View::OnBnClickedButton4MODIFY)
END_MESSAGE_MAP()

// CMFC51901View ����/����

CMFC51901View::CMFC51901View()
	: CRecordView(IDD_MFC51901_FORM)
	, P(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC51901View::~CMFC51901View()
{
}

void CMFC51901View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC51901View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC51901View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC51901Set;
	CRecordView::OnInitialUpdate();

}


// CMFC51901View ���

#ifdef _DEBUG
void CMFC51901View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC51901View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC51901Doc* CMFC51901View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC51901Doc)));
	return (CMFC51901Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC51901View ���ݿ�֧��
CRecordset* CMFC51901View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC51901View ��Ϣ�������


void CMFC51901View::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ɾ��
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);

}


void CMFC51901View::OnBnClickedButton3ADD()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����
	ADD_DLG  adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long I = adddlg.L;
		m_pSet->AddNew();
		m_pSet->m_1 = I;
		m_pSet->Update();
		UpdateData(false);


	}

}


void CMFC51901View::OnBnClickedButton4MODIFY()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸�
	m_pSet->Edit();
	DLG_MODIFY modifydlg;
	int Y= modifydlg.DoModal();
	if (Y == IDOK)
	{
		long I = modifydlg.M;
		m_pSet->Edit();
		m_pSet->m_1 = I;
		m_pSet->Update();
		UpdateData(false);
	}

	
}
