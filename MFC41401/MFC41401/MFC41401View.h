
// MFC41401View.h : CMFC41401View ��Ľӿ�
//

#pragma once


class CMFC41401View : public CView
{
protected: // �������л�����
	CMFC41401View();
	DECLARE_DYNCREATE(CMFC41401View)

// ����
public:
	CMFC41401Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC41401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC41401View.cpp �еĵ��԰汾
inline CMFC41401Doc* CMFC41401View::GetDocument() const
   { return reinterpret_cast<CMFC41401Doc*>(m_pDocument); }
#endif

