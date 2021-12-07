    # Ryan Ma
	# MIPS version of adding the sum of values
    # in an array >5 and <40
	.data
x:	.word 3
	.word 37
	.word 2
	.word 7
	.word 41
	.word 0
prompt:	.asciiz "The largest number is "

	.text
main:	
	la $s0, x
	li $s1, 0
	li $s3, 0 #sum
	li $s4, 5
	li $s5, 40

while:	
	lw $s2, 0($s0)
	beq $s2, $0, done

	ble $s2, $s4, skip
	bge $s2, $s5, skip
	# ble $s2, $s1, skip
	add $s3, $s3, $s2

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
	
	
