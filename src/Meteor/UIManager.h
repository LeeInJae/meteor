#pragma once

#include <list>
class CUIObject;

class CUIManager
{
public:
	~CUIManager(void);

	void Init();
	void Release();
	void AddUI( CUIObject * uiObject );
	void UpdateUI( float deltaTime );
	void RenderUI();
	void CloseAll();


	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CUIManager & GetInstance();

private:
	CUIManager();
	CUIManager( const CUIManager & );
	CUIManager & operator=( const CUIManager & );

	std::list< CUIObject * > m_UIObjects;
};
