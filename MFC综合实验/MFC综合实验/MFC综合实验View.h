
// MFC综合实验View.h : CMFC综合实验View 类的接口
//

#pragma once

class CMFC综合实验Set;

class CMFC综合实验View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC综合实验View();
	DECLARE_DYNCREATE(CMFC综合实验View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_FORM };
#endif
	CMFC综合实验Set* m_pSet;

// 特性
public:
	CMFC综合实验Doc* GetDocument() const;

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
	virtual ~CMFC综合实验View();
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
	CString name;
	long num;
	long age;
	CString pic;
	long high;
	long money;
	CString empty;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSort();
	afx_msg void Onsearch();
	afx_msg void OnAdd();
	afx_msg void OnModify();
	afx_msg void OnDelete();
	afx_msg void Onrecord();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC综合实验View.cpp 中的调试版本
inline CMFC综合实验Doc* CMFC综合实验View::GetDocument() const
   { return reinterpret_cast<CMFC综合实验Doc*>(m_pDocument); }
#endif

