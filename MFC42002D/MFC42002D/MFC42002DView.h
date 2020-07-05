
// MFC42002DView.h : CMFC42002DView 类的接口
//

#pragma once


class CMFC42002DView : public CView
{
protected: // 仅从序列化创建
	CMFC42002DView();
	DECLARE_DYNCREATE(CMFC42002DView)

// 特性
public:
	CMFC42002DDoc* GetDocument() const;

// 操作
public:
	CRect crect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42002DView();
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

#ifndef _DEBUG  // MFC42002DView.cpp 中的调试版本
inline CMFC42002DDoc* CMFC42002DView::GetDocument() const
   { return reinterpret_cast<CMFC42002DDoc*>(m_pDocument); }
#endif

