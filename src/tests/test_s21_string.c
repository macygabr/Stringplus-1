#include "test_s21_string.h"

int main() {
   int error = 0;
    Suite *test_arr[] = {test_s21_sprintf(), test_s21_sprintf() ,  NULL};

  for (int i = 0; test_arr[i] != NULL; i++) {
    SRunner *runner = srunner_create(test_arr[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    int failed = srunner_ntests_failed(runner);
    error += failed;
    printf("-----------------------------------------\n");
    srunner_free(runner);
  }

  if (error)
    printf("======= NUMBER OF FAILED TESTS: %d =======\n", error);
  else
    printf("======= SUCCESS =======\n");

  return error == 0 ? 0 : 1;
}
