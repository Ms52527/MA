
// MFC42002A.h : MFC42002A Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC42002AApp:
// �йش����ʵ�֣������ MFC42002A.cpp
//

class CMFC42002AApp : public CWinApp
{
public:
	CMFC42002AApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC42002AApp theApp;
