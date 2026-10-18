#include <stddef.h>
#include <math.h>
#include <limits.h>
#include "raylib.h"
#include "rayliberplate.h"

RayPlateStatus SetWindowPosCenter() {

  if (!IsWindowReady()) {
    return RAY_PLATE_INVALID_STATE;
  }

  const int monitor = GetCurrentMonitor();

  if (monitor < 0 || monitor >= GetMonitorCount()) {
    return RAY_PLATE_INVALID_STATE;
  }
  
  const int monitorWidth = GetMonitorWidth(monitor);
  const int monitorHeight = GetMonitorHeight(monitor);

  if (monitorWidth <= 0 || monitorHeight <= 0) {
    return RAY_PLATE_INVALID_STATE;
  }

  const Vector2 monitorPos = GetMonitorPosition(monitor);
  
  const int windowWidth = GetScreenWidth();
  const int windowHeight = GetScreenHeight();

  if (windowWidth <= 0 || windowHeight <= 0) {
    return RAY_PLATE_INVALID_STATE;
  }

  const double windowPosX = (double)monitorPos.x + ((double)monitorWidth - windowWidth) / 2;
  const double windowPosY = (double)monitorPos.y + ((double)monitorHeight - windowHeight) / 2;

  if (!isfinite(windowPosX) || !isfinite(windowPosY)) {
    return RAY_PLATE_INVALID_STATE;
  }

  if (windowPosX > INT_MAX || windowPosY > INT_MAX) {
    return RAY_PLATE_INVALID_STATE;
  }

  if (windowPosX < INT_MIN || windowPosY < INT_MIN) {
    return RAY_PLATE_INVALID_STATE;
  } 

  SetWindowPosition((int)windowPosX, (int)windowPosY);

  return RAY_PLATE_OK;
  
}
