
// CGDlg.h : ͷ�ļ�
//

#pragma once


// CCGDlg �Ի���
class CCGDlg : public CDialogEx
{
// ����
public:
	CCGDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void DrawPixel(int x, int y, char type);
	int m_StartNodeX;
	int m_StartNodeY;
	int m_EndNodeX;
	int m_EndNodeY;
	afx_msg void OnBnClickedButton3();
};
