void print(char *s) {
  if (*s != 0) {
    putchar(*s);
    print(s+1);
  }
}

void printreverse(char *s) {
  if (*s != 0) {
    printreverse(s+1);
    putchar(*s);
  }
}

int main() {
  char *s = "Hello world";
  print(s);
  putchar('\n');
  printreverse(s);
  putchar('\n');
}
