# prcpp-my-string
String Class in C++. Exercise from FHNW.

##
Unfortunately I could not use the following code, because I am working with the libc++ compiler.
```
m_string = shared_ptr<char>(unique_ptr<char[]>(new char[gewenschteLaenge]));
```

## How to compile with the terminal
### Run your code
```
g++ ./src/main.cpp -o run.out
./run.out 
```

### Hint
If your app has a main method you need to comment it out, because otherwise you habe a conflict.
