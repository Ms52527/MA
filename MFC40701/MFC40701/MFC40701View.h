
// MFC40701View.h : CMFC40701View ��Ľӿ�
//

#pragma once


class CMFC40701View : public CView
{
protected: // �������л�����
	CMFC40701View();
	DECLARE_DYNCREATE(CMFC40701View)

// ����
public:
	CMFC40701Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC40701View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC40701View.cpp �еĵ��԰汾
inline CMFC40701Doc* CMFC40701View::GetDocument() const
   { return reinterpret_cast<CMFC40701Doc*>(m_pDocument); }
#endif

