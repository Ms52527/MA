// bigpic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC525.h"
#include "bigpic.h"
#include "afxdialogex.h"


// bigpic �Ի���

IMPLEMENT_DYNAMIC(bigpic, CDialogEx)

bigpic::bigpic(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

bigpic::~bigpic()
{
}

void bigpic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(bigpic, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// bigpic ��Ϣ�������

void bigpic::foo(CString filename)
{
	CImage img;
	img.Load(filename);
	int sx, sy, w, h;
	CRect rect;
	CDC *pDC = GetDlgItem(IDC_STATIC11)->GetDC();
	GetDlgItem(IDC_STATIC11)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio> img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void bigpic::OnPaint()
{
	CPaintDC dc(this);
	foo(fil);

}
