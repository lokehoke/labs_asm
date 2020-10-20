.data
FIRST: .int 33
SECOND: .int 22
.global main
main:
/*Добавляем в стек*/
pushl FIRST 
pushl SECOND
call Watch  #Вызов функции
popl %eax # Вычищаем параметр из стека
popl %ebx # Вычищаем параметр из стека
xor %eax, %eax
ret
    
