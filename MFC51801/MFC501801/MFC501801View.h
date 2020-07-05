
// MFC501801View.h : CMFC501801View 类的接口
//

#pragma once

class CMFC501801Set;

class CMFC501801View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC501801View();
	DECLARE_DYNCREATE(CMFC501801View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC501801_FORM };
#endif
	CMFC501801Set* m_pSet;

// 特性
public:
	CMFC501801Doc* GetDocument() const;

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
	virtual ~CMFC501801View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	CString name;
	CString num;
	CString age;
	CString pic;
	CString high;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFC501801View.cpp 中的调试版本
inline CMFC501801Doc* CMFC501801View::GetDocument() const
   { return reinterpret_cast<CMFC501801Doc*>(m_pDocument); }
#endif

