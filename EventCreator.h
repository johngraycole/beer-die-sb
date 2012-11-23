#ifndef __EVENT_CREATOR_H__
#define __EVENT_CREATOR_H__

#include <boost/foreach.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

template <class EventListener, class EventItem>
class EventCreator {
public:
	EventCreator() : _listeners(), _mutex() {}
	virtual ~EventCreator() {}

	void NotifyAll(const EventItem &item) {
		_mutex.lock();
		boost::shared_ptr<EventListener> l_ptr;
		BOOST_FOREACH( l_ptr, _listeners ) {
			notify(l_ptr, item);
		}
		_mutex.unlock();
	}

	void AddListener( boost::shared_ptr<EventListener> listener ) {
		_mutex.lock();
		_listeners.push_back(listener);
		_mutex.unlock();
	}

	void RemoveListener( boost::shared_ptr<EventListener> listener) {
		_mutex.lock();
		for (int i=0; i<_listeners.size(); i++) {
			if (_listeners[i] == listener) {
				_listeners.erase( _listeners.begin()+i );
				break;
			}
		}
		_mutex.unlock();
	}

protected:
	virtual void notify( boost::shared_ptr<EventListener> listener, const EventItem &item ) = 0;

private:
	std::vector< boost::shared_ptr<EventListener> > _listeners;
	boost::mutex _mutex;
};


#endif /* __EVENT_CREATOR_H__ */

