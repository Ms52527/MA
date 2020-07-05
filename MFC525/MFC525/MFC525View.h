
// MFC525View.h : CMFC525View 类的接口
//

#pragma once

class CMFC525Set;

class CMFC525View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC525View();
	DECLARE_DYNCREATE(CMFC525View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC525_FORM };
#endif
	CMFC525Set* m_pSet;

// 特性
public:
	CMFC525Doc* GetDocument() const;

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
	virtual ~CMFC525View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	long num;
	long age;
	CString pic;
	long high;
	long money;
	CString empty;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSort();
	afx_msg void Onsearch();
	afx_msg void Onrecord();
};

#ifndef _DEBUG  // MFC525View.cpp 中的调试版本
inline CMFC525Doc* CMFC525View::GetDocument() const
   { return reinterpret_cast<CMFC525Doc*>(m_pDocument); }
#endif

