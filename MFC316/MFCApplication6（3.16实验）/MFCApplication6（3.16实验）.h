
// MFCApplication6（3.16实验）.h : MFCApplication6（3.16实验） 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFCApplication6（316实验）App:
// 有关此类的实现，请参阅 MFCApplication6（3.16实验）.cpp
//

class CMFCApplication6（316实验）App : public CWinApp
{
public:
	CMFCApplication6（316实验）App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication6（316实验）App theApp;
