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

  const char *title, 
  int pct_covx, 
  int pct_covy
  
);
RayPlateStatus InitRelativeWindowDivisor(

  const char *title,
  double div_covx,
  double div_covy

);

#ifdef __cplusplus
}
#endif

#endif /*RAYLIBERPLATE_H*/
