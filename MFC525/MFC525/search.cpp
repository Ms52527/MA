// search.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC525.h"
#include "search.h"
#include "afxdialogex.h"


// search �Ի���

IMPLEMENT_DYNAMIC(search, CDialogEx)

search::search(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	
	, ii(_T(""))
{

}

search::~search()
{
}

void search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Text(pDX, IDC_EDIT1, ii);
}


BEGIN_MESSAGE_MAP(search, CDialogEx)
	
END_MESSAGE_MAP()


// search ��Ϣ�������


