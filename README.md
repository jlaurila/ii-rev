# Introduction to revese engineering

- Static analysis with strings, Ghidra, gdb and Cutter
- Dynamic analysis with ltrace, strace and gdb
- Patching with Cutter and gdb 
- Bypassing anti-debugging techniques
- LD_PRELOAD


# 0 - trivial example
- strings

# 1 - license check with mod 7
- ghidra with and without symbols (gcc -s)
- demonstrate how you can rename functions and variables (L key)
- demonstrate how you can add comments
- use: gcc -o2 -s 

# out - packed executable
- file
- binwalk out
- upx -d out -ohepsuli
- chmod +x hepsuli
- Ghidra
- note that there is no way to enter the correct password and show that with the gdb commands below
```
disas main
break * main+477
run
x/s $rdi
x/s $rsi
7069636f4354467b5539585f556e5034636b314e365f42316e34526933535f62646438343839337d
```


# 3 - obfuscated with XOR
- ltrace
- bypass with LD_PRELOAD
  - show the library code first
```
LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
LD_PRELOAD=./mylibrary.so ./3 foo
```

# 4 - system call - the password is not on local machine
- strace
- bypass with patching with Cutter
- `echo -n "mysecretpassword" | nc -l -p 8080\`

# key_check - anti debug
- ltrace doesn't work due to anti debug
- `set disassembly-flavor intel`
- bypass with gdb `disas main` -> break anti_debug -> **`return`**
```
disas main
break * anti_debug
break * main+148
return
continue
# observer stcmp arguments
``` 
## method 2
```
gdb --write -q ./key_check
disas main
# note that the call function length is 5 bytes
# nop the call
set {unsigned char} 0x00000000004011e2  = 0x90
set {unsigned char} 0x00000000004011e3  = 0x90
set {unsigned char} 0x00000000004011e4  = 0x90
set {unsigned char} 0x00000000004011e5  = 0x90
set {unsigned char} 0x00000000004011e6  = 0x90
quit
# run with ltrace

```

