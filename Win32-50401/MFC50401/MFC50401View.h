
// MFC50401View.h : CMFC50401View 类的接口
//

#pragma once


class CMFC50401View : public CView
{
protected: // 仅从序列化创建
	CMFC50401View();
	DECLARE_DYNCREATE(CMFC50401View)

// 特性
public:
	CMFC50401Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC50401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC50401View.cpp 中的调试版本
inline CMFC50401Doc* CMFC50401View::GetDocument() const
   { return reinterpret_cast<CMFC50401Doc*>(m_pDocument); }
#endif

