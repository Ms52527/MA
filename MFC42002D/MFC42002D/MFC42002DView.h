
// MFC42002DView.h : CMFC42002DView ��Ľӿ�
//

#pragma once


class CMFC42002DView : public CView
{
protected: // �������л�����
	CMFC42002DView();
	DECLARE_DYNCREATE(CMFC42002DView)

// ����
public:
	CMFC42002DDoc* GetDocument() const;

// ����
public:
	CRect crect;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42002DView();
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

#ifndef _DEBUG  // MFC42002DView.cpp �еĵ��԰汾
inline CMFC42002DDoc* CMFC42002DView::GetDocument() const
   { return reinterpret_cast<CMFC42002DDoc*>(m_pDocument); }
#endif

