
// MFC41301View.h : CMFC41301View 类的接口
//

#pragma once


class CMFC41301View : public CView
{
protected: // 仅从序列化创建
	CMFC41301View();
	DECLARE_DYNCREATE(CMFC41301View)

// 特性
public:
	CMFC41301Doc* GetDocument() const;

// 操作
public:
	CRect re;
	int a;

	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41301View();
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

#ifndef _DEBUG  // MFC41301View.cpp 中的调试版本
inline CMFC41301Doc* CMFC41301View::GetDocument() const
   { return reinterpret_cast<CMFC41301Doc*>(m_pDocument); }
#endif

