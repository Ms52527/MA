
// MFC525Doc.h : CMFC525Doc ��Ľӿ�
//


#pragma once
#include "MFC525Set.h"


class CMFC525Doc : public CDocument
{
protected: // �������л�����
	CMFC525Doc();
	DECLARE_DYNCREATE(CMFC525Doc)

// ����
public:
	CMFC525Set m_MFC525Set;

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
	virtual ~CMFC525Doc();
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
