
// MFC0View.h : CMFC0View ��Ľӿ�
//

#pragma once


class CMFC0View : public CView
{
protected: // �������л�����
	CMFC0View();
	DECLARE_DYNCREATE(CMFC0View)

// ����
public:
	CMFC0Doc* GetDocument() const;

// ����
public:
	    int N;
		CArray<CRect, CRect>cr;
		int tim[5];
		bool set,tim0,tim1,tim2,tim3,tim4;


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC0View.cpp �еĵ��԰汾
inline CMFC0Doc* CMFC0View::GetDocument() const
   { return reinterpret_cast<CMFC0Doc*>(m_pDocument); }
#endif
