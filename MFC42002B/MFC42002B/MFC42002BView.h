
// MFC42002BView.h : CMFC42002BView ��Ľӿ�
//

#pragma once


class CMFC42002BView : public CView
{
protected: // �������л�����
	CMFC42002BView();
	DECLARE_DYNCREATE(CMFC42002BView)

// ����
public:
	CMFC42002BDoc* GetDocument() const;

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
	virtual ~CMFC42002BView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdlg();
};

#ifndef _DEBUG  // MFC42002BView.cpp �еĵ��԰汾
inline CMFC42002BDoc* CMFC42002BView::GetDocument() const
   { return reinterpret_cast<CMFC42002BDoc*>(m_pDocument); }
#endif

