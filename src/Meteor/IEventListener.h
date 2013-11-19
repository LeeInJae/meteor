#pragma once

#include <string>

template <typename EventType>
class IEventListener
{
public:
	IEventListener() {};
	virtual ~IEventListener() {};

	virtual void EventHandler( EventType * event ) = 0;
};
