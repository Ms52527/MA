
// MFC51101Doc.h : CMFC51101Doc ��Ľӿ�
//


#pragma once
#include "MFC51101Set.h"


class CMFC51101Doc : public CDocument
{
protected: // �������л�����
	CMFC51101Doc();
	DECLARE_DYNCREATE(CMFC51101Doc)

// ����
public:
	CMFC51101Set m_MFC51101Set;

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
	virtual ~CMFC51101Doc();
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
