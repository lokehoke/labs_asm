.data
N: .int 1
an1: .int 1
an0: .int 1
N1: .int 1
input:
.string "%d"
msg:
.string "Enter N "
output:
.string "fi(%d)=%d\n"
error:
.string "error\n"
.global main 
main:
    subl $20, %esp
    movl $msg, (%esp)
    call printf
    leal 16(%esp), %eax
    movl %eax, 4(%esp)
    movl $input, (%esp)
    call scanf
    movl 16(%esp), %eax
    movl %eax, N
    addl $20, %esp
    
    cmpl $0,N
    jnge less_then_zero
    jmp zeroo
    next:
    
    start:
        cmpl $0, N
        je exit
        
        movl an1,%ecx
        movl an1,%eax
        movl an0,%edx
        addl %eax,%edx
        movl %edx,an1
        movl %ecx,an0
        pushl an1
        pushl N1
        pushl $output
        call printf
        addl $12, %esp

        addl $-1, N
        addl $1,  N1
        jmp start
        ret
    
    less_then_zero:
        pushl $error
        call printf
        addl $4, %esp
        jmp exit
        
    zeroo:
        pushl $1
        pushl $0
        pushl $output
        call printf
        addl $12, %esp
        jmp next
        
    exit:
        ret
