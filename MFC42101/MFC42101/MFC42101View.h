
// MFC42101View.h : CMFC42101View 类的接口
//

#pragma once


class CMFC42101View : public CView
{
protected: // 仅从序列化创建
	CMFC42101View();
	DECLARE_DYNCREATE(CMFC42101View)

// 特性
public:
	CMFC42101Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC42101View();
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

	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // MFC42101View.cpp 中的调试版本
inline CMFC42101Doc* CMFC42101View::GetDocument() const
   { return reinterpret_cast<CMFC42101Doc*>(m_pDocument); }
#endif

