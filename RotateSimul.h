// RotateSimul.h : ROTATESIMUL アプリケーションのメイン ヘッダー ファイル
//

#if !defined(AFX_ROTATESIMUL_H__13EA510F_0075_4368_BA90_0E2E4A0A27B9__INCLUDED_)
#define AFX_ROTATESIMUL_H__13EA510F_0075_4368_BA90_0E2E4A0A27B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulApp:
// このクラスの動作の定義に関しては RotateSimul.cpp ファイルを参照してください。
//

class CRotateSimulApp : public CWinApp
{
public:
	CRotateSimulApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CRotateSimulApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
	//{{AFX_MSG(CRotateSimulApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ROTATESIMUL_H__13EA510F_0075_4368_BA90_0E2E4A0A27B9__INCLUDED_)
