
// MFC42001View.h : CMFC42001View 类的接口
//

#pragma once


class CMFC42001View : public CView
{
protected: // 仅从序列化创建
	CMFC42001View();
	DECLARE_DYNCREATE(CMFC42001View)

// 特性
public:
	CMFC42001Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpen();
};

#ifndef _DEBUG  // MFC42001View.cpp 中的调试版本
inline CMFC42001Doc* CMFC42001View::GetDocument() const
   { return reinterpret_cast<CMFC42001Doc*>(m_pDocument); }
#endif

