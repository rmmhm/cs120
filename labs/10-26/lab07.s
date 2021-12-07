        #lab07
        #Ryan Ma

        .data

name:   .asciiz "Ryan Ma\n"
        .text

main:   li $v0, 4
        la $a0, name
        syscall

        li $v0, 0
        li $a0, 0

        li $a1, 18
        li $a2, 27
        li $a3, -11
        add $a0, $a1, $a2
        add $a0, $a0, $a3

        li $v0, 1
        syscall

        li $v0, 10
        syscall