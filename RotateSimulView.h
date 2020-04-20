// RotateSimulView.h : CRotateSimulView �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATESIMULVIEW_H__813AEDD4_6C97_4C83_8776_0FFBA85FF7E0__INCLUDED_)
#define AFX_ROTATESIMULVIEW_H__813AEDD4_6C97_4C83_8776_0FFBA85FF7E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRotateSimulView : public CView
{
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CRotateSimulView();
	DECLARE_DYNCREATE(CRotateSimulView)

// �A�g���r���[�g
public:
	CRotateSimulDoc* GetDocument();

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CRotateSimulView)
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷��ۂɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
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

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CRotateSimulView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // RotateSimulView.cpp �t�@�C�����f�o�b�O���̎��g�p����܂��B
inline CRotateSimulDoc* CRotateSimulView::GetDocument()
   { return (CRotateSimulDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ROTATESIMULVIEW_H__813AEDD4_6C97_4C83_8776_0FFBA85FF7E0__INCLUDED_)
