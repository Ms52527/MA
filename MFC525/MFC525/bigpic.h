#pragma once


// bigpic �Ի���

class bigpic : public CDialogEx
{
	DECLARE_DYNAMIC(bigpic)

public:
	bigpic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~bigpic();

	CString fil;

	void foo(CString filename);
	afx_msg void OnPaint();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
