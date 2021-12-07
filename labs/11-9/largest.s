	# MIPS version of finding the largest
	# element, and printing it.
	.data
x:	.word 3
	.word 37
	.word 2
	.word 7
	.word 41
	.word 0
prompt:	.asciiz "The largest number is "

	.text
main:	la $s0, x
	li $s1, 0

while:	lw $s2, 0($s0)
	beq $s2, $0, done

	ble $s2, $s1, skip
	move $s1, $s2

skip:
	# Move the pointer
	addi $s0, $s0, 4

	j while

done:
	# SPIM can print ASCII strings...
	li $v0, 4
	la $a0, prompt
	syscall

	# SPIM has code to print numbers as
	# part of the operating system.  
	li $v0, 1
	move $a0, $s1
	syscall

	# This system call stops the machine
	li $v0, 10
	syscall
	
	
