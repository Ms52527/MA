#pragma once


// DLGADD �Ի���

class DLGADD : public CDialogEx
{
	DECLARE_DYNAMIC(DLGADD)

public:
	DLGADD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLGADD();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int ONE;
	int TWO;
	int THREE;
	afx_msg void OnBnClickedButton1();
};
