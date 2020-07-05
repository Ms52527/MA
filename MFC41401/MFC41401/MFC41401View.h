
// MFC41401View.h : CMFC41401View 类的接口
//

#pragma once


class CMFC41401View : public CView
{
protected: // 仅从序列化创建
	CMFC41401View();
	DECLARE_DYNCREATE(CMFC41401View)

// 特性
public:
	CMFC41401Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41401View();
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
};

#ifndef _DEBUG  // MFC41401View.cpp 中的调试版本
inline CMFC41401Doc* CMFC41401View::GetDocument() const
   { return reinterpret_cast<CMFC41401Doc*>(m_pDocument); }
#endif

