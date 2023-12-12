# Fundamental Instructions
### mov
```asm
mov rsi, 8
```
Move 8 into the rsi register.
```asm
mov rdi, QWORD PTR [rsi]
```
Move a quad-word amount of data from the location of the adress inside rsi. In other words treat rsi as a pointer, dereference it and grab 8 bytes (one quad-word) and move that into the rdi register. This is a load operation.
```asm
mov QWORD PTR [rdi], rdi
```
Take the value from rdi and pass it to the location of the address in rdi. This is a store operation.

# Performing a syscall
```asm
mov rax, <syscall number>
mov rdi, <arg 0>
mov rsi, <arg 1>
mov rdx, <arg 2>
mov r10, <arg 3>
mov r8, <arg 4>
mov r9, <arg 5>
```

## syscall numbers

| name | number | rdi | rsi | rdx |
| -    | -      | -   | -   | -   |
| write | 1 | int fd | const char* buffer | size_t count |
| exit | 60     | int error_code| 