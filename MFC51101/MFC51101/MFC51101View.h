
// MFC51101View.h : CMFC51101View 类的接口
//

#pragma once

class CMFC51101Set;

class CMFC51101View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC51101View();
	DECLARE_DYNCREATE(CMFC51101View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC51101_FORM };
#endif
	CMFC51101Set* m_pSet;

// 特性
public:
	CMFC51101Doc* GetDocument() const;

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
	virtual ~CMFC51101View();
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
	CString num;
	CString age;
	CString pic;
	CString high;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFC51101View.cpp 中的调试版本
inline CMFC51101Doc* CMFC51101View::GetDocument() const
   { return reinterpret_cast<CMFC51101Doc*>(m_pDocument); }
#endif

