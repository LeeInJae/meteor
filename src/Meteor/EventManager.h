#pragma once

#include "EventSubject.h"

template <typename EventType>
class CEventManager : CEventSubject<EventType>
{
private:
	CEventManager();
	CEventManager( const CEventManager & ) {}
	virtual ~CEventManager();

public:
	static CEventManager & GetInstance()
	{
		static CEventManager instance;
		return instance;
	}

	void Register( IEventListener<EventType> & receiver )
	{
		m_Listeners.push_back( & receiver );
	}

	void SendEvent( EventType * event )
	{
		for ( auto listener : m_Listeners )
			listener->EventHandler( event );
	}

protected:
	std::list<IEventListener<EventType> *> m_Listeners;
};
