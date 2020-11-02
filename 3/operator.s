.global operator
operator:
mov 4(%esp), %edx
mov 8(%esp), %ecx
mov 12(%esp), %eax
imul %edx,%ecx
mov %eax,%edx
add %ecx,%eax
sub %ecx,%edx
mov %edx,%ecx
xor %edx,%edx
ret
