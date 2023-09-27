#include "Colliders.h"
#include <math.h>
#include <iostream>

using namespace std;

/////////////////////
// Circle Collider //
/////////////////////

CircleCollider::CircleCollider(float x, float y, float radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
}

CircleCollider::~CircleCollider() 
{

}

bool CircleCollider::CollisionWithCircle(CircleCollider& c) const
{
	float diffX = this->x - c.x;
	float diffY = this->y - c.y;
	float dist = sqrt((diffX * diffX) + (diffY * diffY)); // find the actual distance between the 2 circle centers

	if (dist <= this->radius + c.radius) // if the distance between the circles is less than (or equal to) the sum of the radii, the circles have collided
	{
		return true;		
	}
	return false; // return false by default
}

bool CircleCollider::CollisionWithBox(BoxCollider& b) const
{
	// make temp variables for testing which edge of the box is closest to the circle
	float testX = this->x;
	float testY = this->y;

	//assign the proper values to testX
	if (this->x < b.getX())
		testX = b.getX();
	else if (this->x > b.getX() + b.getW())
		testX = b.getX() + b.getW();

	// and to testY
	if (this->y < b.getY())
		testY = b.getY();
	else if (this->x > b.getY() + b.getH())
		testY = b.getY() + b.getH();

	/* 
	/	having the correct values on testX and testY gives an edge on rectangle which
	/	is closest to the center of the circle. From this point, a distance to the edge
	/	can be calculated using the corners of the rectance and the center of the circle.
	*/

	//calculate distances from the circle center to the test points, and the vector distance
	float distX = this->x - testX;
	float distY = this->y - testY;
	float dist = sqrt((distX * distX) + (distY * distY));

	if (dist <= this->radius)
	{
		return true;
	}

	return false;
}

float CircleCollider::getX() { return this->x; }
float CircleCollider::getY() { return this->y; }
float CircleCollider::getRadius() { return this->radius; }

//////////////////
// Box Collider //
//////////////////

BoxCollider::BoxCollider(float x, float y, float w, float h) 
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

BoxCollider::~BoxCollider()
{

}

bool BoxCollider::CollisionWithBox(BoxCollider& b)const
{
	// this is known as Axis-Aligned Bounding Box collision or AABB and is used for box-to-box collisions
	if (this->x < b.x + b.w &&
		this->x + this->w > b.x &&
		this->y < b.y + b.h &&
		this->y + this->h > b.y)
	{
		return true;
	}
	return false;
}

/*bool BoxCollider::CollisionWithCircle(CircleCollider& c)const
{

}*/

float BoxCollider::getX() { return this->x; }
float BoxCollider::getY() { return this->y; }
float BoxCollider::getW() { return this->w; }
float BoxCollider::getH() { return this->h; }