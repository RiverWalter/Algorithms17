#include <utility>
using namespace std;
void BubbleSort(int a[], int n)
{
   for (int i = n; i >= 2; i--) {
      bool hasSwap = false;
      for (int j = 0; j < i - 1; j++) {
         if (a[j]> a [j + 1]) {
            swap(a[j], a[j + 1]);
			hasSwap = true;
         }
      }
      if (!hasSwap) break;
   }
}