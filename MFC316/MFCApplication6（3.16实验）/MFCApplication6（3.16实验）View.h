
// MFCApplication6（3.16实验）View.h : CMFCApplication6（316实验）View 类的接口
//

#pragma once


class CMFCApplication6（316实验）View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication6（316实验）View();
	DECLARE_DYNCREATE(CMFCApplication6（316实验）View)

// 特性
public:
	CMFCApplication6（316实验）Doc* GetDocument() const;

// 操作
public:
	int a, b, c, d;
	BOOL set;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication6（316实验）View();
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

#ifndef _DEBUG  // MFCApplication6（3.16实验）View.cpp 中的调试版本
inline CMFCApplication6（316实验）Doc* CMFCApplication6（316实验）View::GetDocument() const
   { return reinterpret_cast<CMFCApplication6（316实验）Doc*>(m_pDocument); }
#endif

