
// MFCA32401View.h : CMFCA32401View ��Ľӿ�
//

#pragma once


class CMFCA32401View : public CView
{
protected: // �������л�����
	CMFCA32401View();
	DECLARE_DYNCREATE(CMFCA32401View)

// ����
public:
	CMFCA32401Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCA32401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFCA32401View.cpp �еĵ��԰汾
inline CMFCA32401Doc* CMFCA32401View::GetDocument() const
   { return reinterpret_cast<CMFCA32401Doc*>(m_pDocument); }
#endif

