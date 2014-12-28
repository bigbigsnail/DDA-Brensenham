
// CGDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCGDlg �Ի���



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


// CCGDlg ��Ϣ�������

BOOL CCGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCGDlg::OnBnClickedButton1()//DrawMesh
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CClientDC pDC(this);
	CPen myPen;
	myPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *pOldPen = pDC.SelectObject(&myPen);
	for (int i = 0; i <= 54; i++)//��������
	{
		pDC.MoveTo(100, 20 * i + 100);
		pDC.LineTo(1800, 20 * i + 100);
	}
	for (int i = 0; i <= 85; i++)//��������
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

//���ÿһ�����أ�x��yΪ���꣬type�����ж���ѡ�������ɫ
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	Algorithm = 'D';
	//�����������굽��Ļ����ϵ�ı任�������������յ�
	StartNodeX = 100 + 20 * m_StartNodeX;
	StartNodeY = 1180 - 20 * (m_StartNodeY + 1);
	EndNodeX = 100 + 20 * m_EndNodeX;
	EndNodeY = 1180 - 20 * (m_EndNodeY + 1);
	DrawPixel(StartNodeX, StartNodeY, Algorithm);
	DrawPixel(EndNodeX, EndNodeY, Algorithm);

	tempX = (double)m_StartNodeX;//��¼x,yλ��
	tempY = (double)m_StartNodeY;
	x = StartNodeX;//��¼����Ļ����ϵ�е�λ��
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
	slope = (double)(m_EndNodeY - m_StartNodeY) / (double)(m_EndNodeX - m_StartNodeX);//����б��
	
	if (slope <= 1 && slope >= -1)//б�ʾ���ֵС��1
	{
		for (int i = 1; i < DeltaX; i++)
		{
			x = StartNodeX + i * 20;
			tempY = tempY + slope;
			y = 1180 - 20 * ((int)tempY + 1);
			DrawPixel(x, y, Algorithm);
		}
	}
	else if (slope > 1)//б�ʴ���1
	{
		for (int i = 1; i < DeltaY; i++)
		{
			y = StartNodeY - 20 * i;
			tempX = tempX + (1.0 / slope);
			x = 100 + 20 * (int)tempX;
			DrawPixel(x, y, Algorithm);
		}
	}
	else if (slope < -1)//б�ʴ���-1
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	double Pk, PositiveDelta;
	bool PositiveDeltaY;

	Algorithm = 'B';
	//�����������굽��Ļ����ϵ�ı任�������������յ�
	StartNodeX = 100 + 20 * m_StartNodeX;
	StartNodeY = 1180 - 20 * (m_StartNodeY + 1);
	EndNodeX = 100 + 20 * m_EndNodeX;
	EndNodeY = 1180 - 20 * (m_EndNodeY + 1);
	DrawPixel(StartNodeX, StartNodeY, Algorithm);
	DrawPixel(EndNodeX, EndNodeY, Algorithm);

	DeltaX = (double)m_EndNodeX - m_StartNodeX;
	DeltaY = (double)m_EndNodeY - m_StartNodeY;
	tempX = (double)m_StartNodeX;//��¼x,yλ��
	tempY = (double)m_StartNodeY;
	x = StartNodeX;//��¼����Ļ����ϵ�е�λ��
	y = StartNodeY;
	slope = (double)(m_EndNodeY - m_StartNodeY) / (double)(m_EndNodeX - m_StartNodeX);//����б��
	
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


	if (slope <= 1 && slope >= 0)//б��������[0,1]
	{
		Pk = 2 * DeltaY - DeltaX;//������ߺ�����ֵ
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
	else if (slope < 0 && slope >= -1)//б��������[-1,0)
	{
		Pk = 2 * (-DeltaY) - DeltaX;//������ߺ�����ֵ
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
	else if (slope > 1)//б�ʴ���1
	{
		Pk = 2 * DeltaX - DeltaY;//������ߺ�����ֵ
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
	else if (slope < -1)//б��С��-1
	{
		Pk = 2 * DeltaX - (-DeltaY);//������ߺ�����ֵ
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
