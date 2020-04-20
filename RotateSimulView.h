// RotateSimulView.h : CRotateSimulView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATESIMULVIEW_H__813AEDD4_6C97_4C83_8776_0FFBA85FF7E0__INCLUDED_)
#define AFX_ROTATESIMULVIEW_H__813AEDD4_6C97_4C83_8776_0FFBA85FF7E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRotateSimulView : public CView
{
protected: // シリアライズ機能のみから作成します。
	CRotateSimulView();
	DECLARE_DYNCREATE(CRotateSimulView)

// アトリビュート
public:
	CRotateSimulDoc* GetDocument();

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CRotateSimulView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CRotateSimulView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int			m_map[100][100];
	
	typedef struct _mypos
	{
		float x;
		float y;
	} myPos;
	myPos m_myPos;
	
	float		m_myAng;
	CBitmap		m_Obj[5], m_Blk, m_BackBmp;
	CDC			MemDC, BackDC;
	void Draw();

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CRotateSimulView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // RotateSimulView.cpp ファイルがデバッグ環境の時使用されます。
inline CRotateSimulDoc* CRotateSimulView::GetDocument()
   { return (CRotateSimulDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ROTATESIMULVIEW_H__813AEDD4_6C97_4C83_8776_0FFBA85FF7E0__INCLUDED_)
