
// MFCUsingWinLIBDLL.h : MFCUsingWinLIBDLL Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCUsingWinLIBDLLApp:
// �йش����ʵ�֣������ MFCUsingWinLIBDLL.cpp
//

class CMFCUsingWinLIBDLLApp : public CWinApp
{
public:
	CMFCUsingWinLIBDLLApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCUsingWinLIBDLLApp theApp;
