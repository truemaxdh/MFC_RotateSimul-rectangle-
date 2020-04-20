// RotateSimulView.cpp : CRotateSimulView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "RotateSimul.h"

#include "RotateSimulDoc.h"
#include "RotateSimulView.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView

IMPLEMENT_DYNCREATE(CRotateSimulView, CView)

BEGIN_MESSAGE_MAP(CRotateSimulView, CView)
	//{{AFX_MSG_MAP(CRotateSimulView)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView クラスの構築/消滅

CRotateSimulView::CRotateSimulView()
{
	// TODO: この場所に構築用のコードを追加してください。

}

CRotateSimulView::~CRotateSimulView()
{
}

BOOL CRotateSimulView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView クラスの描画

void CRotateSimulView::OnDraw(CDC* pDC)
{
	CRotateSimulDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView クラスの印刷

BOOL CRotateSimulView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CRotateSimulView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRotateSimulView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView クラスの診断

#ifdef _DEBUG
void CRotateSimulView::AssertValid() const
{
	CView::AssertValid();
}

void CRotateSimulView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRotateSimulDoc* CRotateSimulView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRotateSimulDoc)));
	return (CRotateSimulDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView クラスのメッセージ ハンドラ
void CRotateSimulView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	m_myPos.x = 50;
	m_myPos.y = 50;
	m_myAng = 0;

	m_Obj[0].LoadBitmap(IDB_OBJ1);
	m_Obj[1].LoadBitmap(IDB_OBJ2);
	m_Obj[2].LoadBitmap(IDB_OBJ3);
	m_Obj[3].LoadBitmap(IDB_OBJ4);
	m_Obj[4].LoadBitmap(IDB_OBJ5);
	m_Blk.LoadBitmap(IDB_BLK);

	srand( (unsigned)time( NULL ) );
	
	for(int i = 0; i<100; i++)
	{
		for(int j = 0; j<100; j++)
		{
			m_map[i][j] = rand() * 5 / RAND_MAX;
		}
	}

	CClientDC dc(this);
	MemDC.CreateCompatibleDC(&dc);
	BackDC.CreateCompatibleDC(&dc);
	
	CRect rect;
	GetClientRect(&rect);
	m_BackBmp.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
	
	BackDC.SelectObject(&m_BackBmp);
	SetTimer(0,100,NULL);
}

void CRotateSimulView::Draw()
{
	//①Nxをfloatに定義すると丸っぽくなる
	/*
	float ang,Nx,Ny;
	int i, Ox, Oy;
	*/
	//②Nxをintに定義すると四角形になる
	float	ang;
	int		i, Ox, Oy, Nx, Ny;
	CRect	rect;
	
	CClientDC dc(this);
	GetClientRect(rect);
	BackDC.FillRect(rect, new CBrush(RGB(255,255,255)));

	for(i = 0; i<30; i++)
	{
		for(ang = 0; ang < 3.141592 * 2; ang += 1.0f / i)
		{
			Ox = i * cos(ang) + m_myPos.x;
			Oy = i * sin(ang) + m_myPos.y;
			Nx = i * cos(ang - m_myAng);
			Ny = i * sin(ang - m_myAng);

			if(0 <= Ox && Ox <= 99 && 0 <= Oy && Oy <= 99)
				MemDC.SelectObject(&m_Obj[m_map[Oy][Ox]]);
			else
				MemDC.SelectObject(&m_Blk);
			BackDC.BitBlt(Nx * 16 + 240,Ny * 16 + 240,16,16,&MemDC,0,0,SRCCOPY);
		}
	}
	dc.BitBlt(0,0,480,480,&BackDC,0,0,SRCCOPY);
}

void CRotateSimulView::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	KillTimer(0);
	Draw();
	CView::OnTimer(nIDEvent);
}

void CRotateSimulView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	myPos myPosTemp = m_myPos;
	switch(nChar)
	{
	case VK_NUMPAD4:
	case VK_LEFT:
		m_myAng -=0.1;
		break;
	case VK_NUMPAD6:
	case VK_RIGHT:
		m_myAng +=0.1;
		break;
	case VK_NUMPAD8:
	case VK_UP:
		myPosTemp.x += cos(3.141592 * 1.5 + m_myAng);
		myPosTemp.y += sin(3.141592 * 1.5 + m_myAng);
		break;
	case VK_NUMPAD2:
	case VK_DOWN:
		myPosTemp.x -= cos(3.141592 * 1.5 + m_myAng);
		myPosTemp.y -= sin(3.141592 * 1.5 + m_myAng);
		break;
	}	
	if(0 <= myPosTemp.x && myPosTemp.x <= 99 && 0 <= myPosTemp.y && myPosTemp.y <= 99)
		m_myPos = myPosTemp;

	Draw();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
