
// MFC31702Doc.h : CMFC31702Doc ��Ľӿ�
//


#pragma once


class CMFC31702Doc : public CDocument
{
protected: // �������л�����
	CMFC31702Doc();
	DECLARE_DYNCREATE(CMFC31702Doc)

// ����
public:

// ����
public:
	CRect cr;
	//int w, h;
	


// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC31702Doc();
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
