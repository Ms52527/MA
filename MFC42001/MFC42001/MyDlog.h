#pragma once


// MyDlog �Ի���

class MyDlog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlog)

public:
	MyDlog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
