
// MFCA32401.h : MFCA32401 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCA32401App:
// �йش����ʵ�֣������ MFCA32401.cpp
//

class CMFCA32401App : public CWinApp
{
public:
	CMFCA32401App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCA32401App theApp;
