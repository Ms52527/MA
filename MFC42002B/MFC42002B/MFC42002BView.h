
// MFC42002BView.h : CMFC42002BView 类的接口
//

#pragma once


class CMFC42002BView : public CView
{
protected: // 仅从序列化创建
	CMFC42002BView();
	DECLARE_DYNCREATE(CMFC42002BView)

// 特性
public:
	CMFC42002BDoc* GetDocument() const;

// 操作
public:
	CRect A;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42002BView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdlg();
};

#ifndef _DEBUG  // MFC42002BView.cpp 中的调试版本
inline CMFC42002BDoc* CMFC42002BView::GetDocument() const
   { return reinterpret_cast<CMFC42002BDoc*>(m_pDocument); }
#endif

