#pragma once
class character
{
public:
	virtual void Update(float ElapsedSec);
	virtual void Draw();
	
	void Move(const uint8_t* Keycode);
	void Attack();
	void MoveToPlayer(const Point2f& Pos);

	Point2f MousePos{};
	float Speed{5};
	float Size{20};
	float XLoc{200};
	float YLoc{200};
	bool bIsShoots{false};
};

