#include "pch.h"
#include "character.h"
#include <utils.h>
#include "Texture.h"

character::character()
<%
	
%>

void character::Update(float ElapsedSec)
<%
	
%>

void character::Draw()
<%
	utils::DrawEllipse(Point2f(XLoc,YLoc),Size,Size);
	utils::FillEllipse(Point2f(XLoc,YLoc),Size,Size);
	if (bIsShoots)
	<%
		utils::DrawLine(Point2f(XLoc, YLoc), MousePos);
	%>

%>

void character::Move(const uint8_t* Keycode)
<%
	if (Keycode[SDL_SCANCODE_A])
	<%
		XLoc -= Speed;
	%>
	if (Keycode[SDL_SCANCODE_D])
	<%
		XLoc += Speed;
	%>
	if (Keycode[SDL_SCANCODE_W])
	<%
		YLoc += Speed;
	%>
	if (Keycode[SDL_SCANCODE_S])
	<%
		YLoc -= Speed;
	%>
	
%>

void character::Attack()
<%
	bIsShoots = true;
%>

void character::MoveToPlayer(const Point2f& Pos)
<%
	if (Pos.x > XLoc)
	<%
		XLoc += Speed;
	%>
	if (Pos.x < XLoc)
	<%
		XLoc -= Speed;
	%>
	if (Pos.y > YLoc)
	<%
		YLoc += Speed;
	%>
	if (Pos.y < YLoc)
	<%
		YLoc -= Speed;
	%>
%>
