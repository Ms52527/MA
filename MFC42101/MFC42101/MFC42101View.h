
// MFC42101View.h : CMFC42101View ��Ľӿ�
//

#pragma once


class CMFC42101View : public CView
{
protected: // �������л�����
	CMFC42101View();
	DECLARE_DYNCREATE(CMFC42101View)

// ����
public:
	CMFC42101Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC42101View();
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

	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // MFC42101View.cpp �еĵ��԰汾
inline CMFC42101Doc* CMFC42101View::GetDocument() const
   { return reinterpret_cast<CMFC42101Doc*>(m_pDocument); }
#endif

