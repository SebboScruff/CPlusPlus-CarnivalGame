#pragma once

struct BoxCollider {
public:
	BoxCollider(float x, float y, float w, float h);

	~BoxCollider();

	bool CollisionWithBox(BoxCollider &b) const;

	// Not including a Box-To-Circle  Collision method since there is already a Circle-To-Box collision in the CircleCollider struct
	// Don't want to risk calling effectively the same thing twice

	//bool CollisionWithCircle(CircleCollider& c) const;

	float getX();
	float getY();
	float getW();
	float getH();

private:
	float x;
	float y;
	float w;
	float h;

};

struct CircleCollider {
public:
	CircleCollider(float x, float y, float radius);

	~CircleCollider();

	bool CollisionWithCircle(CircleCollider& c) const;
	bool CollisionWithBox(BoxCollider& b) const;

	float getX();
	float getY();
	float getRadius();

private:
	float x;
	float y;
	float radius;

};

