// search.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC综合实验.h"
#include "search.h"
#include "afxdialogex.h"


// search 对话框

IMPLEMENT_DYNAMIC(search, CDialogEx)

search::search(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, y(_T(""))
{

}

search::~search()
{
}

void search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, y);
}


BEGIN_MESSAGE_MAP(search, CDialogEx)
END_MESSAGE_MAP()


// search 消息处理程序
