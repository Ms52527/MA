
// MFC31701View.h : CMFC31701View ��Ľӿ�
//

#pragma once


class CMFC31701View : public CView
{
protected: // �������л�����
	CMFC31701View();
	DECLARE_DYNCREATE(CMFC31701View)

// ����
public:
	CMFC31701Doc* GetDocument() const;

// ����
public:
	BOOL set;
	
	double m;
	int count;
	int a, b, c, d;
	int distance;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC31701View();
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

#ifndef _DEBUG  // MFC31701View.cpp �еĵ��԰汾
inline CMFC31701Doc* CMFC31701View::GetDocument() const
   { return reinterpret_cast<CMFC31701Doc*>(m_pDocument); }
#endif

