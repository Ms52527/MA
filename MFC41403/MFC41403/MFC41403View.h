
// MFC41403View.h : CMFC41403View ��Ľӿ�
//

#pragma once


class CMFC41403View : public CView
{
protected: // �������л�����
	CMFC41403View();
	DECLARE_DYNCREATE(CMFC41403View)

// ����
public:
	CMFC41403Doc* GetDocument() const;

// ����
public:
	CString a;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC41403View();
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
	afx_msg void OnOpendlg();
};

#ifndef _DEBUG  // MFC41403View.cpp �еĵ��԰汾
inline CMFC41403Doc* CMFC41403View::GetDocument() const
   { return reinterpret_cast<CMFC41403Doc*>(m_pDocument); }
#endif

