#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <time.h>
#include <conio.h>
#define PROJECT_NAME    "Washing Machine System"

/* Prototypes for all the test functions */
void test_stateOnOff(void);
void test_mainmenu(void);
void test_Washclothes(void);
void test_WashMenu(void);
void test_soak(void);
void test_Temperature(void);
void test_viewlog(void);


/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */
  
  
  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "stateOnOff", test_stateOnOff);
  CU_add_test(suite, "mainmenu", test_mainmenu);
  CU_add_test(suite, "Washclothes", test_Washclothes);
  CU_add_test(suite, "WashMenu", test_WashMenu);
 CU_add_test(suite, "soak", test_soak);
CU_add_test(suite, "Temperature", test_Temperature);
CU_add_test(suite, "viewlog", test_viewlog);




/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  /* run the unit test framework*/
  CU_basic_run_tests();
  
  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */ 
void test_stateOnOff(void) {
  CU_ASSERT(o == stateOnOff(o));
  
  /* Dummy fail*/
  CU_ASSERT(o != stateOnOff(o));
}

void test_mainmenu(void) {
  CU_ASSERT(w|v == mainmenu(w, v));
  
  /* Dummy fail*/
  CU_ASSERT(w|v != mainmenu(w, v));
}

void test_Washclothes(void) {
  CU_ASSERT(s|m|l|x|f == Washclothes(s, m, l, x, f));
  
  /* Dummy fail*/
  CU_ASSERT(s|m|l|x|f != Washclothes(s, m, l, x, f));
}

void test_WashMenu(void) {
  CU_ASSERT(f|w|r|s == WashMenu(f, w, r, s));
  
  /* Dummy fail*/
  CU_ASSERT(f|w|r|s != WashMenu(f, w, r, s));
}

void test_soak(void) {
  CU_ASSERT(y == soak(y));
  
  /* Dummy fail*/
  CU_ASSERT(y != soak(y));
}

void test_Temperature(void) {
  CU_ASSERT(h|c == Temperature(h, c));
  
  /* Dummy fail*/
  CU_ASSERT(h|c != Temperature(h, c));
}

void test_viewlog(void) {
  CU_ASSERT(v == viewlog(v));
  
  /* Dummy fail*/
  CU_ASSERT(v != viewlog(v));
}

