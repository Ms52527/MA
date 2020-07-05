#pragma once


// DLGADD 对话框

class DLGADD : public CDialogEx
{
	DECLARE_DYNAMIC(DLGADD)

public:
	DLGADD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLGADD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int ONE;
	int TWO;
	int THREE;
	afx_msg void OnBnClickedButton1();
};
