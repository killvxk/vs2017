
// ManagerDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ManagerDemo.h"
#include "ManagerDemoDlg.h"
#include "afxdialogex.h"
#include "link.h"
#include <stdio.h>    
#include <winsock2.h> 
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib") 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MSG_TEST			WM_USER+100
#define MSG_DEV_EVENT		WM_USER+101
#define MSG_REFRESH_TREE	WM_USER+102

HWND	g_HWnd;

extern BlkDevNode*	g_pblkDevHead;

BlkDevData blkDev1[18] = {
		{1, L"fuck benkai 1", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
		{1, L"fuck benkai 1", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
		{1, L"fuck benkai 1", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
		{1, L"fuck benkai 1", L"App1", L"Cnt3", L"", L"", NULL},
		{1, L"fuck benkai 1", L"App2", L"", L"", L"", NULL},
		{1, L"fuck benkai 1", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
		{1, L"fuck benkai 1", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
		{1, L"fuck benkai 1", L"App3", L"Cnt3", L"cert1", L"exch", NULL}
};
BlkDevData blkDev2[18] = {
		{2, L"fuck benkai 2", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
		{2, L"fuck benkai 2", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
		{2, L"fuck benkai 2", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
};

BlkDevData blkDev3[18] = {
		{3, L"fuck benkai 3", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
		{3, L"fuck benkai 3", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
		{3, L"fuck benkai 3", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
};

BlkDevData blkDev4[18] = {
	{4, L"fuck benkai 4", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
	{4, L"fuck benkai 4", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
	{4, L"fuck benkai 4", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
};

BlkDevData blkDev5[18] = {
	{5, L"fuck benkai 5", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
	{5, L"fuck benkai 5", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
	{5, L"fuck benkai 5", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
};
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnMsgTest(WPARAM wParam, LPARAM lParam);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_MESSAGE(MSG_TEST, &CAboutDlg::OnMsgTest)
END_MESSAGE_MAP()


// CManagerDemoDlg dialog



CManagerDemoDlg::CManagerDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANAGERDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_DevTree);
}

BEGIN_MESSAGE_MAP(CManagerDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_GETINFOTIP, IDC_TREE1, &CManagerDemoDlg::OnGetinfotipTree1)
	ON_BN_CLICKED(IDC_BUTTON1, &CManagerDemoDlg::OnBnClickedButton1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CManagerDemoDlg::OnSelchangedTree1)
	ON_MESSAGE(MSG_DEV_EVENT, &CManagerDemoDlg::OnMsgDevEvent)
	ON_MESSAGE(MSG_REFRESH_TREE, &CManagerDemoDlg::OnMsgRefreshTree)
END_MESSAGE_MAP()


// CManagerDemoDlg message handlers

BOOL CManagerDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	HICON hIcon[6];
	hIcon[0] = theApp.LoadIcon(IDI_ICON2);
	hIcon[1] = theApp.LoadIcon(IDI_ICON3);
	hIcon[2] = theApp.LoadIcon(IDI_ICON6);
	hIcon[3] = theApp.LoadIcon(IDI_ICON7);
	hIcon[4] = theApp.LoadIcon(IDI_ICON6);
	hIcon[5] = theApp.LoadIcon(IDI_ICON5);

	m_imageList.Create(16, 16, ILC_COLOR32, 6, 3);
	for (int i = 0; i<6; i++)
	{
		m_imageList.Add(hIcon[i]);
	}

	m_DevTree.SetImageList(&m_imageList, TVSIL_NORMAL);
	m_csUserTips = _T("User");

	g_HWnd = this->m_hWnd;

	InitUserTree();
	ListenEvent();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CManagerDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CManagerDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CManagerDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CManagerDemoDlg::InitUserTree()
{
	m_hRoot = m_DevTree.InsertItem(_T("NULL"), INDEX_IMAGE_ROOT, INDEX_IMAGE_SEL);
//	m_userTreeCtrl.Expand(m_hRoot, TVE_EXPAND);

	HTREEITEM hDev;

	int s4Count = 18;
	for ( int i = 0; i<s4Count;i++ )
	{
		if ( NULL != *blkDev1[i].m_pszCert )
		{
			unsigned char* pu1Cert = new unsigned char[1000];
			memset(pu1Cert, 0x33, 1000);
			blkDev1[i].m_pu1Cert = pu1Cert;
		}
		hDev = InsertItem(blkDev1[i]);
	}
	ExpandItem(hDev);
	m_DevTree.SelectItem(hDev);

	for (int i = 0; i < s4Count; i++)
	{
		if (NULL != *blkDev2[i].m_pszCert)
		{
			unsigned char* pu1Cert = new unsigned char[1000];
			memset(pu1Cert, 0x33, 1000);
			blkDev2[i].m_pu1Cert = pu1Cert;
		}
		hDev = InsertItem(blkDev2[i]);
	}
	ExpandItem(hDev);
	m_DevTree.SelectItem(hDev);

	for (int i = 0; i < s4Count; i++)
	{
		if (NULL != *blkDev3[i].m_pszCert)
		{
			unsigned char* pu1Cert = new unsigned char[1000];
			memset(pu1Cert, 0x33, 1000);
			blkDev3[i].m_pu1Cert = pu1Cert;
		}
		hDev = InsertItem(blkDev3[i]);
	}
	ExpandItem(hDev);
	m_DevTree.SelectItem(hDev);

	for (int i = 0; i < s4Count; i++)
	{
		if (NULL != *blkDev4[i].m_pszCert)
		{
			unsigned char* pu1Cert = new unsigned char[1000];
			memset(pu1Cert, 0x33, 1000);
			blkDev4[i].m_pu1Cert = pu1Cert;
		}
		hDev = InsertItem(blkDev4[i]);
	}
	ExpandItem(hDev);
	m_DevTree.SelectItem(hDev);

	for (int i = 0; i < s4Count; i++)
	{
		if (NULL != *blkDev5[i].m_pszCert)
		{
			unsigned char* pu1Cert = new unsigned char[1000];
			memset(pu1Cert, 0x33, 1000);
			blkDev5[i].m_pu1Cert = pu1Cert;
		}
		hDev = InsertItem(blkDev5[i]);
	}
	ExpandItem(hDev);
	m_DevTree.SelectItem(hDev);
}

void CManagerDemoDlg::OnGetinfotipTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
// 	LPNMTVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMTVGETINFOTIP>(pNMHDR);
// 	// TODO: Add your control notification handler code here
// 	*pResult = 0;

	LPNMTVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMTVGETINFOTIP>(pNMHDR);
	// TODO: 在此加入控件通知处理程序代码
	*pResult = 0;
	//  设置提示信息
	NMTVGETINFOTIP* pTVTipInfo = (NMTVGETINFOTIP*)pNMHDR;
	HTREEITEM hRoot = m_DevTree.GetRootItem();
	CString csText;
	// 设置提示信息的2种方法：通过Item类型推断、依据SetItemdata设置的參数
	if (pTVTipInfo->hItem == hRoot)
		csText = _T("管理员 ");
	else if (pTVTipInfo->lParam == 1)
		csText = _T("部门");
	else
	{
		BSTR bstrTemp = (BSTR)(pTVTipInfo->lParam);
		csText = bstrTemp;
	}
	// 使用安全版本号的拷贝函数。csText获取的长度须要加1，包括结束符
	_tcscpy_s(pTVTipInfo->pszText, csText.GetLength() + 1, csText.GetBuffer());
}

HTREEITEM CManagerDemoDlg::InsertItem(BlkDevData blkDevData)
{
	HTREEITEM	hRoot = m_DevTree.GetRootItem();
	HTREEITEM	hDev, hApp, hCnt, hCert;

	hDev = hApp = hCnt = hCert = NULL;

	// 判断要插入的设备是否存在
	// TODO 是不是要判断SlotId或者Label是否为空
	if ( 0 == blkDevData.m_u4SlotId )
	{
		goto END;
	}
	hDev = m_DevTree.GetChildItem(hRoot);
	if (NULL == hDev) // 没有节点，那肯定要插入设备
	{
		hDev = m_DevTree.InsertItem(blkDevData.m_pszLabel, INDEX_IMAGE_DEV, INDEX_IMAGE_SEL, hRoot, TVI_LAST);
		m_DevTree.SetItemData(hDev, blkDevData.m_u4SlotId);
	}
	else
	{
		int		s4SlotId;
		BOOL	bExist = FALSE;

		while (NULL != hDev)
		{
			s4SlotId = m_DevTree.GetItemData(hDev);
			if (s4SlotId == blkDevData.m_u4SlotId)
			{
				bExist = TRUE;
				break;
			}
			hDev = m_DevTree.GetNextSiblingItem(hDev);
		}

		if (FALSE == bExist) // 不存在即将插入的设备，则插入
		{
			hDev = m_DevTree.InsertItem(blkDevData.m_pszLabel, INDEX_IMAGE_DEV, INDEX_IMAGE_SEL, hRoot, TVI_LAST);
			m_DevTree.SetItemData(hDev, blkDevData.m_u4SlotId);
		}
	}

	// 判断app
	if ( NULL == *blkDevData.m_pszApp )
	{
		goto END;
	}
	hApp = m_DevTree.GetChildItem(hDev);
	if (NULL == hApp)
	{
		hApp = m_DevTree.InsertItem(blkDevData.m_pszApp, INDEX_IMAGE_APP, INDEX_IMAGE_SEL, hDev, TVI_LAST);
	}
	else
	{
		CString	strAppInsert(blkDevData.m_pszApp);
		BOOL	bExist = FALSE;

		while (NULL != hApp)
		{
			CString strApp;
			strApp = m_DevTree.GetItemText(hApp);
			if (0 == strApp.Compare(strAppInsert))
			{
				bExist = TRUE;
				break;
			}
			hApp = m_DevTree.GetNextSiblingItem(hApp);
		}

		if (FALSE == bExist) // 不存在即将插入的设备，则插入
		{
			hApp = m_DevTree.InsertItem(blkDevData.m_pszApp, INDEX_IMAGE_APP, INDEX_IMAGE_SEL, hDev, TVI_LAST);
		}
	}
	
	// 判断Cnt
	if ( NULL == *blkDevData.m_pszCnt )
	{
		goto END;
	}
	hCnt = m_DevTree.GetChildItem(hApp);
	if (NULL == hCnt)
	{
		hCnt = m_DevTree.InsertItem(blkDevData.m_pszCnt, INDEX_IMAGE_CNT, INDEX_IMAGE_SEL, hApp, TVI_LAST);
	}
	else
	{
		CString	strCntInsert(blkDevData.m_pszCnt);
		BOOL	bExist = FALSE;

		while (NULL != hCnt)
		{
			CString strCnt;
			strCnt = m_DevTree.GetItemText(hCnt);
			if (0 == strCnt.Compare(strCntInsert))
			{
				bExist = TRUE;
				break;
			}
			hCnt = m_DevTree.GetNextSiblingItem(hCnt);
		}

		if (FALSE == bExist) // 不存在即将插入的设备，则插入
		{
			hCnt = m_DevTree.InsertItem(blkDevData.m_pszCnt, INDEX_IMAGE_CNT, INDEX_IMAGE_SEL, hApp, TVI_LAST);
		}
	}

	// 判断Cert
	if (NULL == *blkDevData.m_pszCert)
	{
		goto END;
	}
	hCert = m_DevTree.GetChildItem(hCnt);
	if (NULL == hCert)
	{
		hCert = m_DevTree.InsertItem(blkDevData.m_pszCert, INDEX_IMAGE_CERT, INDEX_IMAGE_SEL, hCnt, TVI_LAST);
	}
	else
	{
		CString	strCertInsert(blkDevData.m_pszCert);
		BOOL	bExist = FALSE;

		while (NULL != hCert)
		{
			CString strCert;
			strCert = m_DevTree.GetItemText(hCert);
			if (0 == strCert.Compare(strCertInsert))
			{
				bExist = TRUE;
				break;
			}
			hCert = m_DevTree.GetNextSiblingItem(hCert);
		}

		if (FALSE == bExist) // 不存在即将插入的设备，则插入
		{
			hCert = m_DevTree.InsertItem(blkDevData.m_pszCert, INDEX_IMAGE_CERT, INDEX_IMAGE_SEL, hCnt, TVI_LAST);
		}
	}

END:
	return hDev;
}

void CManagerDemoDlg::CollapseTree()
{

}

void CManagerDemoDlg::ExpandItem(HTREEITEM hItem)
{
	if ( NULL != hItem )
	{
		HTREEITEM	hItemChild = m_DevTree.GetChildItem(hItem); // 先找儿子
		if ( NULL != hItemChild )
		{
			m_DevTree.Expand(hItem, TVE_EXPAND); // 有儿子，则先展开自己
			ExpandItem(hItemChild); // 再展开儿子
			hItemChild = m_DevTree.GetNextSiblingItem(hItemChild); // 再找儿子多的兄弟
			ExpandItem(hItemChild); // 再展开儿子的兄弟
		}
	}
}

void CManagerDemoDlg::ExpandItem(int s4SlotId)
{

}

void CManagerDemoDlg::ResetTree()
{
	m_DevTree.DeleteAllItems();
}

int CManagerDemoDlg::GetLocal(BlkDevData* pblkDevData)
{
	HTREEITEM		hItemCur;
	int				s4Index, s4IndexSel, s4IndexTmp;
	CString			strData;
	BlkDevData*		pblkDevDataTmp = NULL;

	pblkDevDataTmp = new BlkDevData;
	memset(pblkDevDataTmp, 0x00, sizeof(BlkDevData));
	hItemCur = m_DevTree.GetSelectedItem();
	m_DevTree.GetItemImage(hItemCur, s4Index, s4IndexSel);

	s4IndexTmp = s4Index;
	if ( INDEX_IMAGE_CERT == s4IndexTmp )
	{
		strData = m_DevTree.GetItemText(hItemCur);
		wcscpy_s(pblkDevDataTmp->m_pszCert, 64, strData.GetBuffer(strData.GetLength()));
		strData.ReleaseBuffer();

		hItemCur = m_DevTree.GetParentItem(hItemCur);
		m_DevTree.GetItemImage(hItemCur, s4IndexTmp, s4IndexSel);
	}
	if ( INDEX_IMAGE_CNT == s4IndexTmp )
	{
		strData = m_DevTree.GetItemText(hItemCur);
		wcscpy_s(pblkDevDataTmp->m_pszCnt, 64, strData.GetBuffer(strData.GetLength()));
		strData.ReleaseBuffer();

		hItemCur = m_DevTree.GetParentItem(hItemCur);
		m_DevTree.GetItemImage(hItemCur, s4IndexTmp, s4IndexSel);
	}
	if ( INDEX_IMAGE_APP == s4IndexTmp )
	{
		strData = m_DevTree.GetItemText(hItemCur);
		wcscpy_s(pblkDevDataTmp->m_pszApp, 32, strData.GetBuffer(strData.GetLength()));
		strData.ReleaseBuffer();

		hItemCur = m_DevTree.GetParentItem(hItemCur);
		m_DevTree.GetItemImage(hItemCur, s4IndexTmp, s4IndexSel);
	}
	if ( INDEX_IMAGE_DEV == s4IndexTmp )
	{
		strData = m_DevTree.GetItemText(hItemCur);
		wcscpy_s(pblkDevDataTmp->m_pszLabel, 64, strData.GetBuffer(strData.GetLength()));
		strData.ReleaseBuffer();
		pblkDevDataTmp->m_u4SlotId = m_DevTree.GetItemData(hItemCur);

		hItemCur = m_DevTree.GetParentItem(hItemCur);
		m_DevTree.GetItemImage(hItemCur, s4IndexTmp, s4IndexSel);
	}

	if ( NULL != pblkDevDataTmp )
	{
		memcpy(pblkDevData, pblkDevDataTmp, sizeof(BlkDevData));
		delete pblkDevDataTmp;
	}
	return s4Index;
}

void CManagerDemoDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString strData;
	BlkDevData	blkDevData;
	int			s4Index;

	s4Index = GetLocal(&blkDevData);

	if ( INDEX_IMAGE_ROOT == s4Index )
	{
		strData.Format(_T("%s"), L"NULL");
	}
	else
	{
		strData.Format(_T("Level:%d\nSlotId:%d\nLabel:%s\nApp:%s\nCnt:%s\nCert:%s"), s4Index, blkDevData.m_u4SlotId, \
			(NULL == *blkDevData.m_pszLabel) ? L"NULL" : blkDevData.m_pszLabel, \
			(NULL == *blkDevData.m_pszApp) ? L"NULL" : blkDevData.m_pszApp, \
			(NULL == *blkDevData.m_pszCnt) ? L"NULL" : blkDevData.m_pszCnt , \
			(NULL == *blkDevData.m_pszCert) ? L"NULL" : blkDevData.m_pszCert);
	}

	MessageBox(strData);
}


void CManagerDemoDlg::OnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here

	//m_DevTree.SetBkColor()

	*pResult = 0;
}

UINT ListenThreadProc(LPVOID)
{
	//初始化WSA windows自带的socket
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//创建服务端套接字
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	//服务端需要绑定ip和端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY; //监听任意的地址
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) //将服务端套接字与上面的ip和端口绑定 
	{
		printf("bind error !");
	}

	//开始监听
	if (listen(slisten, 5) == SOCKET_ERROR)  //用listen（） 监听前面绑定好的slisten套接字
	{
		printf("listen error !");
		return 0;
	}

	//循环接受数据
	SOCKET sClient;  //创建连接的套接字
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr); //用于接受客户端地址
	char revData[255]; //存储接受的数据
	while (1)
	{
		printf("等待连接...\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen); //和客户端 connect（）对应
		if (sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}
		char sendBuf[20] = { '\0' };
		printf("接受到一个连接：%s \r\n", inet_ntop(AF_INET, (void*)&remoteAddr.sin_addr, sendBuf, 16));

		//数据接收
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			printf(revData);
		}

		//发送数据给客户端
		const char *sendData = "recved";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);  //关闭已接通的套接字
	}


	closesocket(slisten); //关闭监听的套接字
	WSACleanup();
	return 0;
}

void CManagerDemoDlg::ListenEvent()
{
	AfxBeginThread(ListenThreadProc, NULL);
}

afx_msg LRESULT CManagerDemoDlg::OnMsgDevEvent(WPARAM wParam, LPARAM lParam)
{
	BlkDevData*	pblkDevData;
	int			s4OpCode;

	do 
	{
		if (NULL == wParam || NULL == lParam)
		{
			continue;
		}

		s4OpCode = (int)wParam;
		pblkDevData = (BlkDevData*)lParam;

		if ( OP_CODE_INSERT == s4OpCode )
		{
			AddDevNode(pblkDevData);
		} 
		if ( OP_CODE_REMOVE == s4OpCode )
		{
			DeleteDev(pblkDevData->m_u4SlotId);
		}

		::PostMessage(g_HWnd, MSG_REFRESH_TREE, NULL, NULL);
	} while (FALSE);

	return 0;
}

afx_msg LRESULT CAboutDlg::OnMsgTest(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

BOOL CManagerDemoDlg::RemoveDev(int s4SlotId)
{

	return TRUE;
}

afx_msg LRESULT CManagerDemoDlg::OnMsgRefreshTree(WPARAM wParam, LPARAM lParam)
{
	BlkDevNode*	pblkDevNode = NULL;
	
	ResetTree();
	
	pblkDevNode = g_pblkDevHead;
	if ( NULL != pblkDevNode->pNext )
	{
		InsertItem(pblkDevNode->m_blkDevData);
	}

	return 0;
}
