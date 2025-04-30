
#pragma once
#include "Shape.h"
#include "raylib.h"
#include <vector>

class ImageShape : public Shape {
public:
    bool canAnimate = false;
public:
    ImageShape(Vector2 position, Texture2D* texture, bool canAnimate = false);
    void becomeAnimated(const std::vector<Texture2D>& frames);
    bool isAnimatable() const { return canAnimate; }
    bool ColorCheck(Color check) override;
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

