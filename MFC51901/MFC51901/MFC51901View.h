
// MFC51901View.h : CMFC51901View ��Ľӿ�
//

#pragma once

class CMFC51901Set;

class CMFC51901View : public CRecordView
{
protected: // �������л�����
	CMFC51901View();
	DECLARE_DYNCREATE(CMFC51901View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC51901_FORM };
#endif
	CMFC51901Set* m_pSet;

// ����
public:
	CMFC51901Doc* GetDocument() const;

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
	virtual ~CMFC51901View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long P;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3ADD();
	afx_msg void OnBnClickedButton4MODIFY();
};

#ifndef _DEBUG  // MFC51901View.cpp �еĵ��԰汾
inline CMFC51901Doc* CMFC51901View::GetDocument() const
   { return reinterpret_cast<CMFC51901Doc*>(m_pDocument); }
#endif

