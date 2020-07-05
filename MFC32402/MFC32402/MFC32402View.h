
// MFC32402View.h : CMFC32402View 类的接口
//

#pragma once


class CMFC32402View : public CView
{
protected: // 仅从序列化创建
	CMFC32402View();
	DECLARE_DYNCREATE(CMFC32402View)

// 特性
public:
	CMFC32402Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC32402View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC32402View.cpp 中的调试版本
inline CMFC32402Doc* CMFC32402View::GetDocument() const
   { return reinterpret_cast<CMFC32402Doc*>(m_pDocument); }
#endif

