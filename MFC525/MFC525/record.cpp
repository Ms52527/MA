// record.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC525.h"
#include "record.h"
#include "afxdialogex.h"


// record 对话框

IMPLEMENT_DYNAMIC(record, CDialogEx)

record::record(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, xx(_T(""))
{

}

record::~record()
{
}

void record::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST1, xx);
}


BEGIN_MESSAGE_MAP(record, CDialogEx)
END_MESSAGE_MAP()


// record 消息处理程序
