
// MFC31702View.h : CMFC31702View ��Ľӿ�
//

#pragma once


class CMFC31702View : public CView
{
protected: // �������л�����
	CMFC31702View();
	DECLARE_DYNCREATE(CMFC31702View)

// ����
public:
	CMFC31702Doc* GetDocument() const;

// ����
public:
	

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC31702View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC31702View.cpp �еĵ��԰汾
inline CMFC31702Doc* CMFC31702View::GetDocument() const
   { return reinterpret_cast<CMFC31702Doc*>(m_pDocument); }
#endif

