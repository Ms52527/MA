
// MFC42002D.h : MFC42002D Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC42002DApp:
// �йش����ʵ�֣������ MFC42002D.cpp
//

class CMFC42002DApp : public CWinApp
{
public:
	CMFC42002DApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC42002DApp theApp;
