
// MFC42102View.h : CMFC42102View ��Ľӿ�
//

#pragma once


class CMFC42102View : public CView
{
protected: // �������л�����
	CMFC42102View();
	DECLARE_DYNCREATE(CMFC42102View)

// ����
public:
	CMFC42102Doc* GetDocument() const;

// ����
public:
	CString B;
	CString C;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42102View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnOpenpic();
};

#ifndef _DEBUG  // MFC42102View.cpp �еĵ��԰汾
inline CMFC42102Doc* CMFC42102View::GetDocument() const
   { return reinterpret_cast<CMFC42102Doc*>(m_pDocument); }
#endif

