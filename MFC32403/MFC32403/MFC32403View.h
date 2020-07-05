
// MFC32403View.h : CMFC32403View ��Ľӿ�
//

#pragma once


class CMFC32403View : public CView
{
protected: // �������л�����
	CMFC32403View();
	DECLARE_DYNCREATE(CMFC32403View)

// ����
public:
	CMFC32403Doc* GetDocument() const;

// ����
public:
	int dx, dy, ux, uy;
	int a;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC32403View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC32403View.cpp �еĵ��԰汾
inline CMFC32403Doc* CMFC32403View::GetDocument() const
   { return reinterpret_cast<CMFC32403Doc*>(m_pDocument); }
#endif

