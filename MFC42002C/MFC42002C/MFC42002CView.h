
// MFC42002CView.h : CMFC42002CView ��Ľӿ�
//

#pragma once


class CMFC42002CView : public CView
{
protected: // �������л�����
	CMFC42002CView();
	DECLARE_DYNCREATE(CMFC42002CView)

// ����
public:
	CMFC42002CDoc* GetDocument() const;

// ����
public:
	CRect A;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42002CView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC42002CView.cpp �еĵ��԰汾
inline CMFC42002CDoc* CMFC42002CView::GetDocument() const
   { return reinterpret_cast<CMFC42002CDoc*>(m_pDocument); }
#endif

