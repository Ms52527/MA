
// MFC42102View.h : CMFC42102View 类的接口
//

#pragma once


class CMFC42102View : public CView
{
protected: // 仅从序列化创建
	CMFC42102View();
	DECLARE_DYNCREATE(CMFC42102View)

// 特性
public:
	CMFC42102Doc* GetDocument() const;

// 操作
public:
	CString B;
	CString C;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42102View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnOpenpic();
};

#ifndef _DEBUG  // MFC42102View.cpp 中的调试版本
inline CMFC42102Doc* CMFC42102View::GetDocument() const
   { return reinterpret_cast<CMFC42102Doc*>(m_pDocument); }
#endif

