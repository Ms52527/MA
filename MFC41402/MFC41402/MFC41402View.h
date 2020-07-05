
// MFC41402View.h : CMFC41402View 类的接口
//

#pragma once


class CMFC41402View : public CView
{
protected: // 仅从序列化创建
	CMFC41402View();
	DECLARE_DYNCREATE(CMFC41402View)

// 特性
public:
	CMFC41402Doc* GetDocument() const;

// 操作
public:
	CString  a;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41402View();
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

#ifndef _DEBUG  // MFC41402View.cpp 中的调试版本
inline CMFC41402Doc* CMFC41402View::GetDocument() const
   { return reinterpret_cast<CMFC41402Doc*>(m_pDocument); }
#endif

