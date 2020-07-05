#pragma once


// MyDlog 对话框

class MyDlog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlog)

public:
	MyDlog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int X;
	int Y;
	double Z;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	int R;
};
