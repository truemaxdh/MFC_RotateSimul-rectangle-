// RotateSimulDoc.cpp : CRotateSimulDoc �N���X�̓���̒�`���s���܂��B
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
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc �N���X�̍\�z/����

CRotateSimulDoc::CRotateSimulDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRotateSimulDoc::~CRotateSimulDoc()
{
}

BOOL CRotateSimulDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc �V���A���C�[�[�V����

void CRotateSimulDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRotateSimulDoc �N���X�̐f�f

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
// CRotateSimulDoc �R�}���h
