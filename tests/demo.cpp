#include <iostream>
#include "raylib.h"
#include "rayliberplate.h"

class Player {
private:
  Vector2 position;
  Vector2 velocity;
  float radius;

public:
  Player(
  float positionx, 
  float positiony, 
  float velocityx,
  float velocityy,
  float radiusdef
  ) {
  
    position.x = positionx;
    position.y = positiony;
    velocity.x = velocityx;
    velocity.y = velocityy;
    radius = radiusdef;
    
  }

  void playerMovement(int screenWidth, int screenHeight) {
    
    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x >= screenWidth || position.x <= 0) {
      velocity.x *= -1;
    }

    if (position.y >= screenHeight || position.y <= 0) {
      velocity.y *= -1;
    }
    
  }

  void drawPlayer() {
    DrawCircleV(position, radius, BLACK);
  }
  
};

int main(void) {

  InitRelativeWindowDivisor("Demo", 1, 2);
  SetWindowPosCenter();
  SetTargetFPS(60);

  Player daBall(20.0f, 20.0f, 5.0f, 5.0f, 10.0f);

  while (!WindowShouldClose()) {
  
    daBall.playerMovement(GetScreenWidth(), GetScreenHeight());
    
    BeginDrawing();
    
      ClearBackground(RAYWHITE);
      daBall.drawPlayer();
      
    EndDrawing();
    
  }

  CloseWindow();
  return 0;
}
