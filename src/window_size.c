#include <stddef.h>
#include <math.h>
#include "raylib.h"
#include "rayliberplate.h"

RayPlateStatus SetWindowSizePercentage(double pct_covx, double pct_covy) {

  if (!IsWindowReady()) {
    return RAY_PLATE_INVALID_STATE;
  }

  if (pct_covx <= 0 || pct_covy <= 0) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (pct_covx > 100 || pct_covy > 100) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (!isfinite(pct_covx) || !isfinite(pct_covy)) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

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
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize(windowWidth, windowHeight);

  return RAY_PLATE_OK;
}

RayPlateStatus SetWindowSizeDivisor(double div_covx, double div_covy) {

  if (!IsWindowReady()) {
    return RAY_PLATE_INVALID_STATE;
  }

  if (div_covx < 1 || div_covy < 1) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (!isfinite(div_covx) || !isfinite(div_covy)) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  const int monitor = GetCurrentMonitor();

  if (monitor < 0 || monitor >= GetMonitorCount()) {
    return RAY_PLATE_INVALID_STATE;
  }

  const int monitorWidth = GetMonitorWidth(monitor);
  const int monitorHeight = GetMonitorHeight(monitor);
  const int screenWidth = monitorWidth / div_covx;
  const int screenHeight = monitorHeight / div_covy;

  if (screenWidth <= 0 || screenWidth <= 0) {
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize(screenWidth, screenHeight);
  
  return RAY_PLATE_OK;
  
}
