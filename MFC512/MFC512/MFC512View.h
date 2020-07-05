
// MFC512View.h : CMFC512View 类的接口
//

#pragma once

class CMFC512Set;



class CMFC512View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC512View();
	DECLARE_DYNCREATE(CMFC512View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC512_FORM };
#endif
	CMFC512Set* m_pSet;
	CString Path;

// 特性
public:
	CMFC512Doc* GetDocument() const;
	void Drawpic(CString file);
	
	

// 操作
public:
	CString   str,filename;
	int a;

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC512View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString Pname;
	
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC512View.cpp 中的调试版本
inline CMFC512Doc* CMFC512View::GetDocument() const
   { return reinterpret_cast<CMFC512Doc*>(m_pDocument); }
#endif

