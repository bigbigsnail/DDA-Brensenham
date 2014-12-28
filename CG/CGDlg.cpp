
// CGDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CG.h"
#include "CGDlg.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <cstdio>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int StartNodeX, StartNodeY, EndNodeX, EndNodeY;
int	x, y;
double  DeltaX, DeltaY, tempX, tempY;
double slope;
char Algorithm;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCGDlg 对话框



CCGDlg::CCGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCGDlg::IDD, pParent)
	, m_StartNodeX(0)
	, m_StartNodeY(0)
	, m_EndNodeX(0)
	, m_EndNodeY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StartNodeX);
	DDX_Text(pDX, IDC_EDIT2, m_StartNodeY);
	DDX_Text(pDX, IDC_EDIT3, m_EndNodeX);
	DDX_Text(pDX, IDC_EDIT4, m_EndNodeY);
}

BEGIN_MESSAGE_MAP(CCGDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCGDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCGDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCGDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCGDlg 消息处理程序

BOOL CCGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCGDlg::OnBnClickedButton1()//DrawMesh
{
	// TODO:  在此添加控件通知处理程序代码

	CClientDC pDC(this);
	CPen myPen;
	myPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *pOldPen = pDC.SelectObject(&myPen);
	for (int i = 0; i <= 54; i++)//绘制网格
	{
		pDC.MoveTo(100, 20 * i + 100);
		pDC.LineTo(1800, 20 * i + 100);
	}
	for (int i = 0; i <= 85; i++)//绘制网格
	{
		pDC.MoveTo(20 * i + 100, 100);
		pDC.LineTo(20 * i + 100, 1180);
	}
	/*POINT P1, P2;
	P1.x = 0;
	P1.y = 0;
	P2.x = 100;
	P1.y = 100;
	CRect rectangle(P1, P2);
	CBrush Brush(RGB(0, 0, 0));
	pDC.FillRect(&rectangle, &Brush);
	*/
}

//填充每一个像素，x和y为坐标，type用于判断以选择填充颜色
void CCGDlg::DrawPixel(int x, int y, char type)
{
	CClientDC pDC(this);

	POINT P1, P2;
	P1.x = x;
	P1.y = y;
	P2.x = x + 20;
	P2.y = y + 20;
	CRect rectangle(P1, P2);
	CBrush Brush1(RGB(45, 175, 233));
	CBrush Brush2(RGB(255, 127, 0));

	if (type == 'D')
	{
		pDC.FillRect(&rectangle, &Brush1);
	}
	else if (type == 'B')
	{
		pDC.FillRect(&rectangle, &Brush2);
	}
}


void CCGDlg::OnBnClickedButton2()//DDA
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

	Algorithm = 'D';
	//进行输入坐标到屏幕坐标系的变换，并画出起点和终点
	StartNodeX = 100 + 20 * m_StartNodeX;
	StartNodeY = 1180 - 20 * (m_StartNodeY + 1);
	EndNodeX = 100 + 20 * m_EndNodeX;
	EndNodeY = 1180 - 20 * (m_EndNodeY + 1);
	DrawPixel(StartNodeX, StartNodeY, Algorithm);
	DrawPixel(EndNodeX, EndNodeY, Algorithm);

	tempX = (double)m_StartNodeX;//记录x,y位置
	tempY = (double)m_StartNodeY;
	x = StartNodeX;//记录在屏幕坐标系中的位置
	y = StartNodeY;
	DeltaX = m_EndNodeX - m_StartNodeX;
	if (m_EndNodeY >= m_StartNodeY)
	{
		DeltaY = (double)(m_EndNodeY - m_StartNodeY);
	}
	else
	{
		DeltaY = (double)(m_StartNodeY - m_EndNodeY);
	}
	slope = (double)(m_EndNodeY - m_StartNodeY) / (double)(m_EndNodeX - m_StartNodeX);//计算斜率
	
	if (slope <= 1 && slope >= -1)//斜率绝对值小于1
	{
		for (int i = 1; i < DeltaX; i++)
		{
			x = StartNodeX + i * 20;
			tempY = tempY + slope;
			y = 1180 - 20 * ((int)tempY + 1);
			DrawPixel(x, y, Algorithm);
		}
	}
	else if (slope > 1)//斜率大于1
	{
		for (int i = 1; i < DeltaY; i++)
		{
			y = StartNodeY - 20 * i;
			tempX = tempX + (1.0 / slope);
			x = 100 + 20 * (int)tempX;
			DrawPixel(x, y, Algorithm);
		}
	}
	else if (slope < -1)//斜率大于-1
	{
		for (int i = 1; i < DeltaY; i++)
		{
			y = StartNodeY + 20 * i;
			tempX = tempX + (1.0 / (-slope));
			x = 100 + 20 * (int)tempX;
			DrawPixel(x, y, Algorithm);
		}
	}
	
	UpdateData(FALSE);
}


void CCGDlg::OnBnClickedButton3()//Brensenham
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

	double Pk, PositiveDelta;
	bool PositiveDeltaY;

	Algorithm = 'B';
	//进行输入坐标到屏幕坐标系的变换，并画出起点和终点
	StartNodeX = 100 + 20 * m_StartNodeX;
	StartNodeY = 1180 - 20 * (m_StartNodeY + 1);
	EndNodeX = 100 + 20 * m_EndNodeX;
	EndNodeY = 1180 - 20 * (m_EndNodeY + 1);
	DrawPixel(StartNodeX, StartNodeY, Algorithm);
	DrawPixel(EndNodeX, EndNodeY, Algorithm);

	DeltaX = (double)m_EndNodeX - m_StartNodeX;
	DeltaY = (double)m_EndNodeY - m_StartNodeY;
	tempX = (double)m_StartNodeX;//记录x,y位置
	tempY = (double)m_StartNodeY;
	x = StartNodeX;//记录在屏幕坐标系中的位置
	y = StartNodeY;
	slope = (double)(m_EndNodeY - m_StartNodeY) / (double)(m_EndNodeX - m_StartNodeX);//计算斜率
	
	if (DeltaY >= 0)
	{
		PositiveDeltaY = true;
		PositiveDelta = DeltaY;
	}
	else
	{
		PositiveDeltaY = false;
		PositiveDelta = -DeltaY;
	}


	if (slope <= 1 && slope >= 0)//斜率在区间[0,1]
	{
		Pk = 2 * DeltaY - DeltaX;//计算决策函数初值
		for (int i = 1; i < (m_EndNodeX - m_StartNodeX); i++)
		{
			if (Pk < 0)
			{
				Pk = Pk + 2 * DeltaY;
				x = StartNodeX + i * 20;
				tempY = tempY;
				y = 1180 - 20 * ((int)tempY + 1);
				DrawPixel(x, y, Algorithm);
			}
			else
			{
				Pk = Pk + 2 * DeltaY - 2 * DeltaX;
				x = StartNodeX + i * 20;
				tempY = tempY + 1;
				y = 1180 - 20 * ((int)tempY + 1);
				DrawPixel(x, y, Algorithm);
			}
		}
	}
	else if (slope < 0 && slope >= -1)//斜率在区间[-1,0)
	{
		Pk = 2 * (-DeltaY) - DeltaX;//计算决策函数初值
		for (int i = 1; i < (m_EndNodeX - m_StartNodeX); i++)
		{
			if (Pk < 0)
			{
				Pk = Pk + 2 * (-DeltaY);
				x = StartNodeX + i * 20;
				tempY = tempY;
				y = 1180 - 20 * ((int)tempY + 1);
				DrawPixel(x, y, Algorithm);
			}
			else
			{
				Pk = Pk + 2 * (-DeltaY) - 2 * DeltaX;
				x = StartNodeX + i * 20;
				tempY = tempY - 1;
				y = 1180 - 20 * ((int)tempY + 1);
				DrawPixel(x, y, Algorithm);
			}
		}
	}
	else if (slope > 1)//斜率大于1
	{
		Pk = 2 * DeltaX - DeltaY;//计算决策函数初值
		for (int i = 1; i < PositiveDelta; i++)
		{
			if (Pk <= 0)
			{
				Pk = Pk + 2 * DeltaX;
				y = StartNodeY - 20 * i;
				tempX = tempX;
				x = 100 + (int)tempX * 20;
				DrawPixel(x, y, Algorithm);
			}
			else
			{
				Pk = Pk + 2 * DeltaX - 2 * DeltaY;
				y = StartNodeY - 20 * i;
				tempX = tempX + 1;
				x = 100 + (int)tempX * 20;
				DrawPixel(x, y, Algorithm);
			}
		}
	}
	else if (slope < -1)//斜率小于-1
	{
		Pk = 2 * DeltaX - (-DeltaY);//计算决策函数初值
		for (int i = 1; i < PositiveDelta; i++)
		{
			if (Pk <= 0)
			{
				Pk = Pk + 2 * DeltaX;
				y = StartNodeY + 20 * i;
				tempX = tempX;
				x = 100 + (int)tempX * 20;
				DrawPixel(x, y, Algorithm);
			}
			else
			{
				Pk = Pk + 2 * DeltaX - 2 * (-DeltaY);
				y = StartNodeY + 20 * i;
				tempX = tempX + 1;
				x = 100 + (int)tempX * 20;
				DrawPixel(x, y, Algorithm);
			}
		}
	}

	UpdateData(FALSE);
}
