typedef int(*InFunction)(double);

typedef int*(*OutFunction)(char const *);

typedef OutFunction(*ComplexFunction)(int, InFunction);