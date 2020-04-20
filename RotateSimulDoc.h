// RotateSimulDoc.h : CRotateSimulDoc クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATESIMULDOC_H__2B781DA0_A7D8_4D7A_BA56_41EC8304258B__INCLUDED_)
#define AFX_ROTATESIMULDOC_H__2B781DA0_A7D8_4D7A_BA56_41EC8304258B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRotateSimulDoc : public CDocument
{
protected: // シリアライズ機能のみから作成します。
	CRotateSimulDoc();
	DECLARE_DYNCREATE(CRotateSimulDoc)

// アトリビュート
public:

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CRotateSimulDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CRotateSimulDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CRotateSimulDoc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ROTATESIMULDOC_H__2B781DA0_A7D8_4D7A_BA56_41EC8304258B__INCLUDED_)
