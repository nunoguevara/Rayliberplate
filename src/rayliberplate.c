#include <stddef.h>
#include "raylib.h"
#include "rayliberplate.h"
#include <stdio.h>

/* This is the file for core implementations and functions for 
the library. If you want to change some things, you can change it here */

// Initializing relative window with percentage

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
  
  const int windowWidth = GetMonitorWidth(monitor);
  const int windowHeight = GetMonitorHeight(monitor);

  if ((int)windowWidth * (pct_covx / 100.0f) <= 0 || (int)windowHeight * (pct_covy / 100.0f) <= 0) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }
  
  SetWindowSize((int)windowWidth * (pct_covx / 100.0f), (int)windowHeight * (pct_covy / 100.0f));
  SetWindowPosition((int)windowWidth * (50 / 100.0f), (int)windowHeight * (50 / 100.0f));

  return RAY_PLATE_OK;
  
}

RayPlateStatus InitRelativeWindowDivisor(const char *title, double div_covx, double div_covy) {

  if (title == NULL) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (div_covx <= 1 || div_covy <= 1) {
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

  const int windowWidth = GetMonitorWidth(monitor);
  const int windowHeight = GetMonitorHeight(monitor);

  if (windowWidth / (double)div_covx <= 0 || windowHeight / (double)div_covy <= 0) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize(windowWidth / (double)div_covx, windowHeight / (double)div_covy);
  SetWindowPosition((int)windowWidth / 2, (int)windowHeight / 2);
  
  return RAY_PLATE_OK;
}
