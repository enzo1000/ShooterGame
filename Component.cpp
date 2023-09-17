#include "Component.h"
#include "Actor.h"

Component::Component(Actor* ownerP, int updateOrderP) :
	owner(*ownerP),	//Le choix du pointeur ou référence est fait pour garantir la plus simple API
	updateOrder(updateOrderP)
{
	owner.addComponent(this);
}

Component::~Component() {
	owner.removeComponent(this);
}

void Component::update(float dt) {

}