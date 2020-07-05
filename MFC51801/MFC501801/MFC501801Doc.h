
// MFC501801Doc.h : CMFC501801Doc 类的接口
//


#pragma once
#include "MFC501801Set.h"


class CMFC501801Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFC501801Doc();
	DECLARE_DYNCREATE(CMFC501801Doc)

// 特性
public:
	CMFC501801Set m_MFC501801Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFC501801Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
