#pragma once


// edit 对话框

class edit : public CDialogEx
{
	DECLARE_DYNAMIC(edit)

public:
	edit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~edit();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
