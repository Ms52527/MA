// Dlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC42002D.h"
#include "Dlg1.h"
#include "afxdialogex.h"


// Dlg1 �Ի���

IMPLEMENT_DYNAMIC(Dlg1, CDialogEx)

Dlg1::Dlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, A(0)
	, B(0)
	, C(0)
{

}

Dlg1::~Dlg1()
{
}

void Dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, A);
	DDX_Text(pDX, IDC_EDIT2, B);
	DDX_Text(pDX, IDC_EDIT3, C);
}


BEGIN_MESSAGE_MAP(Dlg1, CDialogEx)
END_MESSAGE_MAP()


// Dlg1 ��Ϣ�������
