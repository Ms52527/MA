// DLG_MODIFY.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC51901.h"
#include "DLG_MODIFY.h"
#include "afxdialogex.h"


// DLG_MODIFY �Ի���

IMPLEMENT_DYNAMIC(DLG_MODIFY, CDialogEx)

DLG_MODIFY::DLG_MODIFY(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODIFY, pParent)
	, M(0)
{

}

DLG_MODIFY::~DLG_MODIFY()
{
}

void DLG_MODIFY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, M);
}


BEGIN_MESSAGE_MAP(DLG_MODIFY, CDialogEx)
END_MESSAGE_MAP()


// DLG_MODIFY ��Ϣ�������
