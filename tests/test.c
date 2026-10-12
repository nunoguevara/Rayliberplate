#include <stdio.h>
#include "raylib.h"
#include "rayliberplate.h"

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
  
  status = InitRelativeWindowPercentage("Test", 101, 80);
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;
  
  status = InitRelativeWindowPercentage("Test", 80, 101);
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;
  
  status = InitRelativeWindowPercentage("Test", -1, 10);
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;
  
  status = InitRelativeWindowPercentage("Test", 10, -1);
  if(!ReportTestResult(&i, status == RAY_PLATE_INVALID_ARGUMENT)) return 1;

  status = InitRelativeWindowPercentage("Test", 80, 80);
  if(!ReportTestResult(&i, status == RAY_PLATE_OK)) return 1;
  CloseWindow();

  if (IsWindowReady()) {
    fprintf(
      stderr, 
      "\nCRITICAL ERROR: EDGE CASE HANDLING TEST FAILED SPECTULARLY AT TEST 6"
    );
    
    return -1;
  }
  
  printf("\nTest 6 clear");
  
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

  InitRelativeWindowDivisor("Test1", 1, 2);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  
  return 0;
  
}
