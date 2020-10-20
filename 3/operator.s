.global operator
operator:
mov 4(%esp), %ebx
mov 8(%esp), %ecx
mov 12(%esp), %eax
imul %ebx,%ecx
mov %ecx,%ebx
add %eax,%ecx
sub %ebx,%eax
ret
