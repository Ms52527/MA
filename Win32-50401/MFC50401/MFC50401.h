
// MFC50401.h : MFC50401 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC50401App:
// 有关此类的实现，请参阅 MFC50401.cpp
//

class CMFC50401App : public CWinApp
{
public:
	CMFC50401App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC50401App theApp;
