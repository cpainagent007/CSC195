
#include "ImageShape.h"
#include "raylib.h"

bool ImageShape::ColorCheck(Color check) {
    return false;
}

ImageShape::ImageShape(Vector2 position, Texture* image)
    : Shape(position), staticTexture(image), isAnimated(false), animationFrames(nullptr), currentFrame(0), timer(0.0f) {
}

void ImageShape::becomeAnimated(std::vector<Texture>& frames) {
    animationFrames = &frames;
    isAnimated = true;
    currentFrame = 0;
    timer = 0.0f;
}

void ImageShape::update(float deltaTime) {
    if (isAnimated && animationFrames) {
        timer += deltaTime;
        if (timer >= frameTime) {
            timer -= frameTime;
            currentFrame = (currentFrame + 1) % animationFrames->size();
        }
    }
}

void ImageShape::draw() {
    if (isAnimated && animationFrames) {
        DrawTexture((*animationFrames)[currentFrame], m_position.x, (m_position.y - 500), WHITE);
    }
    else if (staticTexture) {
        DrawTexture(*staticTexture, (m_position.x - 125), (m_position.y - 115), WHITE);
    }
}

Rectangle ImageShape::getBounds() const {
    if (isAnimated && animationFrames) {
        Texture t = (*animationFrames)[currentFrame];
        return { m_position.x, m_position.y, (float)t.width, (float)t.height };
    }
    else if (staticTexture) {
        return { m_position.x, m_position.y, (float)staticTexture->width, (float)staticTexture->height };
    }
    return { 0, 0, 0, 0 };
}

ImageShape::Type ImageShape::getType() {
    return Type::Image;
}
