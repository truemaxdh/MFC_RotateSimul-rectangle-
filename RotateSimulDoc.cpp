// RotateSimulDoc.cpp : CRotateSimulDoc クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "RotateSimul.h"

#include "RotateSimulDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc

IMPLEMENT_DYNCREATE(CRotateSimulDoc, CDocument)

BEGIN_MESSAGE_MAP(CRotateSimulDoc, CDocument)
	//{{AFX_MSG_MAP(CRotateSimulDoc)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc クラスの構築/消滅

CRotateSimulDoc::CRotateSimulDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CRotateSimulDoc::~CRotateSimulDoc()
{
}

BOOL CRotateSimulDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc シリアライゼーション

void CRotateSimulDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください。
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください。
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc クラスの診断

#ifdef _DEBUG
void CRotateSimulDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRotateSimulDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc コマンド
