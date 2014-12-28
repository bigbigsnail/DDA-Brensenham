
// CGDlg.h : 头文件
//

#pragma once


// CCGDlg 对话框
class CCGDlg : public CDialogEx
{
// 构造
public:
	CCGDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
