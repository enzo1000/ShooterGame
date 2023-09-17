#pragma once

//Actor.cpp va inclure Components.h mais comme Components.h 
// ne peut pas inclure Actor.cpp on déclare en avant un 
// Actor ici et on inclura Actor.h dans Component.cpp
class Actor;

class Component
{
public:
	Component(Actor* ownerP, int updateOrderP = 100);
	Component() = delete;
	virtual ~Component();
	Component(const Component&) = delete;
	Component& operator = (const Component&) = delete;

	int getUpdateOrder() const { return updateOrder;  }

	virtual void update(float dt);

private:
	Actor& owner;
	int updateOrder;	//Ordre des component dans la méthode updateComponent
};