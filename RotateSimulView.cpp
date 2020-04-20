// RotateSimulView.cpp : CRotateSimulView �N���X�̓���̒�`���s���܂��B
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
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView �N���X�̍\�z/����

CRotateSimulView::CRotateSimulView()
{
	// TODO: ���̏ꏊ�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRotateSimulView::~CRotateSimulView()
{
}

BOOL CRotateSimulView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView �N���X�̕`��

void CRotateSimulView::OnDraw(CDC* pDC)
{
	CRotateSimulDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView �N���X�̈��

BOOL CRotateSimulView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �f�t�H���g�̈������
	return DoPreparePrinting(pInfo);
}

void CRotateSimulView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRotateSimulView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView �N���X�̐f�f

#ifdef _DEBUG
void CRotateSimulView::AssertValid() const
{
	CView::AssertValid();
}

void CRotateSimulView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRotateSimulDoc* CRotateSimulView::GetDocument() // ��f�o�b�O �o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRotateSimulDoc)));
	return (CRotateSimulDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulView �N���X�̃��b�Z�[�W �n���h��
void CRotateSimulView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
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
	//�@Nx��float�ɒ�`����Ɗۂ��ۂ��Ȃ�
	/*
	float ang,Nx,Ny;
	int i, Ox, Oy;
	*/
	//�ANx��int�ɒ�`����Ǝl�p�`�ɂȂ�
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
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	KillTimer(0);
	Draw();
	CView::OnTimer(nIDEvent);
}

void CRotateSimulView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
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
