
// MFC40701View.h : CMFC40701View 类的接口
//

#pragma once


class CMFC40701View : public CView
{
protected: // 仅从序列化创建
	CMFC40701View();
	DECLARE_DYNCREATE(CMFC40701View)

// 特性
public:
	CMFC40701Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC40701View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC40701View.cpp 中的调试版本
inline CMFC40701Doc* CMFC40701View::GetDocument() const
   { return reinterpret_cast<CMFC40701Doc*>(m_pDocument); }
#endif

