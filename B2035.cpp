//B2035 write by cn_ryh
#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a > 0) {
    cout << "positive" << endl;
  } else if (a == 0) {
    cout << "zero" << endl;
  } else {
    cout << "negative" << endl;
  }
  return 0;
}