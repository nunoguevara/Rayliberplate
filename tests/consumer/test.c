#include <stdio.h>
#include "raylib.h"
#include <math.h>
#include "rayliberplate.h"
#include <float.h>

/* This is rayliberplate diagnostic test to test
new features and stuff, it could be ignored if you only
use the library rather than modifying it */
int ReportTestResult(int *test, int status) {

  if (status) {
    printf("\nTest %d clear", *test);
    (*test)++;
    return 1;
  }

  fprintf(stderr, "\nTest %d failed", *test);
  return 0;

}

int EdgeCaseHandlingTest() {
  
  printf("STARTING EDGE CASE HANDLING TESTS...");  

  RayPlateStatus status;
  int i = 1;

  // 1
  status = InitRelativeWindowPercentage(NAN, 80, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  // 2
  status = InitRelativeWindowPercentage(80, NAN, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  // 3
  status = InitRelativeWindowPercentage(INFINITY, 90, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  // 4
  status = InitRelativeWindowPercentage(10, -1, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  // 5
  status = InitRelativeWindowPercentage(10, DBL_MAX, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_STATE)) return 1;

  status = InitRelativeWindowPercentage(10, 10, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_OK)) return 1;
  
  CloseWindow();

  if (IsWindowReady()) {
    fprintf(
      stderr, 
      "\nCRITICAL ERROR: EDGE CASE HANDLING TEST FAILED SPECTULARLY AT TEST 6"
    );
    
    return -1;
  }

  printf("\nTest %d clear", i);
  i++;

  status = InitRelativeWindowDivisor(0, 0, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  status = InitRelativeWindowDivisor(-1, -1, "Test");
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  status = InitRelativeWindowDivisor(2, 1, NULL);
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;
  
  printf("\nEDGE CASE HANDLING TEST RAN SUCCESSFULY");
  
  return 0;
  
}

int main(void) {

  // For now, the diagnostic test is still small
  
  if (EdgeCaseHandlingTest() != 0) {
    printf("\nERROR: EDGE CASE HANDLING TEST FAILED");
    return -2;
  }

  printf("\nOVERALL TESTS RAN SUCCESSFULY\n");

  InitRelativeWindowDivisor(1, 2, "Test1");
  SetWindowPosCenter();

  int testTime = 100;
  
  while (!WindowShouldClose() && testTime > 0) {
    testTime--;
    BeginDrawing();
      ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  
  return 0;
  
}
