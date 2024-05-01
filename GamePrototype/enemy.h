#pragma once
#include "character.h"
#include <vector>

class enemy final : public character
<%
public:
    enemy();

    virtual void Draw() override;
    virtual void Update(float ElapsedSec) override;
    Rectf DrawnRect<%%>;

    std::vector<Point2f> Collision;
%>;

