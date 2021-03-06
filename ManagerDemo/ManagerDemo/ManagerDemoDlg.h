
// ManagerDemoDlg.h : header file
//

#pragma once

#include "link.h"

// typedef enum ENTREELEVELTAG
// {
// 	INDEX_IMAGE_ROOT = 0,
// 	INDEX_IMAGE_DEV,
// 	INDEX_IMAGE_APP,
// 	INDEX_IMAGE_CNT,
// 	INDEX_IMAGE_CERT
// }EnTreeLevel;

#define		INDEX_IMAGE_ROOT	0
#define		INDEX_IMAGE_DEV		1
#define		INDEX_IMAGE_APP		2
#define		INDEX_IMAGE_CNT		3
#define		INDEX_IMAGE_CERT	4
#define		INDEX_IMAGE_SEL		5

#define OP_CODE_WAIT			0
#define OP_CODE_INSERT			1
#define OP_CODE_REMOVE			2

typedef struct BLKTRANSPROTOCOLTAG
{
	int			m_s4OpCode;
	BlkDevData	m_blkDevData;
}BlkTransProtocol;

// CManagerDemoDlg dialog
class CManagerDemoDlg : public CDialogEx
{
// Construction
public:
	CManagerDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANAGERDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_DevTree;
	CImageList	m_imageList;
	void InitUserTree();
	CString m_csUserTips;
	afx_msg void OnGetinfotipTree1(NMHDR *pNMHDR, LRESULT *pResult);
	HTREEITEM	m_hRoot;
	HTREEITEM InsertItem(BlkDevData blkDevData); //返回设备节点
	BOOL RemoveDev(int s4SlotId);
	void CollapseTree();
	void ExpandItem(HTREEITEM hItem);
	void ExpandItem(int s4SlotId);
	void ResetTree();
	int GetLocal(BlkDevData* pblkDevData);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	void ListenEvent();
protected:
	afx_msg LRESULT OnMsgDevEvent(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMsgRefreshTree(WPARAM wParam, LPARAM lParam);
};
