#include <stddef.h>

#ifndef RAYLIBERPLATE_H
#define RAYLIBERPLATE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum RayPlateStatus {

  RAY_PLATE_OK = 0,
  RAY_PLATE_INIT_FAILURE = -1,
  RAY_PLATE_INVALID_ARGUMENT = -2,
  RAY_PLATE_INVALID_STATE = -3
  
} RayPlateStatus;

RayPlateStatus InitRelativeWindowPercentage(

  const char *title, 
  int pct_covx, 
  int pct_covy
  
);

#ifdef __cplusplus
}
#endif

#endif /*RAYLIBERPLATE_H*/
