
// MFC50401View.h : CMFC50401View ��Ľӿ�
//

#pragma once


class CMFC50401View : public CView
{
protected: // �������л�����
	CMFC50401View();
	DECLARE_DYNCREATE(CMFC50401View)

// ����
public:
	CMFC50401Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC50401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC50401View.cpp �еĵ��԰汾
inline CMFC50401Doc* CMFC50401View::GetDocument() const
   { return reinterpret_cast<CMFC50401Doc*>(m_pDocument); }
#endif

