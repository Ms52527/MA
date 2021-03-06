
// MFC31701View.h : CMFC31701View 类的接口
//

#pragma once


class CMFC31701View : public CView
{
protected: // 仅从序列化创建
	CMFC31701View();
	DECLARE_DYNCREATE(CMFC31701View)

// 特性
public:
	CMFC31701Doc* GetDocument() const;

// 操作
public:
	BOOL set;
	
	double m;
	int count;
	int a, b, c, d;
	int distance;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC31701View();
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

#ifndef _DEBUG  // MFC31701View.cpp 中的调试版本
inline CMFC31701Doc* CMFC31701View::GetDocument() const
   { return reinterpret_cast<CMFC31701Doc*>(m_pDocument); }
#endif

