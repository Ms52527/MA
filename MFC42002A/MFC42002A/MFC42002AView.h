
// MFC42002AView.h : CMFC42002AView 类的接口
//

#pragma once


class CMFC42002AView : public CView
{
protected: // 仅从序列化创建
	CMFC42002AView();
	DECLARE_DYNCREATE(CMFC42002AView)

// 特性
public:
	CMFC42002ADoc* GetDocument() const;

// 操作
public:
	int X1,X2;
	int Y1,Y2;
	int flag;
	CRect A;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42002AView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC42002AView.cpp 中的调试版本
inline CMFC42002ADoc* CMFC42002AView::GetDocument() const
   { return reinterpret_cast<CMFC42002ADoc*>(m_pDocument); }
#endif

