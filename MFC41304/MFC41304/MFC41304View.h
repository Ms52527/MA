
// MFC41304View.h : CMFC41304View ��Ľӿ�
//

#pragma once


class CMFC41304View : public CView
{
protected: // �������л�����
	CMFC41304View();
	DECLARE_DYNCREATE(CMFC41304View)

// ����
public:
	CMFC41304Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC41304View();
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

#ifndef _DEBUG  // MFC41304View.cpp �еĵ��԰汾
inline CMFC41304Doc* CMFC41304View::GetDocument() const
   { return reinterpret_cast<CMFC41304Doc*>(m_pDocument); }
#endif

