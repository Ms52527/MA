// DLGADD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC41302.h"
#include "DLGADD.h"
#include "afxdialogex.h"


// DLGADD �Ի���

IMPLEMENT_DYNAMIC(DLGADD, CDialogEx)

DLGADD::DLGADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, ONE(0)
	, TWO(0)
	, THREE(0)
{

}

DLGADD::~DLGADD()
{
}

void DLGADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ONE);
	DDX_Text(pDX, IDC_EDIT2, TWO);
	DDX_Text(pDX, IDC_EDIT3, THREE);
}


BEGIN_MESSAGE_MAP(DLGADD, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DLGADD::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLGADD ��Ϣ�������


void DLGADD::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	THREE = ONE + TWO;
	UpdateData(false);
	


}
