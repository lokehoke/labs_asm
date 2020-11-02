.data
FIRST: .int 33
SECOND: .int 22
.global main
main:
/*Добавляем в стек*/
pushl SECOND
pushl FIRST 
call Watch  #Вызов функции
addl $8, %esp
xor %eax, %eax
ret
    
