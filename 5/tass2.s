.globl tass
    tass:
        fldl 4(%esp)
        fldl 4(%esp)
        fmulp
        fldl 4(%esp)
        fldl 12(%esp)
        faddp
        fdivp
