#include <stddef.h>
#include <math.h>
#include <limits.h>
#include "raylib.h"
#include "rayliberplate.h"

// Initializing relative window using percentage

RayPlateStatus InitRelativeWindowPercentage(const char *title, double pct_covx, double pct_covy) {
  
  if (title == NULL) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (!isfinite(pct_covx) || !isfinite(pct_covy)) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (pct_covx <= 0 || pct_covy <= 0) {
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
  const double windowWidth = monitorWidth * (pct_covx / 100.0); 
  const double windowHeight = monitorHeight * (pct_covy / 100.0);

  if (!isfinite(windowWidth) || !isfinite(windowHeight)) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  } 
  
  if (windowWidth > INT_MAX || windowHeight > INT_MAX) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }
  
  if (windowWidth < 1 || windowHeight < 1) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize((int)windowWidth, (int)windowHeight);

  return RAY_PLATE_OK;
  
}

// Initializing relative window using a divisor

RayPlateStatus InitRelativeWindowDivisor(const char *title, double div_covx, double div_covy) {

  if (title == NULL) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (!isfinite(div_covx) || !isfinite(div_covy)) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (div_covx <= 0 || div_covy <= 0) {
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
  const double windowWidth = monitorWidth / div_covx;
  const double windowHeight = monitorHeight / div_covy;

  if (!isfinite(windowWidth) || !isfinite(windowHeight)) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  } 
  
  if (windowWidth > INT_MAX || windowHeight > INT_MAX) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }
  
  if (windowWidth < 1 || windowHeight < 1) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize((int)windowWidth, (int)windowHeight);
  
  return RAY_PLATE_OK;
  
}

