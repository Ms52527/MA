
// MFC501801View.h : CMFC501801View ��Ľӿ�
//

#pragma once

class CMFC501801Set;

class CMFC501801View : public CRecordView
{
protected: // �������л�����
	CMFC501801View();
	DECLARE_DYNCREATE(CMFC501801View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC501801_FORM };
#endif
	CMFC501801Set* m_pSet;

// ����
public:
	CMFC501801Doc* GetDocument() const;

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
	virtual ~CMFC501801View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	CString name;
	CString num;
	CString age;
	CString pic;
	CString high;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFC501801View.cpp �еĵ��԰汾
inline CMFC501801Doc* CMFC501801View::GetDocument() const
   { return reinterpret_cast<CMFC501801Doc*>(m_pDocument); }
#endif

