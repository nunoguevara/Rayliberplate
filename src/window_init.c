#include <stddef.h>
#include <math.h>
#include "raylib.h"
#include "rayliberplate.h"

// Initializing relative window using percentage

RayPlateStatus InitRelativeWindowPercentage(const char *title, double pct_covx, double pct_covy) {
  
  if (title == NULL) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }
  
  if (pct_covx < 1 || pct_covy < 1 || pct_covx > 100 || pct_covy > 100) {
    return RAY_PLATE_INVALID_ARGUMENT;
  } 

  if (!isfinite(pct_covx) || !isfinite(pct_covy)) {
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
  const int windowWidth = monitorWidth * (pct_covx / 100.0); 
  const int windowHeight = monitorHeight * (pct_covy / 100.0);

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

  if (!isfinite(div_covx) || !isfinite(div_covy)) {
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
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize(windowWidth, windowHeight);
  
  return RAY_PLATE_OK;
  
}

