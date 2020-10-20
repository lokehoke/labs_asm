.data
a: .int 100
b: .int 21
c: .int 11
msg: .string "a = 100 b = 21 c=11 \n x= %d y= %d\n"
.global main
main:
pushl a
pushl b
pushl c
call operator
addl $3*4, %esp
push %eax
push %ecx
push $msg
call printf
addl $12, %esp
movl $0, %eax
xor %eax,%eax
ret
