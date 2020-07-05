
// MFC41403View.h : CMFC41403View 类的接口
//

#pragma once


class CMFC41403View : public CView
{
protected: // 仅从序列化创建
	CMFC41403View();
	DECLARE_DYNCREATE(CMFC41403View)

// 特性
public:
	CMFC41403Doc* GetDocument() const;

// 操作
public:
	CString a;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41403View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnOpendlg();
};

#ifndef _DEBUG  // MFC41403View.cpp 中的调试版本
inline CMFC41403Doc* CMFC41403View::GetDocument() const
   { return reinterpret_cast<CMFC41403Doc*>(m_pDocument); }
#endif

