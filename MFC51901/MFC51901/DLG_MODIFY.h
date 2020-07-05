#pragma once


// DLG_MODIFY 对话框

class DLG_MODIFY : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_MODIFY)

public:
	DLG_MODIFY(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_MODIFY();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODIFY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long M;
};
