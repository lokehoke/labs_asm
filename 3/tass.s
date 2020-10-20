.global tass
tass:
    mov 4(%esp), %eax
    shr $1, %eax
    add $1, %eax
ret

