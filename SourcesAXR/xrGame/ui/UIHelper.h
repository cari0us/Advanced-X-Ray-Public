////////////////////////////////////////////////////////////////////////////
//	Module 		: UIHelper.h
//	Created 	: 17.01.2008
//	Author		: Evgeniy Sokolov
//	Description : UI Helper class
////////////////////////////////////////////////////////////////////////////

#ifndef	UI_HELPER_H_INCLUDED
#define UI_HELPER_H_INCLUDED

class CUIXml;
class CUIWindow;
class CUIStatic;
class CUITextWnd;
class CUIProgressBar;
class CUIFrameLineWnd;
class CUIFrameWindow;
class CUI3tButton;
class CUICheckButton;
class UIHint;
class CUIDragDropListEx;
class CUIDragDropReferenceList;
class CUIEditBox;

class UIHelper
{
public:
	UIHelper		() {};
	~UIHelper		() {};

	static	CUIStatic*			CreateStatic		( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUITextWnd*			CreateTextWnd		( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUIProgressBar*		CreateProgressBar	( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUIFrameLineWnd*	CreateFrameLine		( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUIFrameWindow*		CreateFrameWindow	( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUI3tButton*		Create3tButton		( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUICheckButton*		CreateCheck			( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUIEditBox*			CreateEditBox		( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );

	static	UIHint*				CreateHint			( CUIXml& xml, LPCSTR ui_path /*, CUIWindow* parent*/ );
	static	CUIDragDropListEx*	CreateDragDropListEx( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );
	static	CUIDragDropReferenceList*	CreateDragDropReferenceList( CUIXml& xml, LPCSTR ui_path, CUIWindow* parent, bool critical = true  );

}; // class UIHelper

#endif // UI_HELPER_H_INCLUDED
