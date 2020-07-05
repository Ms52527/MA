
// MFC41304View.h : CMFC41304View 类的接口
//

#pragma once


class CMFC41304View : public CView
{
protected: // 仅从序列化创建
	CMFC41304View();
	DECLARE_DYNCREATE(CMFC41304View)

// 特性
public:
	CMFC41304Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41304View();
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

#ifndef _DEBUG  // MFC41304View.cpp 中的调试版本
inline CMFC41304Doc* CMFC41304View::GetDocument() const
   { return reinterpret_cast<CMFC41304Doc*>(m_pDocument); }
#endif

