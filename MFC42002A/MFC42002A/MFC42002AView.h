
// MFC42002AView.h : CMFC42002AView ��Ľӿ�
//

#pragma once


class CMFC42002AView : public CView
{
protected: // �������л�����
	CMFC42002AView();
	DECLARE_DYNCREATE(CMFC42002AView)

// ����
public:
	CMFC42002ADoc* GetDocument() const;

// ����
public:
	int X1,X2;
	int Y1,Y2;
	int flag;
	CRect A;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42002AView();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC42002AView.cpp �еĵ��԰汾
inline CMFC42002ADoc* CMFC42002AView::GetDocument() const
   { return reinterpret_cast<CMFC42002ADoc*>(m_pDocument); }
#endif

