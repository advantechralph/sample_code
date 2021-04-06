
// compile with: /W4 /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
  cout << s;

  for (const auto& e : c) {
    cout << e << " ";
  }

  cout << endl;
}

void fillVector(vector<int>& v)
{
  // A local static variable.
  static int nextValue = 1;

  // The lambda expression that appears in the following call to
  // the generate function modifies and uses the local static
  // variable nextValue.
  generate(v.begin(), v.end(), [] { return nextValue++; });
  //WARNING: this is not thread-safe and is shown for illustration only
}

ostream& operator<<(ostream &out, vector<int> &_v){
  for(vector<int>::iterator it=_v.begin();it!=_v.end();it++){
    cout << *it << " "; 
  }
  cout << endl; 
  return out;
}

int main(void){
  // The number of elements in the vector.
  const int elementCount = 9;

  // Create a vector object with each element set to 1.
  vector<int> v(elementCount, 1); 
  cout << "v: " << v << endl;
  for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    printf("%d ", *(int *)(&(*it)));
  }
  printf("\n");

  // These variables hold the previous two elements of the vector.
  int x = 1;
  int y = 1;

  // Sets each element in the vector to the sum of the
  // previous two elements.
  generate_n(v.begin() + 2,
    elementCount - 2,
    [=]() mutable throw() -> int { // lambda is the 3rd parameter
    // Generate current value.
    int n = x + y;
    // Update previous two values.
    x = y;
    y = n;
    return n;
  });
  print("vector v after call to generate_n() with lambda: ", v);

  // Print the local variables x and y.
  // The values of x and y hold their initial values because
  // they are captured by value.
  cout << "x: " << x << " y: " << y << endl;

  // Fill the vector with a sequence of numbers
  fillVector(v);
  print("vector v after 1st call to fillVector(): ", v);
  // Fill the vector with the next sequence of numbers
  fillVector(v);
  print("vector v after 2nd call to fillVector(): ", v);
  return 0;
}
