#pragma once


// edit �Ի���

class edit : public CDialogEx
{
	DECLARE_DYNAMIC(edit)

public:
	edit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~edit();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	long num;
	long age;
	CString pic;
	long high;
	long money;
	CString empty;
};
