// DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC41304.h"
#include "DLG.h"
#include "afxdialogex.h"


// DLG 对话框

IMPLEMENT_DYNAMIC(DLG, CDialogEx)

DLG::DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, X(_T(""))
	, Y(0)
	, Z(_T(""))
{

}

DLG::~DLG()
{
}

void DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, X);
	DDX_Text(pDX, IDC_EDIT2, Y);
	DDX_Text(pDX, IDC_EDIT3, Z);
}


BEGIN_MESSAGE_MAP(DLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLG 消息处理程序


void DLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString A;
	A.Format(_T("%d"), Y);

	Z = X + A;
	UpdateData(false);
}
