
// MFC51101View.h : CMFC51101View ��Ľӿ�
//

#pragma once

class CMFC51101Set;

class CMFC51101View : public CRecordView
{
protected: // �������л�����
	CMFC51101View();
	DECLARE_DYNCREATE(CMFC51101View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC51101_FORM };
#endif
	CMFC51101Set* m_pSet;

// ����
public:
	CMFC51101Doc* GetDocument() const;

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
	virtual ~CMFC51101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	CString name;
	CString num;
	CString age;
	CString pic;
	CString high;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFC51101View.cpp �еĵ��԰汾
inline CMFC51101Doc* CMFC51101View::GetDocument() const
   { return reinterpret_cast<CMFC51101Doc*>(m_pDocument); }
#endif

