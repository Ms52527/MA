
// MFC42002B.h : MFC42002B Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC42002BApp:
// �йش����ʵ�֣������ MFC42002B.cpp
//

class CMFC42002BApp : public CWinApp
{
public:
	CMFC42002BApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC42002BApp theApp;
