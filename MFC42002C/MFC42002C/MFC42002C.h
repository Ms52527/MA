
// MFC42002C.h : MFC42002C Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC42002CApp:
// �йش����ʵ�֣������ MFC42002C.cpp
//

class CMFC42002CApp : public CWinApp
{
public:
	CMFC42002CApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC42002CApp theApp;
