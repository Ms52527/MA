// Dlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC42002B.h"
#include "Dlg1.h"
#include "afxdialogex.h"


// Dlg1 对话框

IMPLEMENT_DYNAMIC(Dlg1, CDialogEx)

Dlg1::Dlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)

	, top(0)
	, bottom(0)
	, right(0)
	, left(0)
{

}

Dlg1::~Dlg1()
{
}

void Dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, top);
	DDX_Text(pDX, IDC_EDIT2, bottom);
	DDX_Text(pDX, IDC_EDIT4, right);
	DDX_Text(pDX, IDC_EDIT3, left);
}


BEGIN_MESSAGE_MAP(Dlg1, CDialogEx)

END_MESSAGE_MAP()


// Dlg1 消息处理程序


