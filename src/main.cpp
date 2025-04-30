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

    //-----------------------------------------------------------
    // LOADING TEXTURES
    //-----------------------------------------------------------

    SearchAndSetResourceDir("resources");

    Texture kohler = LoadTexture("Kohler.png");
    Texture maple = LoadTexture("Maple.png");
    Texture wabbit = LoadTexture("wabbit_alpha.png");
    Texture chill = LoadTexture("Chill.png");
    Texture car = LoadTexture("FlightCar.png");
    Texture maltigi = LoadTexture("Maltigi.png");

    Texture no = LoadTexture("NoBlock.png");

    Texture default = LoadTexture("BrushDefault.png");
    Texture red = LoadTexture("BrushRed.png");
    Texture orange = LoadTexture("BrushOrange.png");
    Texture yellow = LoadTexture("BrushYellow.png");
    Texture green = LoadTexture("BrushGreen.png");
    Texture blue = LoadTexture("BrushBlue.png");
    Texture purple = LoadTexture("BrushPurple.png");
    Texture black = LoadTexture("BrushBlack.png");
    Texture stamp = LoadTexture("BrushStamp.png");

    //-----------------------------------------------------------
    // LOADING ANIMATIONS/CREATING VECTORS
    //-----------------------------------------------------------

    std::vector<Texture> kohlerSquat;
    for (int i = 1; i <= 112; ++i) {
        char filename[64];
        snprintf(filename, sizeof(filename), "kohlerSquat/ezgif-frame-%03d.png", i);
        Texture tex = LoadTexture(filename);
        kohlerSquat.push_back(tex);
    }

    std::vector<Texture> kohlerBilly;
    for (int i = 1; i <= 107; ++i) {
        char filename[64];
        snprintf(filename, sizeof(filename), "kohlerBilly/ezgif-frame-%03d.png", i);
        Texture tex = LoadTexture(filename);
        kohlerBilly.push_back(tex);
    }

    std::vector<Texture> kohlerGriddy;
    for (int i = 1; i <= 180; ++i) {
        char filename[64];
        snprintf(filename, sizeof(filename), "kohlerGriddy/ezgif-frame-%03d.png", i);
        Texture tex = LoadTexture(filename);
        kohlerGriddy.push_back(tex);
    }

    std::vector<std::vector<Texture2D>*> kohlerDances = {
        &kohlerSquat,
        &kohlerBilly,
        &kohlerGriddy
    };

    std::vector<Texture> mapleHootenanny;
    for (int i = 1; i <= 110; ++i) {
        char filename[64];
        snprintf(filename, sizeof(filename), "mapleHootenanny/ezgif-frame-%03d.png", i);
        Texture tex = LoadTexture(filename);
        mapleHootenanny.push_back(tex);
    }

    std::vector<std::vector<Texture2D>*> mapleDances = {
        &mapleHootenanny
    };

    std::vector<Texture> maltigiWiggle;
    for (int i = 1; i <= 32; ++i) {
        char filename[64];
        snprintf(filename, sizeof(filename), "maltigiWiggle/ezgif-frame-%03d.png", i);
        Texture tex = LoadTexture(filename);
        maltigiWiggle.push_back(tex);
    }

    std::vector<std::vector<Texture2D>*> maltigiDances = {
        &maltigiWiggle
    };
   
    //-----------------------------------------------------------
    // CREATING BOXES
    //-----------------------------------------------------------

    Texture* currentImage = nullptr;
    Shape* currentShape = new Circle(Vector2{ 400, 500 }, 50, BLACK);

    Rectangle tallBox = { 25, 25, 150, 925 };
    Rectangle tallBox2 = { 2100, 25, 150, 925 };

    Rectangle btnCircle = { 50, 50, 100, 40 };
    Rectangle btnSquare = { 50, 100, 100, 40 };
    Rectangle btnTriangle = { 50, 150, 100, 40 };
    Rectangle btnDraw = { 50, 200, 100, 40 };
    Rectangle btnClear = { 50, 250, 100, 40 };

    Rectangle btnRed = { 50, 600, 100, 40 };
    Rectangle btnOrange = { 50, 650, 100, 40 };
    Rectangle btnYellow = { 50, 700, 100, 40 };
    Rectangle btnGreen = { 50, 750, 100, 40 };
    Rectangle btnBlue = { 50, 800, 100, 40 };
    Rectangle btnPurple = { 50, 850, 100, 40 };
    Rectangle btnBlack = { 50, 900, 100, 40 };

    Rectangle btnKohler = { 2125, 50, 100, 40 };
    Rectangle btnMaple = { 2125, 100, 100, 40 };
    Rectangle btnWabbit = { 2125, 150, 100, 40 };
    Rectangle btnChill = { 2125, 200, 100, 40 };
    Rectangle btnCar = { 2125, 250, 100, 40 };
    Rectangle btnMalt = { 2125, 300, 100, 40 };

    Rectangle btnBgRed = { 2125, 600, 100, 40 };
    Rectangle btnBgOrange = { 2125, 650, 100, 40 };
    Rectangle btnBgYellow = { 2125, 700, 100, 40 };
    Rectangle btnBgGreen = { 2125, 750, 100, 40 };
    Rectangle btnBgBlue = { 2125, 800, 100, 40 };
    Rectangle btnBgPurple = { 2125, 850, 100, 40 };
    Rectangle btnBgWhite = { 2125, 900, 100, 40 };

    //-----------------------------------------------------------
    // CREATING MISC.
    //-----------------------------------------------------------
        
    std::vector<Shape*> shapes;
    bool isDrawingImage = false;
    bool drawMode = false;
    Vector2 lastMousePos = { -1, -1 };
    Color chosenColor = WHITE;

    //-----------------------------------------------------------
    // LOOP
    //-----------------------------------------------------------

    while (!WindowShouldClose()) {

        Vector2 mousePos = GetMousePosition();

        //-----------------------------------------------------------
        // SHAPE BUTTONS
        //-----------------------------------------------------------

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

        //-----------------------------------------------------------
        // COLOR BUTTONS
        //-----------------------------------------------------------

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

        //-----------------------------------------------------------
        // STAMP BUTTONS
        //-----------------------------------------------------------

        if (CheckCollisionPointRec(GetMousePosition(), btnKohler) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &kohler;
            isDrawingImage = true;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnMaple) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &maple;
            isDrawingImage = true;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnWabbit) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &wabbit;
            isDrawingImage = true;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnChill) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &chill;
            isDrawingImage = true;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnCar) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &car;
            isDrawingImage = true;
            drawMode = false;
        }
        if (CheckCollisionPointRec(GetMousePosition(), btnMalt) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentImage = &maltigi;
            isDrawingImage = true;
            drawMode = false;
        }

        //-----------------------------------------------------------
        // BACKGROUND COLOR BUTTONS
        //-----------------------------------------------------------

        if (CheckCollisionPointRec(GetMousePosition(), btnBgRed) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = RED; }
        if (CheckCollisionPointRec(GetMousePosition(), btnBgOrange) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = ORANGE; }
        if (CheckCollisionPointRec(GetMousePosition(), btnBgYellow) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = YELLOW; }
        if (CheckCollisionPointRec(GetMousePosition(), btnBgGreen) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = GREEN; }
        if (CheckCollisionPointRec(GetMousePosition(), btnBgBlue) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = BLUE; }
        if (CheckCollisionPointRec(GetMousePosition(), btnBgPurple) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = PURPLE; }
        if (CheckCollisionPointRec(GetMousePosition(), btnBgWhite) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { chosenColor = WHITE; }

        //-----------------------------------------------------------
        // KEYBOARD INPUT
        //-----------------------------------------------------------
        
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
            delete currentShape;
            currentShape = new Circle(Vector2{ 0, 0 }, 2, BLACK);
            isDrawingImage = false;
            drawMode = true;
        }     

        //-----------------------------------------------------------
        // DRAWING
        //-----------------------------------------------------------

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

        //-----------------------------------------------------------
        // CANVAS CHECK
        //-----------------------------------------------------------

        else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
             if (!CheckCollisionPointRec(GetMousePosition(), btnCircle) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnSquare) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnTriangle) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnDraw) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnClear) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnRed) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnOrange) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnYellow) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnGreen) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBlue) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnPurple) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBlack) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnKohler) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnMaple) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnWabbit) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnChill) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnCar) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnMalt) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgRed) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgOrange) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgYellow) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgGreen) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgBlue) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgPurple) &&
                 !CheckCollisionPointRec(GetMousePosition(), btnBgWhite)) {

                 //-----------------------------------------------------------
                 // SHAPES
                 //-----------------------------------------------------------

                Shape* newShape = nullptr;
                
                if (isDrawingImage && currentImage != nullptr) {
                    if (currentImage == &kohler) {
                        shapes.push_back(new ImageShape(mousePos, currentImage, ImageShape::ImageType::KOHLER, true));
                    }
                    if (currentImage == &maple) {
                        shapes.push_back(new ImageShape(mousePos, currentImage, ImageShape::ImageType::MAPLE, true));
                    }
                    if (currentImage == &wabbit) {
                        shapes.push_back(new ImageShape(mousePos, currentImage, ImageShape::ImageType::WABBIT, false));
                    }
                    if (currentImage == &chill) {
                        shapes.push_back(new ImageShape(mousePos, currentImage, ImageShape::ImageType::CHILL, false));
                    }
                    if (currentImage == &car) {
                        shapes.push_back(new ImageShape(mousePos, currentImage, ImageShape::ImageType::CAR, false));
                    }
                    if (currentImage == &maltigi) {
                        shapes.push_back(new ImageShape(mousePos, currentImage, ImageShape::ImageType::MALTIGI, true));
                    }
                    
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

        //-----------------------------------------------------------
        // MISC. CHECKS/DELETE
        //-----------------------------------------------------------

        if (!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            lastMousePos = { -1, -1 };
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (!(shapes.empty())) {
                shapes.pop_back();
            }
        }

        //-----------------------------------------------------------
        // ANIMATE
        //-----------------------------------------------------------

        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            for (auto shape : shapes) {
                ImageShape* imgShape = dynamic_cast<ImageShape*>(shape);
                if (imgShape && imgShape->isAnimatable() && CheckCollisionPointRec(mousePos, imgShape->getBounds())) {

                    switch (imgShape->getImageType()) {
                    case ImageShape::ImageType::KOHLER: {
                        int index = GetRandomValue(0, kohlerDances.size() - 1);
                        imgShape->becomeAnimated(*kohlerDances[index]);
                        break;
                    }
                    case ImageShape::ImageType::MAPLE: {
                        int index = GetRandomValue(0, mapleDances.size() - 1);
                        imgShape->becomeAnimated(*mapleDances[index]);
                        break;
                    }
                    case ImageShape::ImageType::WABBIT: {
                        break;
                    }
                    case ImageShape::ImageType::CHILL: {
                        break;
                    }
                    case ImageShape::ImageType::CAR: {
                        break;
                    }
                    case ImageShape::ImageType::MALTIGI: {
                        int index = GetRandomValue(0, maltigiDances.size() - 1);
                        imgShape->becomeAnimated(*maltigiDances[index]);
                        break;
                    }
                    }

                    break;
                }
            }
        }

        BeginDrawing();
        ClearBackground(chosenColor);

        //-----------------------------------------------------------
        // PRINT SHAPES
        //-----------------------------------------------------------

        float deltaTime = GetFrameTime();
        for (auto s : shapes) {
            s->update(deltaTime);
            s->draw();
        }

        if (isDrawingImage && currentImage != nullptr) {
            DrawTexture(*currentImage, mousePos.x - currentImage->width / 2, mousePos.y - currentImage->height / 2, WHITE);
        }
        else {
            currentShape->setPosition(mousePos);
            currentShape->draw();
        }

        //-----------------------------------------------------------
        // BOXES/LABELS
        //-----------------------------------------------------------

        DrawRectangleRec(tallBox, BLACK);
        DrawRectangleRec(tallBox2, BLACK);

        DrawText("Shapes", 55, 25, 20, WHITE);
        DrawText("Colors", 55, 575, 20, WHITE);
        DrawText("Stamps", 2130, 25, 20, WHITE);
        DrawText("Background", 2130, 575, 20, WHITE);

        //-----------------------------------------------------------
        // SHAPE BUTTONS
        //-----------------------------------------------------------

        DrawRectangleRec(btnCircle, DARKGRAY);
        DrawRectangleRec(btnSquare, DARKGRAY);
        DrawRectangleRec(btnTriangle, DARKGRAY);
        DrawRectangleRec(btnDraw, DARKGRAY);
        DrawRectangleRec(btnClear, DARKGRAY);


        //-----------------------------------------------------------
        // SHAPE TEXT
        //-----------------------------------------------------------

        DrawText("Circle (1)", 55, 55, 20, WHITE);
        DrawText("Square (2)", 55, 105, 20, WHITE);
        DrawText("Triangle (3)", 55, 155, 20, WHITE);
        DrawText("Draw (4)", 55, 205, 20, WHITE);
        DrawText("Clear", 55, 255, 20, WHITE);

        //-----------------------------------------------------------
        // COLOR BUTTONS
        //-----------------------------------------------------------

        if (!isDrawingImage) {
            DrawRectangleRec(btnRed, RED);
            DrawRectangleRec(btnOrange, ORANGE);
            DrawRectangleRec(btnYellow, YELLOW);
            DrawRectangleRec(btnGreen, GREEN);
            DrawRectangleRec(btnBlue, BLUE);
            DrawRectangleRec(btnPurple, PURPLE);
            DrawRectangleRec(btnBlack, BLACK);

            //-----------------------------------------------------------
            // COLOR TEXT
            //-----------------------------------------------------------

            DrawText("Red", 55, 605, 20, BLACK);
            DrawText("Orange", 55, 655, 20, BLACK);
            DrawText("Yellow", 55, 705, 20, BLACK);
            DrawText("Green", 55, 755, 20, BLACK);
            DrawText("Blue", 55, 805, 20, BLACK);
            DrawText("Purple", 55, 855, 20, BLACK);
            DrawText("Black", 55, 905, 20, WHITE);
        }
        else {
            DrawTexture(no, 50, 600, WHITE);
        }

        //-----------------------------------------------------------
        // STAMP BUTTONS
        //-----------------------------------------------------------

        DrawRectangleRec(btnKohler, DARKGRAY);
        DrawRectangleRec(btnMaple, DARKGRAY);
        DrawRectangleRec(btnWabbit, DARKGRAY);
        DrawRectangleRec(btnChill, DARKGRAY);
        DrawRectangleRec(btnCar, DARKGRAY);
        DrawRectangleRec(btnMalt, DARKGRAY);


        //-----------------------------------------------------------
        // STAMP TEXT
        //-----------------------------------------------------------

        DrawText("Kohler", 2130, 55, 20, WHITE);
        DrawText("Maple", 2130, 105, 20, WHITE);
        DrawText("Wabbit", 2130, 155, 20, WHITE);
        DrawText("Chill", 2130, 205, 20, WHITE);
        DrawText("Car", 2130, 255, 20, WHITE);
        DrawText("Luigi", 2130, 305, 20, WHITE);


        //-----------------------------------------------------------
        // BACKGROUND COLOR BUTTONS
        //-----------------------------------------------------------

        DrawRectangleRec(btnBgRed, RED);
        DrawRectangleRec(btnBgOrange, ORANGE);
        DrawRectangleRec(btnBgYellow, YELLOW);
        DrawRectangleRec(btnBgGreen, GREEN);
        DrawRectangleRec(btnBgBlue, BLUE);
        DrawRectangleRec(btnBgPurple, PURPLE);
        DrawRectangleRec(btnBgWhite, WHITE);


        //-----------------------------------------------------------
        // BACKGROUND COLOR TEXT
        //-----------------------------------------------------------

        DrawText("BG Red", 2130, 605, 20, BLACK);
        DrawText("BG Orange", 2130, 655, 20, BLACK);
        DrawText("BG Yellow", 2130, 705, 20, BLACK);
        DrawText("BG Green", 2130, 755, 20, BLACK);
        DrawText("BG Blue", 2130, 805, 20, BLACK);
        DrawText("BG Purple", 2130, 855, 20, BLACK);
        DrawText("BG White", 2130, 905, 20, BLACK);

        //-----------------------------------------------------------
        // CURSORS
        //-----------------------------------------------------------

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

    //-----------------------------------------------------------
    // UNLOADING ANIMATIONS
    //-----------------------------------------------------------

    for (std::vector<Texture2D>* vecPtr : kohlerDances) {
        for (Texture2D& tex : *vecPtr) {
            UnloadTexture(tex);
        }
    }
    for (std::vector<Texture2D>* vecPtr : mapleDances) {
        for (Texture2D& tex : *vecPtr) {
            UnloadTexture(tex);
        }
    }
    for (std::vector<Texture2D>* vecPtr : maltigiDances) {
        for (Texture2D& tex : *vecPtr) {
            UnloadTexture(tex);
        }
    }

    //-----------------------------------------------------------
    // UNLOADING TEXTURES
    //-----------------------------------------------------------

    UnloadTexture(kohler);
    UnloadTexture(maple);
    UnloadTexture(wabbit);
    UnloadTexture(chill);
    UnloadTexture(car);
    UnloadTexture(maltigi);

    UnloadTexture(no);

    UnloadTexture(red);
    UnloadTexture(orange);
    UnloadTexture(yellow);
    UnloadTexture(green);
    UnloadTexture(blue);
    UnloadTexture(purple);
    UnloadTexture(black);

    CloseWindow();
    return 0;
}
