
// MFC50501View.h : CMFC50501View ��Ľӿ�
//

#pragma once

class CMFC50501Set;

class CMFC50501View : public CRecordView
{
protected: // �������л�����
	CMFC50501View();
	DECLARE_DYNCREATE(CMFC50501View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC50501_FORM };
#endif
	CMFC50501Set* m_pSet;

// ����
public:
	CMFC50501Doc* GetDocument() const;

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
	virtual ~CMFC50501View();
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
	double number;
	double age;
	double phone;
};

#ifndef _DEBUG  // MFC50501View.cpp �еĵ��԰汾
inline CMFC50501Doc* CMFC50501View::GetDocument() const
   { return reinterpret_cast<CMFC50501Doc*>(m_pDocument); }
#endif

