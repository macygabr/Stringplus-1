#include "test_s21_string.h"

int main(void) {
  int all_tests_failed = 0;
  Suite *test_s21_string[] = {
      test_first_func(),
      NULL};

 for (int i = 0; test_s21_string[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(test_s21_string[i]);

    srunner_run_all(sr, CK_NORMAL);
    int failed = srunner_ntests_failed(sr);
    all_tests_failed += failed;
    printf("-----------------------------------------\n");
    srunner_free(sr);
  }

  if (all_tests_failed)
    printf("======= NUMBER OF FAILED TESTS: %d =======\n", all_tests_failed);
  else
    printf("======= SUCCESS =======\n");

  return all_tests_failed;
}