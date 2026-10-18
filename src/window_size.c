#include <stddef.h>
#include <math.h>
#include <limits.h>
#include "raylib.h"
#include "rayliberplate.h"

RayPlateStatus SetWindowSizePercentage(double pct_covx, double pct_covy) {

  if (!IsWindowReady()) {
    return RAY_PLATE_INVALID_STATE;
  }

  if (!isfinite(pct_covx) || !isfinite(pct_covy)) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  if (pct_covx <= 0 || pct_covy <= 0) {
    return RAY_PLATE_INVALID_ARGUMENT;
  }

  const int monitor = GetCurrentMonitor();

  if (monitor < 0 || monitor >= GetMonitorCount()) {
    return RAY_PLATE_INVALID_STATE;
  }
  
  const int monitorWidth = GetMonitorWidth(monitor);
  const int monitorHeight = GetMonitorHeight(monitor);
  const double windowWidth = monitorWidth * (pct_covx / 100.0);
  const double windowHeight = monitorHeight * (pct_covy / 100.0);

  if (!isfinite(windowWidth) || !isfinite(windowHeight)) {
    return RAY_PLATE_INVALID_STATE;
  }
  
  if (windowWidth > INT_MAX || windowHeight > INT_MAX) {
    return RAY_PLATE_INVALID_STATE;
  } 
  
  if (windowWidth < 1 || windowHeight < 1) {
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize((int)windowWidth, (int)windowHeight);

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
  const double windowWidth = monitorWidth / div_covx;
  const double windowHeight = monitorHeight / div_covy;

  if (!isfinite(windowWidth) || !isfinite(windowHeight)) {
    return RAY_PLATE_INVALID_STATE;
  }
  
  if (windowWidth > INT_MAX || windowHeight > INT_MAX) {
    return RAY_PLATE_INVALID_STATE;
  } 

  if (windowWidth < 1 || windowWidth < 1) {
    return RAY_PLATE_INVALID_STATE;
  }

  SetWindowSize((int)windowWidth, (int)windowHeight);
  
  return RAY_PLATE_OK;
  
}
