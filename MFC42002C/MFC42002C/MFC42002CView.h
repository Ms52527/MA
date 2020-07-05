
// MFC42002CView.h : CMFC42002CView 类的接口
//

#pragma once


class CMFC42002CView : public CView
{
protected: // 仅从序列化创建
	CMFC42002CView();
	DECLARE_DYNCREATE(CMFC42002CView)

// 特性
public:
	CMFC42002CDoc* GetDocument() const;

// 操作
public:
	CRect A;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42002CView();
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
};

#ifndef _DEBUG  // MFC42002CView.cpp 中的调试版本
inline CMFC42002CDoc* CMFC42002CView::GetDocument() const
   { return reinterpret_cast<CMFC42002CDoc*>(m_pDocument); }
#endif

