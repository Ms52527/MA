
// MFC31702View.h : CMFC31702View 类的接口
//

#pragma once


class CMFC31702View : public CView
{
protected: // 仅从序列化创建
	CMFC31702View();
	DECLARE_DYNCREATE(CMFC31702View)

// 特性
public:
	CMFC31702Doc* GetDocument() const;

// 操作
public:
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC31702View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC31702View.cpp 中的调试版本
inline CMFC31702Doc* CMFC31702View::GetDocument() const
   { return reinterpret_cast<CMFC31702Doc*>(m_pDocument); }
#endif

