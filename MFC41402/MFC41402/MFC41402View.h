
// MFC41402View.h : CMFC41402View ��Ľӿ�
//

#pragma once


class CMFC41402View : public CView
{
protected: // �������л�����
	CMFC41402View();
	DECLARE_DYNCREATE(CMFC41402View)

// ����
public:
	CMFC41402Doc* GetDocument() const;

// ����
public:
	CString  a;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC41402View();
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

#ifndef _DEBUG  // MFC41402View.cpp �еĵ��԰汾
inline CMFC41402Doc* CMFC41402View::GetDocument() const
   { return reinterpret_cast<CMFC41402Doc*>(m_pDocument); }
#endif

