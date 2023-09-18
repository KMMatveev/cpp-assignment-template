#include <hw01.h>
#include <math.h>

int hw01(int start, int end) {
  if (9 < start && start < 100 && start <= end && end < 100) {
    int sum = 0;
    for (int k = start; k < end + 1; k++) {
      int counter = 0;
      for (int i = 2; i < sqrt(k) + 1; i++) {
        if (k % i == 0)
          counter++;
      }
      if (counter == 0) {
        sum += k % 10 + k / 10;
      }
    }
    return sum;
  } else
    return -1;
}
