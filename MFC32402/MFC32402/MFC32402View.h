
// MFC32402View.h : CMFC32402View ��Ľӿ�
//

#pragma once


class CMFC32402View : public CView
{
protected: // �������л�����
	CMFC32402View();
	DECLARE_DYNCREATE(CMFC32402View)

// ����
public:
	CMFC32402Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC32402View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC32402View.cpp �еĵ��԰汾
inline CMFC32402Doc* CMFC32402View::GetDocument() const
   { return reinterpret_cast<CMFC32402Doc*>(m_pDocument); }
#endif

