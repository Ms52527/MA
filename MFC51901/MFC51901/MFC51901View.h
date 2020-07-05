
// MFC51901View.h : CMFC51901View 类的接口
//

#pragma once

class CMFC51901Set;

class CMFC51901View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC51901View();
	DECLARE_DYNCREATE(CMFC51901View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC51901_FORM };
#endif
	CMFC51901Set* m_pSet;

// 特性
public:
	CMFC51901Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC51901View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long P;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3ADD();
	afx_msg void OnBnClickedButton4MODIFY();
};

#ifndef _DEBUG  // MFC51901View.cpp 中的调试版本
inline CMFC51901Doc* CMFC51901View::GetDocument() const
   { return reinterpret_cast<CMFC51901Doc*>(m_pDocument); }
#endif

