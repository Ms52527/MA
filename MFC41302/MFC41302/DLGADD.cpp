// DLGADD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC41302.h"
#include "DLGADD.h"
#include "afxdialogex.h"


// DLGADD 对话框

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


// DLGADD 消息处理程序


void DLGADD::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	THREE = ONE + TWO;
	UpdateData(false);
	


}
