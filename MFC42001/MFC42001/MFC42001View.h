
// MFC42001View.h : CMFC42001View ��Ľӿ�
//

#pragma once


class CMFC42001View : public CView
{
protected: // �������л�����
	CMFC42001View();
	DECLARE_DYNCREATE(CMFC42001View)

// ����
public:
	CMFC42001Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpen();
};

#ifndef _DEBUG  // MFC42001View.cpp �еĵ��԰汾
inline CMFC42001Doc* CMFC42001View::GetDocument() const
   { return reinterpret_cast<CMFC42001Doc*>(m_pDocument); }
#endif

