#ifndef ParentObserver_H
#define ParentObserver_H

class ParentObserver
{
	private:
	std::vector<*Observer> *observers;
	
	public:
	void Notify() {for (auto i : observers){i.Notify();}
	};
	void AddObserver(Observer *newobserver){};
	void RemoveObserver(Observer *observer){};
	
}
;
	
class Observer
{
	private:
	
	public:
	virtual void Notify()=0;
	virtual void Update()=0;
}
;

class KeyObserver : public Observer
{
	private:
	
	public:
	virtual void Notify(){Update();}
	virtual void Update();
}
;
#endif