
// MFCUsingWinLIBDLLView.h : CMFCUsingWinLIBDLLView ��Ľӿ�
//

#pragma once


class CMFCUsingWinLIBDLLView : public CView
{
protected: // �������л�����
	CMFCUsingWinLIBDLLView();
	DECLARE_DYNCREATE(CMFCUsingWinLIBDLLView)

// ����
public:
	CMFCUsingWinLIBDLLDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCUsingWinLIBDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCUsingWinLIBDLLView.cpp �еĵ��԰汾
inline CMFCUsingWinLIBDLLDoc* CMFCUsingWinLIBDLLView::GetDocument() const
   { return reinterpret_cast<CMFCUsingWinLIBDLLDoc*>(m_pDocument); }
#endif

