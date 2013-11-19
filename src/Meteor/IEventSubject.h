#pragma once

#include "IEventListener.h"

template <typename EventType>
class IEventSubject
{
public:
	virtual ~IEventSubject() {};

	virtual void Register( IEventListener<EventType> * listener ) = 0;
	virtual void SendEvent( EventType * event ) = 0;
};
