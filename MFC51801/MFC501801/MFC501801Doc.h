
// MFC501801Doc.h : CMFC501801Doc ��Ľӿ�
//


#pragma once
#include "MFC501801Set.h"


class CMFC501801Doc : public CDocument
{
protected: // �������л�����
	CMFC501801Doc();
	DECLARE_DYNCREATE(CMFC501801Doc)

// ����
public:
	CMFC501801Set m_MFC501801Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC501801Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
