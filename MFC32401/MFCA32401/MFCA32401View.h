
// MFCA32401View.h : CMFCA32401View 类的接口
//

#pragma once


class CMFCA32401View : public CView
{
protected: // 仅从序列化创建
	CMFCA32401View();
	DECLARE_DYNCREATE(CMFCA32401View)

// 特性
public:
	CMFCA32401Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCA32401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFCA32401View.cpp 中的调试版本
inline CMFCA32401Doc* CMFCA32401View::GetDocument() const
   { return reinterpret_cast<CMFCA32401Doc*>(m_pDocument); }
#endif

