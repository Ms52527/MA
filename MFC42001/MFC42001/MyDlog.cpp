// MyDlog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC42001.h"
#include "MyDlog.h"
#include "afxdialogex.h"


// MyDlog 对话框

IMPLEMENT_DYNAMIC(MyDlog, CDialogEx)

MyDlog::MyDlog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, X(0)
	, Y(0)
	, Z(0)
	, R(0)
{

}

MyDlog::~MyDlog()
{
}

void MyDlog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, X);
	DDV_MinMaxInt(pDX, X, -1000, 1000);
	DDX_Text(pDX, IDC_EDIT2, Y);
	DDV_MinMaxInt(pDX, Y, -1000, 1000);
	DDX_Text(pDX, IDC_EDIT3, Z);
	DDV_MinMaxDouble(pDX, Z, -100000, 100000);
	DDX_Text(pDX, IDC_EDIT4, R);
	DDV_MinMaxInt(pDX, R, 0, 10000);
}


BEGIN_MESSAGE_MAP(MyDlog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDlog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDlog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &MyDlog::OnBnClickedButton6)
END_MESSAGE_MAP()


// MyDlog 消息处理程序


void MyDlog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	Z = X + Y;
	UpdateData(false);
}


void MyDlog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	Z = X - Y;
	UpdateData(false);
}


void MyDlog::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	Z = X * Y;
	UpdateData(false);
}


void MyDlog::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	Z = X / Y;
	UpdateData(false);
}


void MyDlog::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	Z =sqrt( R) ;
	UpdateData(false);
}


void MyDlog::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	Z = 1.0/R ;
	UpdateData(false);
}
