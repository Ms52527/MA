
// MFC�ۺ�ʵ��View.h : CMFC�ۺ�ʵ��View ��Ľӿ�
//

#pragma once

class CMFC�ۺ�ʵ��Set;

class CMFC�ۺ�ʵ��View : public CRecordView
{
protected: // �������л�����
	CMFC�ۺ�ʵ��View();
	DECLARE_DYNCREATE(CMFC�ۺ�ʵ��View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_FORM };
#endif
	CMFC�ۺ�ʵ��Set* m_pSet;

// ����
public:
	CMFC�ۺ�ʵ��Doc* GetDocument() const;

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
	virtual ~CMFC�ۺ�ʵ��View();
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
	CString name;
	long num;
	long age;
	CString pic;
	long high;
	long money;
	CString empty;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSort();
	afx_msg void Onsearch();
	afx_msg void OnAdd();
	afx_msg void OnModify();
	afx_msg void OnDelete();
	afx_msg void Onrecord();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC�ۺ�ʵ��View.cpp �еĵ��԰汾
inline CMFC�ۺ�ʵ��Doc* CMFC�ۺ�ʵ��View::GetDocument() const
   { return reinterpret_cast<CMFC�ۺ�ʵ��Doc*>(m_pDocument); }
#endif

