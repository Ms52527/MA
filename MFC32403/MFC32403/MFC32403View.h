
// MFC32403View.h : CMFC32403View 类的接口
//

#pragma once


class CMFC32403View : public CView
{
protected: // 仅从序列化创建
	CMFC32403View();
	DECLARE_DYNCREATE(CMFC32403View)

// 特性
public:
	CMFC32403Doc* GetDocument() const;

// 操作
public:
	int dx, dy, ux, uy;
	int a;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC32403View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC32403View.cpp 中的调试版本
inline CMFC32403Doc* CMFC32403View::GetDocument() const
   { return reinterpret_cast<CMFC32403Doc*>(m_pDocument); }
#endif

