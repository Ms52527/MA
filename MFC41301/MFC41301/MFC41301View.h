
// MFC41301View.h : CMFC41301View ��Ľӿ�
//

#pragma once


class CMFC41301View : public CView
{
protected: // �������л�����
	CMFC41301View();
	DECLARE_DYNCREATE(CMFC41301View)

// ����
public:
	CMFC41301Doc* GetDocument() const;

// ����
public:
	CRect re;
	int a;

	

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC41301View();
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

#ifndef _DEBUG  // MFC41301View.cpp �еĵ��԰汾
inline CMFC41301Doc* CMFC41301View::GetDocument() const
   { return reinterpret_cast<CMFC41301Doc*>(m_pDocument); }
#endif

