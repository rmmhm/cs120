        #hello world for MIPS - Ryan Ma
        .data
hello:  .asciiz "Hello world!\n"

        .text

main:   li $v0, 4
        la $a0, hello
        syscall

        li $v0, 10
        syscall