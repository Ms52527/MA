
// MFC41302View.h : CMFC41302View ��Ľӿ�
//

#pragma once


class CMFC41302View : public CView
{
protected: // �������л�����
	CMFC41302View();
	DECLARE_DYNCREATE(CMFC41302View)

// ����
public:
	CMFC41302Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC41302View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpen();
};

#ifndef _DEBUG  // MFC41302View.cpp �еĵ��԰汾
inline CMFC41302Doc* CMFC41302View::GetDocument() const
   { return reinterpret_cast<CMFC41302Doc*>(m_pDocument); }
#endif

