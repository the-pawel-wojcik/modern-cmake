extern int a();
extern int b();
extern void duplicated();
int main() {
  int aout = a();
  int bout = b();
  duplicated();
}
