#include "Entity.h"
#include "EntityLiving.h"

Entity::Entity() : death(0), show(0), health(0), mapController(0) {}

Entity:: ~Entity() { if (show) mapController->erase(this); }

void Entity::setDeath() { death = 1; }

void Entity::setPoint(const Point& p) { point = p; }

void Entity::setShow(MapController* mapcontroller, const bool& x) {
	if (show == x) return;
	if (show) {
		mapController->erase(this);
		mapController = 0;
	}
	else {
		mapController = mapcontroller;
		mapController->push(this);
	}
	show ^= 1;
	return;
}

MapController* Entity::getMapController() { return show ? mapController : nullptr; }

int Entity::getDeath() const { return death; }

LL Entity::getHealth() const { return health; }

Point Entity::getPoint() const { return point; }

int Entity::inRange(const Point& p) const { return abs(point.x - p.x) < 1 && abs(point.y - p.y) < 1; }

void Entity::beAttacked(EntityLiving* other, LL damage) {}

void Entity::beUsed(EntityLiving* other){}

