
// MFCApplication6��3.16ʵ�飩.h : MFCApplication6��3.16ʵ�飩 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication6��316ʵ�飩App:
// �йش����ʵ�֣������ MFCApplication6��3.16ʵ�飩.cpp
//

class CMFCApplication6��316ʵ�飩App : public CWinApp
{
public:
	CMFCApplication6��316ʵ�飩App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication6��316ʵ�飩App theApp;
