#pragma once

#include <list>
#include "IEventSubject.h"

template <typename EventType>
class CEventSubject : public IEventSubject<EventType>
{
public:
	virtual ~CEventSubject() {};

	virtual void Register( IEventListener<EventType> * listener )
	{
		m_Listeners.push_back( listener );
	}

	virtual void SendEvent( EventType * event )
	{
		for ( auto listener : m_Listeners )
			listener->EventHandler( event );
	}

protected:
	std::list<IEventListener<EventType> *> m_Listeners;
};
