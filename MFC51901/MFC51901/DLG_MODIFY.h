#pragma once


// DLG_MODIFY �Ի���

class DLG_MODIFY : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_MODIFY)

public:
	DLG_MODIFY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_MODIFY();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODIFY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long M;
};
