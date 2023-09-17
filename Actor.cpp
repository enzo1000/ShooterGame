#include "Actor.h"
#include <algorithm>
#include "Game.h"
#include "Component.h"

Actor::Actor() :
	state(Actor::ActorState::Active),
	position(Vector2::zero),
	scale(1.0f),
	rotation(0.0f),
	game(Game::instance())
{
	game.addActor(this);
}

Actor::~Actor()
{
	game.removeActor(this);
	// Need to delete components
	// Because ~Component calls RemoveComponent, need a different style loop
	while (!components.empty()) {
		delete components.back();
	}
}

void Actor::SetPosition(Vector2 positionP) {
	position = positionP;
}

void Actor::setScale(float scaleP) {
	scale = scaleP;
}

void Actor::setRotation(float rotationP) {
	rotation = rotationP;
}

void Actor::update(float dt) {
	if (state == Actor::ActorState::Active) {
		updateComponents(dt);
		updateActor(dt);
	}
}

void Actor::updateComponents(float dt) {
	for (auto component : components) {
		component->update(dt);
	}
}

void Actor::updateActor(float dt) {

}

void Actor::addComponent(Component* component) {
	//Trouve le point d'insertion dans le vecteur trié
	//(Le premier elem avec un ordre plus grand que le mien)
	int myOrder = component->getUpdateOrder();
	auto iter = begin(components);
	for (; iter != end(components); ++iter) {
		if (myOrder < (*iter)->getUpdateOrder()) {
			break;
		}
	}

	//Inser l'élément avant la position de l'iterateur
	components.insert(iter, component);
}

void Actor::removeComponent(Component* component) {
	auto iter = std::find(begin(components), end(components), component);
	if (iter != end(components)) {
		components.erase(iter);
	}
}
