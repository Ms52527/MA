#pragma once


// BIGpic 对话框

class BIGpic : public CDialogEx
{
	DECLARE_DYNAMIC(BIGpic)

public:
	BIGpic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BIGpic();

	CString fil;

	void foo(CString filename);
	afx_msg void OnPaint();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
