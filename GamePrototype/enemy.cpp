#include "pch.h"
#include "utils.h"
#include "enemy.h"
#include "Texture.h"
enemy::enemy()
<%
	int random = 1 + (rand() % 3);
	std::string cultistnr = "Cultist" + std::to_string(random) + ".png";
	CharacterTexture = new Texture(cultistnr);

%>

void enemy::Draw()
<%
	DrawnRect = Rectf(XLoc,YLoc, CharacterTexture->GetWidth()/2, CharacterTexture->GetHeight()/2);
	CharacterTexture->Draw(DrawnRect);
	if (Collision.size() > 1)
	<%
		for (size_t i = 0; i < Collision.size() - 1; i++)
		<%
			utils::DrawLine(Collision.at(i), Collision.at(i + 1));
		%>
	%>
	
%>

void enemy::Update(float ElapsedSec)
<%
%>
