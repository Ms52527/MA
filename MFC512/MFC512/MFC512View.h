
// MFC512View.h : CMFC512View ��Ľӿ�
//

#pragma once

class CMFC512Set;



class CMFC512View : public CRecordView
{
protected: // �������л�����
	CMFC512View();
	DECLARE_DYNCREATE(CMFC512View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC512_FORM };
#endif
	CMFC512Set* m_pSet;
	CString Path;

// ����
public:
	CMFC512Doc* GetDocument() const;
	void Drawpic(CString file);
	
	

// ����
public:
	CString   str,filename;
	int a;

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC512View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString Pname;
	
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC512View.cpp �еĵ��԰汾
inline CMFC512Doc* CMFC512View::GetDocument() const
   { return reinterpret_cast<CMFC512Doc*>(m_pDocument); }
#endif

