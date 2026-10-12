#include <stddef.h>
#include "raylib.h"
#include "rayliberplate.h"

/* This is the file for core implementations and functions for 
the library. If you want to change some things, you can change it here */

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

// Initializing relative window using percentage

RayPlateStatus InitRelativeWindowPercentage(const char *title, int pct_covx, int pct_covy) {
  
  if (title == NULL) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }
  
  if (pct_covx <= 0 || pct_covy <= 0 || pct_covx > 100 || pct_covy > 100) {
    return RAY_PLATE_INVALID_ARGUMENT;
  } 

  if (IsWindowReady()) {
    return RAY_PLATE_INIT_FAILURE;
  }
  
  InitWindow(1, 1, title);
  
  if (!IsWindowReady()) {
    return RAY_PLATE_INIT_FAILURE;
  }

  // WARNING: Even if it's failed to get the current monitor, it still requires CloseWindow()
  // Otherwise, it could generate additional issues
  
  const int monitor = GetCurrentMonitor();

  if (monitor < 0 || monitor >= GetMonitorCount()) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }
  
  const int monitorWidth = GetMonitorWidth(monitor);
  const int monitorHeight = GetMonitorHeight(monitor);
  const int windowWidth = monitorWidth * (pct_covx / 100.0f); 
  const int windowHeight = monitorHeight * (pct_covy / 100.0f);

  if (windowWidth <= 0 || windowHeight <= 0) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }
  
  SetWindowSize(windowWidth, windowHeight);

  return RAY_PLATE_OK;
  
}

// Initializing relative window using a divisor

RayPlateStatus InitRelativeWindowDivisor(const char *title, double div_covx, double div_covy) {

  if (title == NULL) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (div_covx < 1 || div_covy < 1) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (IsWindowReady()) {
    return RAY_PLATE_INIT_FAILURE;
  }

  InitWindow(1, 1, title);

  if (!IsWindowReady()) {
    return RAY_PLATE_INIT_FAILURE;
  }

  const int monitor = GetCurrentMonitor();

  if (monitor < 0 || monitor >= GetMonitorCount()) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  } 

  const int monitorWidth = GetMonitorWidth(monitor);
  const int monitorHeight = GetMonitorHeight(monitor);
  const int windowWidth = monitorWidth / div_covx;
  const int windowHeight = monitorHeight / div_covy;
  
  if (windowWidth <= 0 || windowHeight <= 0) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize(windowWidth, windowHeight);
  
  return RAY_PLATE_OK;
}
