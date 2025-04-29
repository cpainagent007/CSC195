
#pragma once
#include "Shape.h"
#include "raylib.h"
#include <vector>

class ImageShape : public Shape {
public:
    bool ColorCheck(Color check) override;
    ImageShape(Vector2 position, Texture* image);
    void becomeAnimated(std::vector<Texture>& frames);
    void update(float deltaTime) override;
    void draw() override;
    Type getType() override;
    Rectangle getBounds() const;
private:
    Texture* staticTexture;
    std::vector<Texture>* animationFrames = nullptr;
    bool isAnimated = false;
    float frameTime = 0.1f;
    float timer = 0.0f;
    int currentFrame = 0;
};

