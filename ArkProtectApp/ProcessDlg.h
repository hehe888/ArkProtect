#pragma once
#include "afxcmn.h"
#include "Global.hpp"
#include "ProcessCore.h"
#include "ProcessInfoDlg.h"

// CProcessDlg �Ի���

class CProcessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProcessDlg)

public:
	CProcessDlg(CWnd* pParent = NULL, ArkProtect::CGlobal *GlobalObject = NULL);   // ��׼���캯��
	virtual ~CProcessDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCESS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnLvnItemchangedProcessList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickProcessList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnProcessFreshen();
	afx_msg void OnProcessModule();

	DECLARE_MESSAGE_MAP()
public:
	
	void APInitializeProcessList();

	void APLoadProcessList();

	void APInitializeProcessInfoDlg(ArkProtect::eProcessInfoKind ProcessInfoKind);

	void AddProcessFileIcon(WCHAR * wzProcessPath);

	


	CImageList m_ProcessIconList;   // ����ͼ��
	CListCtrl  m_ProcessListCtrl;   // ListControl

	

	ArkProtect::CGlobal      *m_Global;
	ArkProtect::CProcessCore m_Process;

	
	static UINT32     m_SortColumn;
	static BOOL       m_bSortOrder;  // ��¼����˳��
	
	
	
};


int CALLBACK APProcessListCompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);