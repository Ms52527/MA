// edit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC�ۺ�ʵ��.h"
#include "edit.h"
#include "afxdialogex.h"


// edit �Ի���

IMPLEMENT_DYNAMIC(edit, CDialogEx)

edit::edit(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, name(_T(""))
	, num(0)
	, age(0)
	, pic(_T(""))
	, high(0)
	, money(0)
	, empty(_T(""))
{

}

edit::~edit()
{
}

void edit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Text(pDX, IDC_EDIT3, age);
	DDX_Text(pDX, IDC_EDIT4, pic);
	DDX_Text(pDX, IDC_EDIT5, high);
	DDX_Text(pDX, IDC_EDIT6, money);
	DDX_Text(pDX, IDC_EDIT7, empty);
}


BEGIN_MESSAGE_MAP(edit, CDialogEx)
END_MESSAGE_MAP()


// edit ��Ϣ�������
