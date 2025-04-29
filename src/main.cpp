#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "ImageShape.h"

#include "raylib.h"

#include "resource_dir.h"
#include "raymath.h"

#include <vector>

int screen_width = 2300;
int screen_height = 1000;

typedef struct Sprite {
    Texture2D texture;
    Rectangle rect;
    Vector2 position;
} Sprite;

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(screen_width, screen_height, "Colton Painter");

    SearchAndSetResourceDir("resources");

    Texture kohler = LoadTexture("kohler.png");

    Texture default = LoadTexture("BrushDefault.png");
    Texture red = LoadTexture("BrushRed.png");
    Texture orange = LoadTexture("BrushOrange.png");
    Texture yellow = LoadTexture("BrushYellow.png");
    Texture green = LoadTexture("BrushGreen.png");
    Texture blue = LoadTexture("BrushBlue.png");
    Texture purple = LoadTexture("BrushPurple.png");
    Texture black = LoadTexture("BrushBlack.png");
    Texture stamp = LoadTexture("BrushStamp.png");

    std::vector<Texture> gifFrames;
    for (int i = 1; i <= 112; ++i) {
        char filename[64];
        snprintf(filename, sizeof(filename), "ezgif-frame-%03d.png", i);
        Texture tex = LoadTexture(filename);
        gifFrames.push_back(tex);
    }
    
    Texture* currentImage = nullptr;
    Shape* currentShape = new Circle(Vector2{ 400, 500 }, 50, BLACK);

    Rectangle btnCircle = { 50, 50, 100, 40 };
    Rectangle btnSquare = { 50, 100, 100, 40 };
    Rectangle btnTriangle = { 50, 150, 100, 40 };
    Rectangle btnKohler = { 50, 200, 100, 40 };
    Rectangle btnDraw = { 50, 250, 100, 40 };
    Rectangle btnClear = { 50, 300, 100, 40 };

    Rectangle btnRed = { 50, 600, 100, 40 };
    Rectangle btnOrange = { 50, 650, 100, 40 };
    Rectangle btnYellow = { 50, 700, 100, 40 };
    Rectangle btnGreen = { 50, 750, 100, 40 };
    Rectangle btnBlue = { 50, 800, 100, 40 };
    Rectangle btnPurple = { 50, 850, 100, 40 };
    Rectangle btnBlack = { 50, 900, 100, 40 };

    std::vector<Shape*> shapes;
    bool isDrawingImage = false;
    bool drawMode = false;
    Vector2 lastMousePos = { -1, -1 };

    while (!WindowShouldClose()) {

        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(GetMousePosition(), btnCircle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            delete currentShape;
            currentShape = new Circle(Vector2{ 0, 0 }, 50, BLACK);
            isDrawingImage = false;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnSquare) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            delete currentShape;
            currentShape = new Square(Vector2{ 0, 0 }, 100, BLACK);
            isDrawingImage = false;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnTriangle) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            delete currentShape;
            currentShape = new Triangle(Vector2{ 0, 0 }, 50, BLACK);
            isDrawingImage = false;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnKohler) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &kohler;
            isDrawingImage = true;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnDraw) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            delete currentShape;
            currentShape = new Circle(Vector2{ 0, 0 }, 2, BLACK);
            isDrawingImage = false;
            drawMode = true;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnClear) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (auto s : shapes) {
                delete s;
            }
            shapes.clear();
        }
        if (!isDrawingImage) {
            if (CheckCollisionPointRec(GetMousePosition(), btnRed) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(RED);
            }
            if (CheckCollisionPointRec(GetMousePosition(), btnOrange) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(ORANGE);
            }
            if (CheckCollisionPointRec(GetMousePosition(), btnYellow) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(YELLOW);
            }
            if (CheckCollisionPointRec(GetMousePosition(), btnGreen) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(GREEN);
            }
            if (CheckCollisionPointRec(GetMousePosition(), btnBlue) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(BLUE);
            }
            if (CheckCollisionPointRec(GetMousePosition(), btnPurple) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(PURPLE);
            }
            if (CheckCollisionPointRec(GetMousePosition(), btnBlack) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentShape->setColor(BLACK);
            }
        }
        
        if (IsKeyPressed(KEY_ONE)) {
            delete currentShape;
            currentShape = new Circle(Vector2{ 0, 0 }, 50, BLACK);
            isDrawingImage = false;
        }
        if (IsKeyPressed(KEY_TWO)) {
            delete currentShape;
            currentShape = new Square(Vector2{ 0, 0 }, 100, BLACK);
            isDrawingImage = false;
        }
        if (IsKeyPressed(KEY_THREE)) {
            delete currentShape;
            currentShape = new Triangle(Vector2{ 0, 0 }, 50, BLACK);
            isDrawingImage = false;
        }
        if (IsKeyPressed(KEY_FOUR)) {
            currentImage = &kohler;
            isDrawingImage = true;
        }
        if (IsKeyPressed(KEY_FIVE)) {
            delete currentShape;
            currentShape = new Circle(Vector2{ 0, 0 }, 2, BLACK);
            isDrawingImage = false;
        }

        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            for (auto shape : shapes) {
                ImageShape* imgShape = dynamic_cast<ImageShape*>(shape);
                if (imgShape != nullptr) {
                    if (CheckCollisionPointRec(mousePos, imgShape->getBounds())) {
                        imgShape->becomeAnimated(gifFrames);
                        break;
                    }
                }
            }
        }

        

        if (drawMode && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            if (lastMousePos.x >= 0 && lastMousePos.y >= 0) {
                float distance = Vector2Distance(mousePos, lastMousePos);
                int steps = (int)(distance / 1.5f);
                for (int i = 0; i <= steps; i++) {
                    float t = (float)i / (float)steps;
                    Vector2 interpolated = Vector2Lerp(lastMousePos, mousePos, t);
                    shapes.push_back(new Circle(interpolated, currentShape->getSize(), currentShape->getColor()));
                }
            }

            lastMousePos = mousePos;
        }
        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
             if (!CheckCollisionPointRec(GetMousePosition(), btnCircle) &&
                !CheckCollisionPointRec(GetMousePosition(), btnSquare) &&
                !CheckCollisionPointRec(GetMousePosition(), btnTriangle) &&
                !CheckCollisionPointRec(GetMousePosition(), btnKohler) &&
                !CheckCollisionPointRec(GetMousePosition(), btnDraw) &&
                !CheckCollisionPointRec(GetMousePosition(), btnClear) &&
                !CheckCollisionPointRec(GetMousePosition(), btnRed) &&
                !CheckCollisionPointRec(GetMousePosition(), btnOrange) &&
                !CheckCollisionPointRec(GetMousePosition(), btnYellow) &&
                !CheckCollisionPointRec(GetMousePosition(), btnGreen) &&
                !CheckCollisionPointRec(GetMousePosition(), btnBlue) &&
                !CheckCollisionPointRec(GetMousePosition(), btnPurple) &&
                !CheckCollisionPointRec(GetMousePosition(), btnBlack)) {
                Shape* newShape = nullptr;
                
                if (isDrawingImage && currentImage != nullptr) {
                    shapes.push_back(new ImageShape(mousePos, currentImage));
                }
                else{
                    if (dynamic_cast<Circle*>(currentShape)) {
                        newShape = new Circle(mousePos, currentShape->getSize(), currentShape->getColor());
                    }
                    else if (dynamic_cast<Square*>(currentShape)) {
                        newShape = new Square(mousePos, currentShape->getSize(), currentShape->getColor());
                    }
                    else if (dynamic_cast<Triangle*>(currentShape)) {
                        newShape = new Triangle(mousePos, currentShape->getSize(), currentShape->getColor());
                    }
                    if (newShape != nullptr) {
                        shapes.push_back(newShape);
                    }
                }
            }
        }
        if (!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            lastMousePos = { -1, -1 };
        }

        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectangleRec(btnCircle, BLACK);
        DrawRectangleRec(btnSquare, BLACK);
        DrawRectangleRec(btnTriangle, BLACK);
        DrawRectangleRec(btnKohler, BLACK);
        DrawRectangleRec(btnDraw, BLACK);
        DrawRectangleRec(btnClear, BLACK);
        DrawText("Circle", 55, 55, 20, WHITE);
        DrawText("Square", 55, 105, 20, WHITE);
        DrawText("Triangle", 55, 155, 20, WHITE);
        DrawText("Kohler", 55, 205, 20, WHITE);
        DrawText("Draw", 55, 255, 20, WHITE);
        DrawText("Clear", 55, 305, 20, WHITE);
        if (!isDrawingImage) {
            DrawRectangleRec(btnRed, RED);
            DrawRectangleRec(btnOrange, ORANGE);
            DrawRectangleRec(btnYellow, YELLOW);
            DrawRectangleRec(btnGreen, GREEN);
            DrawRectangleRec(btnBlue, BLUE);
            DrawRectangleRec(btnPurple, PURPLE);
            DrawRectangleRec(btnBlack, BLACK);
        }
       
        if (isDrawingImage && currentImage != nullptr) {
            DrawTexture(*currentImage, mousePos.x - currentImage->width / 2, mousePos.y - currentImage->height / 2, WHITE);
        }
        else {
            currentShape->setPosition(mousePos);
            currentShape->draw();
        }

        float deltaTime = GetFrameTime();
        for (auto s : shapes) {
            s->update(deltaTime);
            s->draw();
        }

        if (isDrawingImage) {
            HideCursor();
            currentShape = nullptr;
            DrawTexture(stamp, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(RED)) {
            HideCursor();
            DrawTexture(red, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(ORANGE)) {
            HideCursor();
            DrawTexture(orange, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(YELLOW)) {
            HideCursor();
            DrawTexture(yellow, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(GREEN)) {
            HideCursor();
            DrawTexture(green, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(BLUE)) {
            HideCursor();
            DrawTexture(blue, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(PURPLE)) {
            HideCursor();
            DrawTexture(purple, GetMouseX(), GetMouseY(), WHITE);
        }
        else if (currentShape->ColorCheck(BLACK)) {
            HideCursor();
            DrawTexture(black, GetMouseX(), GetMouseY(), WHITE);
        }
        else {
            ShowCursor();
        }

        EndDrawing();
    }
    for (Texture t : gifFrames) {
        UnloadTexture(t);
    }
    UnloadTexture(kohler);
    CloseWindow();
    return 0;
}
