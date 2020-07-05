
// MFC42002B.h : MFC42002B 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC42002BApp:
// 有关此类的实现，请参阅 MFC42002B.cpp
//

class CMFC42002BApp : public CWinApp
{
public:
	CMFC42002BApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC42002BApp theApp;
