
#pragma once
#include "Shape.h"
#include "raylib.h"
#include <vector>



class ImageShape : public Shape {
public:
    enum ImageType {
        KOHLER,
        MAPLE,
        WABBIT,
        CHILL,
        CAR,
        MALTIGI,
        JOKER,
        X
    };
public:
    ImageShape(Vector2 position, Texture2D* texture, ImageType type, bool canAnimate = false);
    void becomeAnimated(const std::vector<Texture2D>& frames);
    bool isAnimatable() const { return canAnimate; }
    bool ColorCheck(Color check) override;
    void becomeAnimated(std::vector<Texture>& frames);
    void update(float deltaTime) override;
    void draw() override;
    ImageType getImageType() const;
    Type getType() override;
    Rectangle getBounds() const;

    bool canAnimate = false;
    ImageType m_type;
private:
    Texture* staticTexture;
    std::vector<Texture>* animationFrames = nullptr;
    bool isAnimated = false;
    float frameTime = 0.1f;
    float timer = 0.0f;
    int currentFrame = 0;
};

