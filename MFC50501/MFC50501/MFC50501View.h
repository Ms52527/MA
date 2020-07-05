
// MFC50501View.h : CMFC50501View 类的接口
//

#pragma once

class CMFC50501Set;

class CMFC50501View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC50501View();
	DECLARE_DYNCREATE(CMFC50501View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC50501_FORM };
#endif
	CMFC50501Set* m_pSet;

// 特性
public:
	CMFC50501Doc* GetDocument() const;

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
	virtual ~CMFC50501View();
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
	double number;
	double age;
	double phone;
};

#ifndef _DEBUG  // MFC50501View.cpp 中的调试版本
inline CMFC50501Doc* CMFC50501View::GetDocument() const
   { return reinterpret_cast<CMFC50501Doc*>(m_pDocument); }
#endif

