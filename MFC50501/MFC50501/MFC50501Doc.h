
// MFC50501Doc.h : CMFC50501Doc ��Ľӿ�
//


#pragma once
#include "MFC50501Set.h"


class CMFC50501Doc : public CDocument
{
protected: // �������л�����
	CMFC50501Doc();
	DECLARE_DYNCREATE(CMFC50501Doc)

// ����
public:
	CMFC50501Set m_MFC50501Set;

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
	virtual ~CMFC50501Doc();
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
