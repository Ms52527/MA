
// MFC51102Doc.h : CMFC51102Doc ��Ľӿ�
//


#pragma once
#include "MFC51102Set.h"


class CMFC51102Doc : public CDocument
{
protected: // �������л�����
	CMFC51102Doc();
	DECLARE_DYNCREATE(CMFC51102Doc)

// ����
public:
	CMFC51102Set m_MFC51102Set;

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
	virtual ~CMFC51102Doc();
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
