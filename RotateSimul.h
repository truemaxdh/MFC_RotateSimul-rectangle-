// RotateSimul.h : ROTATESIMUL �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#if !defined(AFX_ROTATESIMUL_H__13EA510F_0075_4368_BA90_0E2E4A0A27B9__INCLUDED_)
#define AFX_ROTATESIMUL_H__13EA510F_0075_4368_BA90_0E2E4A0A27B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� RotateSimul.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CRotateSimulApp : public CWinApp
{
public:
	CRotateSimulApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CRotateSimulApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	//{{AFX_MSG(CRotateSimulApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ROTATESIMUL_H__13EA510F_0075_4368_BA90_0E2E4A0A27B9__INCLUDED_)
