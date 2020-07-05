
// MFC�ۺ�ʵ��Set.h: CMFC�ۺ�ʵ��Set ��Ľӿ�
//


#pragma once

// ���������� 2020��7��5��, 18:52

class CMFC�ۺ�ʵ��Set : public CRecordset
{
public:
	CMFC�ۺ�ʵ��Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMFC�ۺ�ʵ��Set)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	m_1;
	long	m_2;
	long	m_3;
	CStringW	m_4;
	long	m_5;
	long	m_6;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

