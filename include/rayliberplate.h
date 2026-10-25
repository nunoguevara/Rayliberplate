#include <stddef.h>

#ifndef RAYLIBERPLATE_H
#define RAYLIBERPLATE_H

/* This is the header file for Rayliberplate, core features
of the library are declared here to make it cleaner and CLEAR */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum RayPlateStatus {
  RAY_PLATE_OK = 0,
  RAY_PLATE_INIT_FAILURE = -1,
  RAY_PLATE_INVALID_ARGUMENT = -2,
  RAY_PLATE_INVALID_STATE = -3
} RayPlateStatus;

RayPlateStatus SetWindowPosCenter();
RayPlateStatus InitRelativeWindowPercentage(
  double pct_covx, 
  double pct_covy,
  const char *title
);
RayPlateStatus InitRelativeWindowDivisor(
  double div_covx,
  double div_covy,
  const char *title
);
RayPlateStatus SetWindowSizePercentage(
  double pct_covx,
  double pct_covy
); 
RayPlateStatus SetWindowSizeDivisor(
  double div_covx,
  double div_covy
);

#ifdef __cplusplus
}
#endif

#endif /*RAYLIBERPLATE_H*/
