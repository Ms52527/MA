
// MFCApplication6��3.16ʵ�飩View.h : CMFCApplication6��316ʵ�飩View ��Ľӿ�
//

#pragma once


class CMFCApplication6��316ʵ�飩View : public CView
{
protected: // �������л�����
	CMFCApplication6��316ʵ�飩View();
	DECLARE_DYNCREATE(CMFCApplication6��316ʵ�飩View)

// ����
public:
	CMFCApplication6��316ʵ�飩Doc* GetDocument() const;

// ����
public:
	int a, b, c, d;
	BOOL set;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication6��316ʵ�飩View();
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

#ifndef _DEBUG  // MFCApplication6��3.16ʵ�飩View.cpp �еĵ��԰汾
inline CMFCApplication6��316ʵ�飩Doc* CMFCApplication6��316ʵ�飩View::GetDocument() const
   { return reinterpret_cast<CMFCApplication6��316ʵ�飩Doc*>(m_pDocument); }
#endif

