
// MFC51901Doc.h : CMFC51901Doc ��Ľӿ�
//


#pragma once
#include "MFC51901Set.h"


class CMFC51901Doc : public CDocument
{
protected: // �������л�����
	CMFC51901Doc();
	DECLARE_DYNCREATE(CMFC51901Doc)

// ����
public:
	CMFC51901Set m_MFC51901Set;

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
	virtual ~CMFC51901Doc();
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
