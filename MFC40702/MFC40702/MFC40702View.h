
// MFC40702View.h : CMFC40702View ��Ľӿ�
//

#pragma once


class CMFC40702View : public CView
{
protected: // �������л�����
	CMFC40702View();
	DECLARE_DYNCREATE(CMFC40702View)

// ����
public:
	CMFC40702Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC40702View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOnput();
};

#ifndef _DEBUG  // MFC40702View.cpp �еĵ��԰汾
inline CMFC40702Doc* CMFC40702View::GetDocument() const
   { return reinterpret_cast<CMFC40702Doc*>(m_pDocument); }
#endif

