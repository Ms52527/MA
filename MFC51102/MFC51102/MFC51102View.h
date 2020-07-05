
// MFC51102View.h : CMFC51102View ��Ľӿ�
//

#pragma once

class CMFC51102Set;

class CMFC51102View : public CRecordView
{
protected: // �������л�����
	CMFC51102View();
	DECLARE_DYNCREATE(CMFC51102View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC51102_FORM };
#endif
	CMFC51102Set* m_pSet;

// ����
public:
	CMFC51102Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC51102View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	CString name;
	CString num;
	CString age;
	CString pic;
	CString high;
};

#ifndef _DEBUG  // MFC51102View.cpp �еĵ��԰汾
inline CMFC51102Doc* CMFC51102View::GetDocument() const
   { return reinterpret_cast<CMFC51102Doc*>(m_pDocument); }
#endif

