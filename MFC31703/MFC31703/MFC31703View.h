
// MFC31703View.h : CMFC31703View ��Ľӿ�
//

#pragma once


class CMFC31703View : public CView
{
protected: // �������л�����
	CMFC31703View();
	DECLARE_DYNCREATE(CMFC31703View)

// ����
public:
	CMFC31703Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC31703View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC31703View.cpp �еĵ��԰汾
inline CMFC31703Doc* CMFC31703View::GetDocument() const
   { return reinterpret_cast<CMFC31703Doc*>(m_pDocument); }
#endif

