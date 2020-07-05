
// MFC40702View.h : CMFC40702View 类的接口
//

#pragma once


class CMFC40702View : public CView
{
protected: // 仅从序列化创建
	CMFC40702View();
	DECLARE_DYNCREATE(CMFC40702View)

// 特性
public:
	CMFC40702Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC40702View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOnput();
};

#ifndef _DEBUG  // MFC40702View.cpp 中的调试版本
inline CMFC40702Doc* CMFC40702View::GetDocument() const
   { return reinterpret_cast<CMFC40702Doc*>(m_pDocument); }
#endif

