#include <stddef.h>
#include <math.h>
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

  if (windowWidth > monitorWidth || windowHeight > monitorHeight) {
    return RAY_PLATE_INVALID_STATE;
  }

  const int windowPosX = monitorPos.x + (monitorWidth - windowWidth) / 2;
  const int windowPosY = monitorPos.y + (monitorHeight - windowHeight) / 2;

  SetWindowPosition(windowPosX, windowPosY);

  return RAY_PLATE_OK;
  
}
