#include <stddef.h>
#include "raylib.h"
#include "rayliberplate.h"

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
  if (GetCurrentMonitor() < 0 || GetCurrentMonitor() >= GetMonitorCount()) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  }
  
  const int monitor = GetCurrentMonitor();
  const int windowWidth = GetMonitorWidth(monitor);
  const int windowHeight = GetMonitorHeight(monitor);

  if (windowWidth <= 0 || windowHeight <= 0) {
    CloseWindow();
    return RAY_PLATE_INVALID_STATE;
  } 
  
  SetWindowSize((int)windowWidth * (pct_covx / 100.0f), (int)windowHeight * (pct_covy / 100.0f));
  SetWindowPosition((int)windowWidth * (50 / 100.0f), (int)windowHeight * (50 / 100.0f));

  return RAY_PLATE_OK;
  
}


