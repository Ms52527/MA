#pragma once


// sort 对话框

class sort : public CDialogEx
{
	DECLARE_DYNAMIC(sort)

public:
	sort(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~sort();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString x;
};
