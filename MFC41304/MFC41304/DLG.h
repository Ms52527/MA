#pragma once


// DLG �Ի���

class DLG : public CDialogEx
{
	DECLARE_DYNAMIC(DLG)

public:
	DLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString X;
	int Y;
	CString Z;
	afx_msg void OnBnClickedButton1();
};
